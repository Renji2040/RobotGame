#include "pch.h"
#include "robot.h"
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

	game() {

	}

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
				break;	
			case 1:
				robots.find(name)->second.move_east();
				break;
			case 2:
				robots.find(name)->second.move_south();
				break;
			case 3:
				robots.find(name)->second.move_west();
				break;
			}

		}
		else {
			switch (dir) {
			case 0:
				robots.find(name)->second.move_north();
				break;
			case 1:
				robots.find(name)->second.move_east();
				break;
			case 2:
				robots.find(name)->second.move_south();
				break;
			case 3:
				robots.find(name)->second.move_west();
				break;
			}

		}
	}

	int num_close() const {
		int count = 0;
		typedef map<string, robot>::const_iterator iter;
		for (iter r = robots.cbegin(); r != robots.cend(); ++r ) {
			robot* robotinstance = new robot();
			if (robotinstance->distance(r->second) <= 10) {
				count++;
			}
		}
		return count;
	}

	int max_distance() const {
		int max = 0;
		typedef map<string, robot>::const_iterator iter;
		for (iter r = robots.cbegin(); r != robots.cend(); ++r) {
			robot rob("name");
			rob.distance(rob);
			robot* robotInstance = new robot();
			if (robotInstance->distance(r->second) > max) {
				max = robotInstance->distance(r->second);
			}
		}
		return max;
	}

	string furthest() const {
		int max = 0;
		string name;
		robot* robotInstance = new robot();
		typedef map<string, robot>::const_iterator iter;
		for (iter r = robots.cbegin(); r != robots.cend(); ++r) {
			if (robotInstance->distance(r->second) > max) {
				max = robotInstance->distance(r->second);
				name = r->first;
			}
		}
		return name;
	}
	
	struct pred {
		inline bool operator() (robot& rob1, robot& rob2)
		{
			
			return rob1.travelled() > rob2.travelled();
		}
	};

	vector<robot> robots_by_travelled() const {
		vector<robot> robotsList = vector<robot>();
		robot* robotInstance = new robot();
		typedef map<string, robot>::const_iterator iter;
		for (iter r = robots.cbegin(); r != robots.cend(); ++r) {
			robotsList.push_back(r->second);
		}
		sort(robotsList.begin(), robotsList.end(), pred());
		return robotsList;
	}
	
};
