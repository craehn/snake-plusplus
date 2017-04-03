#pragma once
#include "GameObject.h"
#include <list>
#include <queue>

class Snake : std::list<GameObject>
{
public:
	Snake (GameObject* headPart, GameObject* bodyPart, int startingLength);
	void increaseLength ();
	int getLength ();
	GameObject* getHead ();
	void updatePosition (int direction, float displacement);
	void pushPreviousTurnPosition (Point2D lastPosition);
	Point2D popPreviousTurnPosition ();
	void drawSnake ();
	GameObject* getBodyPartAt (int pos);


private:
	int length;
	std::queue<Point2D> earlierTurns;
	GameObject* headObject;
	GameObject* bodyObject;
//	GameObject* tailObject;
};
