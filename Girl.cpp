#include <string>
#include <iostream>
#include "Girl.h"
#include "tree.h"
#include "Room.h"
#ifndef GIRL_CPP
#define GIRL_CPP

Girl::Girl()
{
	roomCount = 0;
	elfRoomCount = 0;
	monsterRoomCount = 0;
	wizardRoomCount = 0;
	totalGold = 0;
	gameOver = false;
}
void Girl::reward(int gold)
{
	totalGold += gold;
}
int Girl::getGold()
{
	return totalGold;
}
int Girl::countRooms()
{
	return roomCount;
}
int Girl::countElfRooms()
{
	return elfRoomCount;
}
int Girl::countMonsterRooms()
{
	return monsterRoomCount;
}
int Girl::countWizardRooms()
{
	return wizardRoomCount;
}
//Returns false if valid direction not given , otherwise moves along the tree and performs operations
bool Girl::nextMove(string choice, TreeType<Room> &tree)
{
	if(choice == "left")
	{
		tree.moveCurrentLeft();
		Room room = tree.getCurrentData();
		room.printRoom();
		if(room.getLast() == "wizard"){
			totalGold = (room.getA() * totalGold + room.getB());
			wizardRoomCount++;
			gameOver = true;
		}
		else if(room.getLast() == "elf"){
			totalGold += room.getReward();
			elfRoomCount++;
		}
		else{
			totalGold += room.getReward();
			monsterRoomCount++;
		}
		if(totalGold < 1){
			gameOver = true;
			cout << "You lost all your gold, now youre POOR and DEAD" << endl;
		}
		return true;
	}
	else if(choice == "right")
	{
		tree.moveCurrentRight();
		Room room = tree.getCurrentData();
		room.printRoom();
		if(room.getLast() == "wizard"){
			totalGold = (room.getA() * totalGold + room.getB());
			wizardRoomCount++;
			gameOver = true;
		}
		else if(room.getLast() == "elf"){
			totalGold += room.getReward();
			elfRoomCount++;
		}
		else{
			totalGold += room.getReward();
			monsterRoomCount++;
		}
		if(totalGold < 1){
			gameOver = true;
		}
		return true;
				
	}
	else{
		return false;
	}
	
}
bool Girl::isGameOver(){
	return gameOver;
}
void Girl::printGirlStatus(){
	cout << "Final STATS:" << endl;
	cout << "Monster rooms visited: " << monsterRoomCount << endl;
	cout << "Elf rooms visited: " << elfRoomCount << endl;
	cout << "Wizard rooms visited: " << wizardRoomCount << endl;
	cout << "Total gold: " << totalGold << endl;	
}
#endif	
