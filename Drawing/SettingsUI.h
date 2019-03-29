#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include "Shape.h"
#include <string>

// finish this code; add functions, data as needed
//Bail out funtion
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

//These line are for the calculation and set up of dispaly
const int TEXT_X = 30;
const int SHAPE_X = 45;
const int CHANGE_IN_Y = 45;
const int TEXT_Y_COLOR = 35;
const int TEXT_Y_SHAPE = TEXT_Y_COLOR + 250;
const int COLOR_Y_START = TEXT_Y_COLOR + 40;
const int SHAPE_Y_START = TEXT_Y_SHAPE + 40;
//These each set the offset for each part of the display on x and y 

class SettingsUI
{
private:
	SettingsMgr* ptr;
	Circle rBtn, gBtn, bBtn, wBtn;
	Square sBtn;
	Font font;
	Text selectedColor, selectedShape;
	void setButtons();
	void setText();
	void setR();
	void setG();
	void setB();
	void setCircle();
	void setSquare();

public:
	SettingsUI(SettingsMgr *mgr)
	{
		/*Checks if the font is loaded and if not
		the statement will be put out and it will bail
		out*/
		if (!font.loadFromFile("arial.ttf"))
			die("couldn't load font");
		ptr = mgr;//Making ptr point to the place mgr is pointing
		setText();
		setButtons();

	}
	void handleMouseUp(Vector2f mouse)
	{
		//Setting the different colors depending on the mouse
		if (rBtn.getBounds().contains(mouse))
		{		//.contains-checking if the mouse is within the bounds of the button
			setR();//If the statement is true it sets the color
		}
		else if(gBtn.getBounds().contains(mouse))
		{
			setG();
		}
		else if (bBtn.getBounds().contains(mouse))
		{
			setB();
		}
		else if (wBtn.getBounds().contains(mouse))
		{
			setCircle();
		}
		else if (sBtn.getBounds().contains(mouse))
		{
			setSquare();
		}
	}

	void draw(RenderWindow& win)
	{
		win.draw(selectedColor);
		win.draw(selectedShape);
		rBtn.draw(&win);
		bBtn.draw(&win);
		gBtn.draw(&win);
		wBtn.draw(&win);
		sBtn.draw(&win);

	}

};

void SettingsUI::setButtons()
{//Set the Color and Position of the Buttons
	//The order in which I do it is so that I don't get lost
	rBtn.setColor(Color::Red, Color::Black);
	bBtn.setColor(Color::Blue, Color::Black);
	gBtn.setColor(Color::Green, Color::Black);
	wBtn.setColor(Color::White, Color::Black);
	sBtn.setColor(Color::White, Color::Black);
	//Sets the offset of Position by the button before it
	rBtn.setPos(Vector2f(SHAPE_X, COLOR_Y_START));
	bBtn.setPos(Vector2f(SHAPE_X, rBtn.getPos().y + CHANGE_IN_Y));
	gBtn.setPos(Vector2f(SHAPE_X, bBtn.getPos().y + CHANGE_IN_Y));
	sBtn.setPos(Vector2f(SHAPE_X,SHAPE_Y_START));
	wBtn.setPos(Vector2f(SHAPE_X, sBtn.getPos().y + CHANGE_IN_Y));
	
}
//Setting the Color and the Shapes for the text also Position
void SettingsUI::setText()
{
	//Putting Color and Shape through the same sets to 
	//Create the outlines of the text
	selectedColor.setString("Selected Color: ");
	selectedColor.setFont(font);
	selectedColor.setPosition(Vector2f(TEXT_X, TEXT_Y_COLOR));
	selectedShape.setString("Selected Shape: ");
	selectedShape.setFont(font);
	//Using Vector2f for the Position
	selectedShape.setPosition(Vector2f(TEXT_X,TEXT_Y_SHAPE));

}
//This sets the Color Buttons
void SettingsUI::setR()
{
	/*Only the Button of that color will be set in the first position of x so it shows
	up the other button colors will be black to indicate they are off
	or not selected.*/
	rBtn.setColor(Color::Red, Color::Black);
	gBtn.setColor(Color::Black, Color::Green);
	bBtn.setColor(Color::Black, Color::Blue);
	ptr->setColor(Color::Magenta);

}

void SettingsUI::setG()
{
	/*Only the Button of that color will be set in the first position of x so it shows
	up the other button colors will be black to indicate they are off
	or not selected.*/
	rBtn.setColor(Color::Black, Color::Red);
	gBtn.setColor(Color::Green, Color::Black);
	bBtn.setColor(Color::Black, Color::Blue);
	ptr->setColor(Color::Green);

}

void SettingsUI::setB()
{
	/*Only the Button of that color will be set in the first position of x so it shows
	up the other button colors will be black to indicate they are off
	or not selected.*/
	rBtn.setColor(Color::Black, Color::Red);
	gBtn.setColor(Color::Black, Color::Green);
	bBtn.setColor(Color::Blue, Color::Black);
	ptr->setColor(Color::Cyan);

}

void SettingsUI::setCircle()
{
	/*Only the Button of that color will be set in the first position of x so it shows
	up the other button colors will be black to indicate they are off
	or not selected.*/
	wBtn.setColor(Color::White, Color::Black);
	sBtn.setColor(Color::Black, Color::White);
	ptr->setShape(CIRCLE);

}

void SettingsUI::setSquare()
{
	/*Only the Button of that color will be set in the first position of x so it shows
	up the other button colors will be black to indicate they are off
	or not selected.*/
	wBtn.setColor(Color::Black, Color::White);
	sBtn.setColor(Color::White, Color::Black);
	ptr->setShape(SQUARE);

}