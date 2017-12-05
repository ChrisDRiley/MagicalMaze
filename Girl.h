#include <string>
#include "tree.h"
#include "Room.h"
#ifndef GIRL_H
#define GIRL_H

class Girl {
	public:
		Girl();
		void reward(int gold);
		int countRooms();
		int countElfRooms();
		int countMonsterRooms();
		int countWizardRooms();
		int getGold();
		bool nextMove(std::string choice, TreeType<Room> &tree);
		bool isGameOver();
		void printGirlStatus();
	private:
		int roomCount;
		int elfRoomCount;
		int monsterRoomCount;
		int wizardRoomCount;
		int totalGold;
		bool gameOver;
};
#endif
