#include "GameObject.h"


GameObject::GameObject (Point2D newPosition, SDLBmp* newImage, Rotation newRotation)
{

	position = newPosition;
	image = newImage;
	rotation = newRotation;
	turnX = position.getX();
	turnY = position.getY();
}

Point2D GameObject::getPosition()
{
	return position;
}

void GameObject::setPosition(Point2D newPosition)
{
	position = newPosition;
}

SDLBmp* GameObject::getImage()
{
	image->x = this->getPosition ().getX ();
	image->y = this->getPosition ().getY ();
	return image;
}

void GameObject::setImage(SDLBmp* newImage)
{
	image = newImage;
}

void GameObject::setRotation(Rotation newRotation)
{
	rotation = newRotation;
}

Rotation GameObject::getRotation()
{
	return rotation;
}

Point2D GameObject::getPreviousPosition()
{
	return previousPosition;
}

void GameObject::setPreviousPosition(Point2D oldPosition)
{
	previousPosition = oldPosition;
}

void GameObject::follow(GameObject* bodyPart)
{
	setPosition (bodyPart->getPreviousPosition ());
}

float GameObject::getTurnX()
{
	return turnX;
}

float GameObject::getTurnY()
{
	return turnY;
}

void GameObject::setTurnX(float newX)
{
	turnX = newX;
}

void GameObject::setTurnY(float newY)
{
	turnY = newY;
}
