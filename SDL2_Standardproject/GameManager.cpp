/*
 * @file: GameManager.cpp
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#include "GameManager.h"
#include <iostream>

using namespace std;

/* Initializes SDL, creates the game window and fires off the timer. */
GameManager::GameManager()
{
	SDLManager::Instance().init();
	m_window = SDLManager::Instance().createWindow("My Awesome SDL 2.0 Game");
	Timer::Instance().init();
}

/* Kicks off/is the the gameloop */
void GameManager::play()
{
	int startingLength = 3;
	float speed = 150.0f;
	int speedIncreaseRate = 10;
	int direction = RIGHT;
	int score = 0;
	
	srand (time (nullptr));

	// Load bitmaps
	SDLBmp backround("Assets/gfx/sdl2.bmp");
	SDLBmp playerHeadImage("Assets/gfx/SnakeHead_v1.bmp");
	SDLBmp playerBodyImage("Assets/gfx/SnakeBody_v1.bmp");
	SDLBmp appleImage ("Assets/gfx/apple_v1.bmp");

	Point2D playerStartingPosition ((backround.getWidth () / 2 - playerHeadImage.getWidth () / 2), (backround.getHeight () / 2 - playerHeadImage.getHeight () / 2));
	Point2D applePosition;

	GameObject playerHead (playerStartingPosition, &playerHeadImage, UP);
	GameObject playerBody (playerStartingPosition, &playerBodyImage, UP);
	GameObject apple (applePosition, &appleImage, UP);

	applePosition = randomPlacement (&apple, backround.getWidth (), backround.getHeight ());
	apple.setPosition (applePosition);

	Snake snake (&playerHead, &playerBody, startingLength);



	// Calculate render frames per second (second / frames) (60)
	float render_fps = 1.f / 60.f;
	m_lastRender = render_fps; // set it to render immediately

// Gameloop
	while (isSlithering)
	{

 //Input
		// Update input and deltatime
		InputManager::Instance().Update();
		Timer::Instance().update();

		// Calculate displacement based on deltatime
		auto displacement = speed * Timer::Instance().deltaTime();
		
		/* Input Management */
		CheckInput (&direction);

 //Logic
		
		snake.updatePosition(direction, displacement);
		
		//Check if we died
		GameObject head (*(snake.getHead ()));
		BorderCollideCheck (&head, &backround);
//		AutoCannibalismCheck (&snake);

		//Check if we found object
		if (CrashedWithObjectCheck(&head, &apple))
		{
			score++;
			speed += speedIncreaseRate;
			cout << "Score: " << score << endl;
			//Grow body size
			snake.increaseLength ();
			apple.setPosition(randomPlacement (&apple, backround.getWidth (), backround.getHeight ()));
		}

		//push earlier turn to turn queue
		if (m_lastRender >= render_fps)
		{
			snake.pushPreviousTurnPosition(snake.getHead()->getPosition());
		}

 //Render
		// Update time since last render
		m_lastRender += Timer::Instance().deltaTime();

		// Check if it's time to render
		if (m_lastRender >= render_fps)
		{
			// Add bitmaps to renderer
			backround.draw();
			snake.drawSnake ();
			apple.getImage ()->draw ();
			// Render window
			SDLManager::Instance().renderWindow(m_window);
			m_lastRender = 0.f;
		}
		
		// Sleep to prevent CPU exthaustion (1ms == 1000 frames per second)
		SDL_Delay(1);
	}
}

//Checks input and sets direction
void GameManager::CheckInput(int* direction)
{

	// Left key
	if ((InputManager::Instance ().KeyDown (SDL_SCANCODE_LEFT) ||
		 InputManager::Instance ().KeyStillDown (SDL_SCANCODE_LEFT)) && *direction != 1) {
		*direction = 0;
	}

	// Right key
	if ((InputManager::Instance ().KeyDown (SDL_SCANCODE_RIGHT) ||
		 InputManager::Instance ().KeyStillDown (SDL_SCANCODE_RIGHT)) && *direction != 0) {
		*direction = 1;
	}

	// Key up
	if ((InputManager::Instance ().KeyDown (SDL_SCANCODE_UP) ||
		 InputManager::Instance ().KeyStillDown (SDL_SCANCODE_UP)) && *direction != 3) {
		*direction = 2;
	}

	// Key down
	if ((InputManager::Instance ().KeyDown (SDL_SCANCODE_DOWN) ||
		 InputManager::Instance ().KeyStillDown (SDL_SCANCODE_DOWN)) && *direction != 2) {
		*direction = 3;
	}

	// Exit on [Esc], or window close (user X-ed out the window)
	if (InputManager::Instance ().hasExit () || InputManager::Instance ().KeyDown (SDL_SCANCODE_ESCAPE)) {
		isSlithering = false;
	}


}

//Checks if player crashes with window borders
void GameManager::BorderCollideCheck(GameObject* player, SDLBmp* backround)
{
	// Check if crash with borders
	if (   player->getPosition().getX() < 0
		|| player->getPosition().getY() < 0
		|| player->getPosition().getX() >= backround->getWidth () - player->getImage()->getWidth () 
		|| player->getPosition().getY() >= backround->getHeight () - player->getImage()->getHeight ())
		isSlithering = false;
}

//Checks is player crashes with self
void GameManager::AutoCannibalismCheck(Snake* player)
{
	//Add check for autocannibalism when snake has more body parts
	//head can crash with closest 2 or 3 body parts without ending game to minimize unintended crashes?



	for (auto i = 1; i <= player->getLength() -3; i++)
	{
		if (CrashedWithObjectCheck (player->getHead (), player->getBodyPartAt (i)))
			isSlithering = false;
	}

}

//Checks if player crashes with object
bool GameManager::CrashedWithObjectCheck (GameObject* player, GameObject* object)
{
	//Make 4 points from corners of object
	//Make square from player head represented as if statement
	//Check if points are inside square

	// Checks the upper left corner of object
	if (player->getPosition ().isInsideSquare (object->getPosition ().getX (),
											   object->getPosition ().getY (),
											   object->getImage ()->getWidth (),
											   object->getImage ()->getHeight ()))
		return true;

	// Checks the upper right corner of object
	if (Point2D (player->getPosition ().getX () + player->getImage ()->getWidth (),
				 player->getPosition ().getY ()
				 ).isInsideSquare (object->getPosition ().getX (),
								   object->getPosition ().getY (),
								   object->getImage ()->getWidth (),
								   object->getImage ()->getHeight ()))
		return true;

	// Checks the lower left corner of object
	if (Point2D (player->getPosition ().getX (),
				 player->getPosition ().getY () + player->getImage ()->getHeight ()
				 ).isInsideSquare (object->getPosition ().getX (),
								   object->getPosition ().getY (),
								   object->getImage ()->getWidth (),
								   object->getImage ()->getHeight ()))
		return true;

	// Checks the lower right corner of object
	if (Point2D (player->getPosition ().getX () + player->getImage ()->getWidth (),
				 player->getPosition ().getY () + player->getImage ()->getHeight ()
				 ).isInsideSquare (object->getPosition ().getX (),
								   object->getPosition ().getY (),
								   object->getImage ()->getWidth (),
								   object->getImage ()->getHeight ()))
		return true;

	return false;
}

//Sets image position to random position between 0 and board width/height
Point2D GameManager::randomPlacement(GameObject* image, int boardWidth, int boardHeight)
{
	return Point2D (static_cast<float>(rand() % (boardWidth - image->getImage()->getWidth ())), 
					static_cast<float>(rand() % (boardHeight - image->getImage()->getHeight())));
}

