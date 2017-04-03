#include "GameData.h"

//Trenger info for:

//Window Width/Height
	//Grid Size X
	//Grid Size Y
	//Grid Square size X (probably = window width / grid size X
	//Grid Square size Y (probably = window height / grid size Y

//Snake Head
	// Size
	// Color
	// 

//Snake Body Part
	// Size
	// Color
	// 

//Apple
	// Size
	// Color


GameData::GameData(unsigned* window)
{
	m_window = *window;
}

int GameData::GetWindowSizeX() const
{
	return windowSizeX;
}

int GameData::GetWindowSizeY() const
{
	return windowSizeY;
}

