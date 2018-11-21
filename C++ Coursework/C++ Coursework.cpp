// C++ Coursework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "robot.h" 
#include "game.cpp"
#include <iostream>
#include <string>
#include <tuple>
#include <list>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{

	game game;
	game.move("bob", 2);
	game.move("bob", 2);
	game.move("bob", 2);
	game.move("renji", 1);	
	game.move("renji", 3);	
	game.move("renji", 0);
	game.move("renji", 2);
	game.move("tu", 0);
	game.move("tu", 0);	
	game.move("tu", 0);
	game.move("tu", 0);
	
	cout << game.num_robots() << "NUMBER OF ROBOTS" << "\n";
	cout << game.furthest() << "FURTHEST" << "\n";
	cout << game.num_close() << "NUMBER OF CLOSE ROBOTS" << "\n";
	cout << game.max_distance() << "FURTHEST DISTANCE OF ROBOT" << "\n";

	

	vector<robot> robs = game.robots_by_travelled();
	for (auto&& r : robs) {
		cout << r.name() << "\n";
	}
	string name;
	cin >> name;
}




