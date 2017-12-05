#include <string>
#ifndef ROOM_H
#define ROOM_H

class Room 
{
	public:
		Room();
		Room(std::string line);
		std::string getFirst();
		std::string getLast();
		int getReward();
		int getA();
		int getB();
		void printRoom();
		void operator=(Room other);
		bool operator>(Room other);
		bool operator<(Room other);
		bool operator>=(Room other);
		bool operator<=(Room other);
	private:
		std::string firstName;
		std::string lastName;
		int reward;
		int a;
		int b;
};
#endif
		

