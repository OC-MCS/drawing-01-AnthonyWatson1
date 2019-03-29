#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

//struct goes here
struct getfileRecord
{

	unsigned int Color;
	ShapeEnum Size;
	Vector2f  position;
};

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	//Just telling the class how I want it to be drawn
	//create struct for holding data
	getfileRecord data;
public:
	getfileRecord getRecords()
	{
		return data;
	}
	void setPos2(Vector2f asfab)
	{
		data.position = asfab;
	}
	void setColor2(unsigned int fillColor)
	{
		data.Color = fillColor;
	}
	void setShape2(ShapeEnum SHAPE)
	{
		data.Size = SHAPE;
	}

	virtual void setColor(Color fillColor, Color outlineColor) = 0;
	virtual void setPos(Vector2f asfab) = 0;
	virtual FloatRect getBounds() = 0;
	virtual Vector2f getPos() = 0;
	virtual void draw(RenderWindow* a) = 0;
	/*Saving is just writing and reading to a binary file the close*/
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape c;
	//Create an instance of Circle Class for shape to be drawn
public:
	/*Set the position and thickness of the circle in the
	constructor*/
	Circle()
	{
		c.setOutlineThickness(2);
		c.setRadius(10);
	}
	/*Vector2f is for an already implemented file in the background for graphics
	Here creating a Vector2f for position in the graphics window to be positioned
	*/
	Circle(Vector2f asfab, Color col)
	{
		c.setPosition(asfab);
		setPos2(asfab);
		c.setFillColor(col);
		c.setOutlineColor(col);
		c.setOutlineThickness(2);
		c.setRadius(10);
		setColor2(col.toInteger());
		setShape2(CIRCLE);
	}
	//This is to set the color of the circle's line and outline
	void setColor(Color fillColor, Color outlineColor)
	{
		c.setFillColor(fillColor);
		c.setOutlineColor(outlineColor);
	}

	void setPos(Vector2f asfab)
	{
		c.setPosition(asfab);
	}
	//FloatRect is another class already implemented behind the scenes
	//GetBounds is to check the Bounds of the Shape
	FloatRect getBounds()
	{
		return c.getGlobalBounds();
	}
	Vector2f getPos() 
	{
		return c.getPosition();
	}
	void draw(RenderWindow * win)
	{
		//Win is a Render Window to draw the circle
		win->draw(c);
	}
	//This is a separate backup circle in case the rest don't work it is 
	//A different way to make a circle
	CircleShape makeCircle(float r, float x, float y, Color b)
	{
		CircleShape circle(r);
		circle.setFillColor(Color::Transparent);
		circle.setOutlineColor(b);
		circle.setOutlineThickness(5);
		circle.setPosition(x, y);

		return circle;
	}

};

class Square : public DrawingShape
{
private:
	RectangleShape rect;
public:
	Square()
	{
		rect.setOutlineThickness(2);
		rect.setSize(Vector2f(20,20));
	}
	//constructor for aspects of square
	Square(Vector2f asfab, Color col)
	{
		rect.setPosition(asfab);
		setPos2(asfab);		
		rect.setFillColor(col);
		setColor2(col.toInteger());
		rect.setOutlineColor(col);
		rect.setOutlineThickness(2);
		rect.setSize(Vector2f(20, 20));
		setShape2(SQUARE);
	}
	//sets size
	void size(double x, double y)
	{
		rect.setSize(Vector2f(x,y));
	}
	//sets the color of the square
	void setColor(Color fillColor, Color outlineColor)
	{
		rect.setFillColor(fillColor);
		rect.setOutlineColor(outlineColor);
	}
	//Sets thickness
	void Thickness(int outline)
	{
		rect.setOutlineThickness(outline);
	}
	//sets position
	void setPos(Vector2f asfab)
	{
		rect.setPosition(asfab);
	}
	FloatRect getBounds()
	{
		return rect.getGlobalBounds();
	}
	Vector2f getPos()
	{
		return rect.getPosition();
	}
	void draw(RenderWindow * win)
	{
		//Pointing to the rectangle that is passed
		//Render Window to draw a rectangle
		win->draw(rect);
				
	}
};

