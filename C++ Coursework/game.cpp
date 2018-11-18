#include "pch.h"
#include "robot.h"
#include "robot.cpp"
#include <iostream>
#include <string>
#include <tuple>
#include <list>
#include <algorithm>
#include <map>
#include <vector>


using namespace std;

class game {

	 map<string, robot> robots;

public:
	int num_robots() const {
		return robots.size();
	}



	void move(const string &name, int dir) {
		if (robots.count(name) == 0) {

			robot rob = robot(name);
			robots.emplace(name, rob);
			switch (dir) {
			case 0:
				robots.find(name)->second.move_north();
			case 1:
				robots.find(name)->second.move_east();
			case 2:
				robots.find(name)->second.move_south();
			case 3:
				robots.find(name)->second.move_west();
			}

		}
		else {
			switch (dir) {
			case 0:
				robots.find(name)->second.move_north();
			case 1:
				robots.find(name)->second.move_east();
			case 2:
				robots.find(name)->second.move_south();
			case 3:
				robots.find(name)->second.move_west();
			}

		}
	}

	int num_close() const {
		int count = 0;
		for (map<string, robot>::iterator it = robots.begin; it != robots.end(); ++it ) {
			if (robot::distance(it->second) <= 10) {
				count++;
			}
		}
		return count;
	}

	int max_distance() const {
		int max = 0;
		for (const auto& robot_pair : robots) {
			robot rob("name");
			rob.distance(rob);
			if (distance(robot_pair) > max) {
				max = distance(robot_pair);
			}
		}
		return max;
	}

	string furthest() const {
		int max = 0;
		string name;
		for (const auto& robot_pair : robots) {
			if (distance(robot_pair) > max) {
				max = distance(robot_pair);
				name = robot_pair.second.name;
			}
		}
		return name;
	}

	vector<robot> robots_by_travelled() const {
		vector<robot> robotsList = vector<robot>();
		for (const auto& robot_pair : robots) {
			robotsList.push_back(robot_pair.second);
		}
		sort(robotsList.begin(), robotsList.end(), [](const robot& lhs, const robot& rhs) {
			return distance(lhs) < distance(rhs);
		
		});

	}
};
