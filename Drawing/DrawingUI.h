#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"
#include "Shape.h"
// finish this code; add functions, data as needed

class DrawingUI
{
private:
	//Creating the canvas
	Square canvasOutline;
	Square canvas;
public:
	DrawingUI(Vector2f p)
	{
		canvas.setColor(Color::Black, Color::Black);
		canvas.setPos(p);
		canvas.size(350, 450);
		canvas.Thickness(0);
		canvasOutline.setColor(Color::Transparent, Color::White);
		canvasOutline.setPos(Vector2f(p.x -50.5, p.y));
		canvasOutline.size(400, 510);
		canvasOutline.Thickness(10);
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		/*Creating a pointer pointing to the object
		that will be created and pushing the vector
		back the amount of space it takes for the
		shape to be added*/
		vector<DrawingShape *>ptr;
		canvas.draw(&win);
		if (mgr->getVectorSize() > 0)
		{
			for (int i = 0; i < mgr->getVectorSize(); i++)
			{
				ptr.push_back(mgr->getElemVector(i));
				ptr[i]->draw(&win);
			}
		}
		canvasOutline.draw(&win);
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inside = false;
		//check if the mouse is "inside" the canvas 
		if (canvas.getBounds().contains(mousePos))
		{
			inside = true;
		}
		return inside;
	}

};

