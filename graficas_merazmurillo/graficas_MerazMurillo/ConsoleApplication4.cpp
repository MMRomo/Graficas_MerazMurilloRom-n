#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <conio.h> 
using namespace std;

struct vertex
{
	float x;
	float y;
	float z;
};

int main()
{
	fstream file;
	vector<vertex*> list;
	vector<vertex*>::iterator IT;
	string fileName, find;
	int MAX, trash;
	char character, key;

	cout << "File to open?, use the extension .X: " << endl;
	cin >> fileName;

	file.open(fileName, ios_base::in);

	if (file.is_open())
	{
		system("cls");
		getline(file, find);
		if (find.find(" Mesh mesh_"))
		{
			MAX = 4041;
			file >> character;
		}
	
		for (int i = 0; i < MAX; i++)
		{
			vertex* value = new vertex;
			file >> value->x;
			file >> character;
			file >> value->y;
			file >> character;
			file >> value->z;
			file >> character;
			file >> character;
			list.push_back(value);
		}
	}
	else
	{
		cout << "File not found" << endl;
		return 0;
	}
	cout << "Spacebar prints 1 line" << endl << "Enter prints all" << endl << "Esc to exit" << endl;
	key = _getch();
	   
	while (key != 27)
	{
		if (key == 0)
		{
			key = _getch();
		}
		else
		{
			for (int n = 0; n < MAX; n++)
			{
				while (key != 32 && key != 13)
				{
					key = _getch();
				}
				cout << list[n]->x << ", " << list[n]->y << ", " << list[n]->z << endl;
				if (key == 32)
				{
					key = _getch();
				}
			}
		}

		/*key = _getch();
		switch (key)
		{
		case 32: // spacebar
		//for (IT = list.begin(); IT != list.end(); ++IT)
		for (int i = 0; i < MAX; i++)
		{
		cout << list[i]->x << ", " << list[i]->y << ", " << list[i]->z << endl;
		key = _getch();
		}
		break;
		case 13: // Enter
		//for (IT = list.begin(); IT != list.end(); ++IT)
		for (int i = 0; i < MAX; i++)
		{
		//cout << *IT << " - ";
		cout << list[i]->x << ", " << list[i]->y << ", " << list[i]->z << endl;
		}
		break;
		default:
		break;
		}*/
	}

	return 0;
}

