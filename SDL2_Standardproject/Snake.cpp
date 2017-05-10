#include "Snake.h"
#include <iostream>


Snake::Snake(GameObject* headPart, GameObject* bodyPart, int startingLength)
{
	length = 3;
	headObject = headPart;
	bodyObject = bodyPart;

	this->push_front (GameObject(*headObject));
	this->push_back (GameObject (*bodyObject));
	this->push_back (GameObject (*bodyObject));
	this->push_back (GameObject (*bodyObject));

	getBodyPartAt (0)->setPosition (Point2D (getHead ()->getPosition ().getX () - bodyPart->getImage ()->getWidth (), 
											 getHead()->getPosition().getY()));
	getBodyPartAt (1)->setPosition (Point2D (getBodyPartAt(0)->getPosition ().getX () - bodyPart->getImage ()->getWidth (), 
											 getHead()->getPosition().getY()));
	getBodyPartAt (2)->setPosition (Point2D (getBodyPartAt(1)->getPosition ().getX () - bodyPart->getImage ()->getWidth (), 
											 getHead()->getPosition().getY()));

	getBodyPartAt (0)->setRotation (getHead()->getRotation());
	getBodyPartAt (1)->setRotation (getHead()->getRotation());
	getBodyPartAt (2)->setRotation (getHead()->getRotation());
	
	earlierTurns.push (Point2D(getBodyPartAt (0)->getPosition ().getX() - bodyPart->getImage()->getWidth(), getBodyPartAt (0)->getPosition ().getY()));
	earlierTurns.push (Point2D(getBodyPartAt (1)->getPosition ()));
	earlierTurns.push (Point2D(getBodyPartAt (2)->getPosition ()));

}

void Snake::increaseLength()
{
	length++;
	this->push_back (GameObject (*bodyObject));
}

int Snake::getLength()
{
	return length;
}

GameObject* Snake::getHead()
{
	return &this->front ();
}

//pos -1 returns the head object.  
GameObject* Snake::getBodyPartAt (int pos)
{
	auto snake_part = this->begin ();
	std::advance (snake_part, pos + 1); //+1 to skip head
	return &*snake_part;
}

void Snake::updatePosition (int direction, float displacement)
{
//	auto newHead = *getHead ();
//
//	auto lastMove = newHead.getPosition ();


// sets new position and rotation for head based on direction
	switch (direction) {
		case 0:
			//left
			getHead ()->setPosition (Point2D (getHead ()->getPosition ().getX () - displacement,
											  getHead ()->getPosition ().getY ()));
			getHead ()->setRotation (LEFT);
			getHead ()->setTurnX (getHead ()->getPosition ().getX ());
			break;
		case 1:
			//right
			getHead ()->setPosition (Point2D (getHead ()->getPosition ().getX () + displacement,
											  getHead ()->getPosition ().getY ()));
			getHead ()->setRotation (RIGHT);
			getHead ()->setTurnX (getHead ()->getPosition ().getX ());
			break;
		case 2:
			//up
			getHead ()->setPosition (Point2D (getHead ()->getPosition ().getX (),
											  getHead ()->getPosition ().getY () - displacement));
			getHead ()->setRotation (UP);
			getHead ()->setTurnY (getHead ()->getPosition ().getY ());
			break;
		case 3:
			//down
			getHead ()->setPosition (Point2D (getHead ()->getPosition ().getX (),
											  getHead ()->getPosition ().getY () + displacement));
			getHead ()->setRotation (DOWN);
			getHead ()->setTurnY (getHead ()->getPosition ().getY ());
			break;
		default: break;
	}

	//Sets new position and rotation for rest of body
	for (auto i = 0; i <= length-1; i++) {
		switch (getBodyPartAt (i)->getRotation ()) {
			case 0:
				//left
				getBodyPartAt (i)->setPosition (Point2D (getBodyPartAt (i)->getPosition ().getX () - displacement,
														 getBodyPartAt (i)->getPosition ().getY ()));

				if (getBodyPartAt (i)->getPosition ().getX () < getBodyPartAt (i - 1)->getTurnX ()) {
					getBodyPartAt (i)->setRotation (getBodyPartAt (i - 1)->getRotation ());
					getBodyPartAt (i)->setTurnX (getBodyPartAt (i - 1)->getPosition ().getX ());
					getBodyPartAt (i)->getPosition ().setX (getBodyPartAt (i - 1)->getPosition ().getX ());
				}
				break;
			case 1:
				//right
				getBodyPartAt (i)->setPosition (Point2D (getBodyPartAt (i)->getPosition ().getX () + displacement,
														 getBodyPartAt (i)->getPosition ().getY ()));

				if (getBodyPartAt (i)->getPosition ().getX () > getBodyPartAt (i - 1)->getTurnX ()) {
					getBodyPartAt (i)->setRotation (getBodyPartAt (i - 1)->getRotation ());
					getBodyPartAt (i)->setTurnX (getBodyPartAt (i - 1)->getPosition ().getX ());
					getBodyPartAt (i)->getPosition ().setX (getBodyPartAt (i - 1)->getPosition ().getX ());
				}
				break;
			case 2:
				//up
				getBodyPartAt (i)->setPosition (Point2D (getBodyPartAt (i)->getPosition ().getX (),
														 getBodyPartAt (i)->getPosition ().getY () - displacement));

				if (getBodyPartAt (i)->getPosition ().getY () < getBodyPartAt (i - 1)->getTurnY ()) {
					getBodyPartAt (i)->setRotation (getBodyPartAt (i - 1)->getRotation ());
					getBodyPartAt (i)->setTurnY (getBodyPartAt (i - 1)->getPosition ().getY ());
					getBodyPartAt (i)->getPosition ().setY (getBodyPartAt (i - 1)->getPosition ().getY ());
				}
				break;
			case 3:
				//down
				getBodyPartAt (i)->setPosition (Point2D (getBodyPartAt (i)->getPosition ().getX (),
														 getBodyPartAt (i)->getPosition ().getY () + displacement));

				if (getBodyPartAt (i)->getPosition ().getY () > getBodyPartAt (i - 1)->getTurnY()){
					getBodyPartAt (i)->setRotation (getBodyPartAt (i - 1)->getRotation ());
					getBodyPartAt (i)->setTurnY (getBodyPartAt (i - 1)->getPosition ().getY ());
					getBodyPartAt (i)->getPosition ().setY (getBodyPartAt (i - 1)->getPosition ().getY ());
				}
				break;
			default: break;
		}
	}

}

void Snake::pushPreviousTurnPosition(Point2D lastPosition)
{
	earlierTurns.push (lastPosition);
}

Point2D Snake::popPreviousTurnPosition()
{
	auto popped = earlierTurns.back ();
	earlierTurns.pop();
	return popped;
}

void Snake::drawSnake()
{

//	getBodyPartAt(0)->getImage ()->draw (getBodyPartAt(0)->getRotation ());

	
	for (auto i = 0; i <= length-1; i++)
	{
		getBodyPartAt (i)->getImage ()->draw (getBodyPartAt (0)->getRotation ());
	}

	getHead ()->getImage ()->draw (getHead ()->getRotation ());

}

Snake::Snake(int snakeLength) {
	length = snakeLength;
}
