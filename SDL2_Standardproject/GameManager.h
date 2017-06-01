/*
 * @file: GameManager.h
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SDL/SDLManager.h"
#include "SDL/SDLBmp.h"
#include "InputManager.h"
#include "Timer.h"
#include "GameObject.h"
#include "Snake.h"

class GameManager
{
public:
	/* Meyer's singleton style instance call */
	static GameManager& Instance()
	{
		static GameManager g;
		return g;
	}

	/* Kicks off/is the the gameloop */
	void play();
private:
	GameManager();								// Hidden constructor
	GameManager(const GameManager&);			// Hidden copy constructor
	GameManager& operator=(const GameManager&); // Hidden assign operator
	void RunGameLoop (Snake snake, SDLBmp background, GameObject apple, float render_fps, float speed, int direction, int score, int speedIncreaseRate);
	void CheckInput (int* direction);
	void BorderCollideCheck(GameObject* player, SDLBmp* backround);
	void AutoCannibalismCheck (Snake* player);
	Point2D randomPlacement(GameObject* image, int boardWidth, int boardHeight);
	static bool CrashedWithObjectCheck (GameObject* player, GameObject* object);

	bool isSlithering = true;
	unsigned int m_window; // pointer to main window
	float m_lastRender; // Time in seconds since last render

};

#endif