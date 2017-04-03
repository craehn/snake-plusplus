#pragma once
#include "Point2D.h"
#include "SDL/SDLBmp.h"


enum Rotation
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};


class GameObject
{
public:
	GameObject (Point2D newPosition, SDLBmp* newImage, Rotation rotation);
	Point2D getPosition ();
	void setPosition (Point2D newPosition);
	SDLBmp* getImage ();
	void setImage (SDLBmp* newImage);
	void setRotation (Rotation newRotation);
	Rotation getRotation ();
	Point2D getPreviousPosition();
	void setPreviousPosition (Point2D position);
	void follow(GameObject* bodyPart);

	float getTurnX();
	float getTurnY();
	void setTurnX(float newX);
	void setTurnY(float newY);
private:
	Point2D previousPosition;
	Point2D position;
	Rotation rotation; 
	SDLBmp* image;
	float turnX;
	float turnY;
};

