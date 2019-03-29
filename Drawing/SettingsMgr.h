#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color chosenColor;
	ShapeEnum chosenShape;

public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		fstream file2;
		file2.open("settings.bin", ios::in| ios::out | ios::binary);
		file2.read(reinterpret_cast<char*>(&chosenColor), sizeof(Color));
		file2.read(reinterpret_cast<char*>(&chosenShape), sizeof(ShapeEnum));
		//chosenColor = startingColor;
		//chosenShape = startingShape;
		file2.close();

	}
	~SettingsMgr()
	{
		fstream saved;
		saved.open("settings.bin", ios::out | ios::binary);

		saved.write(reinterpret_cast<char *>(&chosenColor), sizeof(Color));
		saved.write(reinterpret_cast<char*>(&chosenShape), sizeof(ShapeEnum));
		saved.close();
	}
	//Update current color
	Color getCurColor()
	{
		return chosenColor; //Returns the chosen color 
	}

	//Update current shape
	ShapeEnum getCurShape()
	{
		return chosenShape; // just to make it compile;
	}
	//Sets the color that is picked just to 
	//Be able to use the color
	void setColor(Color newColor)
	{
		chosenColor = newColor;
	}
	//Sets the new shape to what is passed for what is created
	void setShape(ShapeEnum newShape)
	{
		chosenShape = newShape;
	}
};
