#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include <fstream>

using namespace std;
using namespace sf;

// finish the ShapeMgr class.


class ShapeMgr
{
private:
	vector<DrawingShape *>shapes;
	getfileRecord data;
public:
	ShapeMgr()
	{
		/*fstream file;
		file.open("shapes.bin", ios::in | ios::binary);
		if (!file)
		{
			cout << "Could not load" << endl;
			exit(-1);
		}
		while (file)
		{
			getfileRecord temp;
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			Color temp_color(temp.Color);
			if (temp.position.x >= 200 && temp.position.y >= 20)
			{
				if (temp.Size == CIRCLE)
				{
					shapes.push_back(new Circle(temp.position, temp_color));
				}
			}
		}*/
	}

	void load() {//Loading into a file
		fstream file;
		file.open("shapes.bin", ios::in | ios::binary);
		if (!file)
		{
			cout << "Could not load" << endl;
			exit(-1);
		}
		while (file)
		{
			getfileRecord temp;
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			Color temp_color(temp.Color);
				if (temp.Size == CIRCLE)
				{
					shapes.push_back(new Circle(temp.position, temp_color));
				}
				else {
					shapes.push_back(new Square(temp.position, temp_color));
				}
		}
	}
	~ShapeMgr()
	{/*Going to have a loop and the statement/condition is going to be the
	 drawing shape and in the loop it going to be the different things about 
	 the shape and from that information its going to create a shape and push that
	 information onto the vector*/
		//Saving
		fstream object;
		object.open("shapes.bin", ios::out | ios::binary);
		for (int i = 0; i < shapes.size(); i++) {
			data = (*shapes[i]).getRecords();
			object.write(reinterpret_cast<char *>(&data), sizeof(getfileRecord));
		
		}
		object.close();
		while (!shapes.empty())
			shapes.pop_back();
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		pos.x -= 10;
		pos.y -= 10;

		if (whichShape == CIRCLE)
		{
			Circle *a = new Circle(pos, color);
			shapes.push_back(a);
		}
		else if (whichShape == SQUARE)
		{
			Square *b = new Square(pos, color);
			shapes.push_back(b);
		}
	}
	int getVectorSize()
	{
		return shapes.size();
	}

	DrawingShape* getElemVector(int i)
	{
		return shapes[i];
	}
};


