#pragma once

/*
* @file: GameData.h
* @author: Torstein Alvern
* @version: 1.0.0 <20.03.2017>
*
* @description: A class to hold game data
*/

#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameData {
public:
	GameData (unsigned int* window);	// Hidden constructor
	int GetWindowSizeX () const;
	int GetWindowSizeY () const;
private:
	unsigned int m_window; // pointer to main window
	int windowSizeX;
	int windowSizeY;
};
#endif