#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Room.h"
#ifndef ROOM_CPP
#define ROOM_CPP

using namespace std;

Room::Room(){
	firstName = "";
	lastName = "";
	reward = 0;
	a = 0;
	b = 0;
}
// Separate line from file into first and last name, randomly choose reward
Room::Room(string line){
	srand (time(NULL));

	firstName = line.substr(0,line.find(" "));
	lastName = line.substr(line.find(" ")+1);
	if(lastName == "elf"){
		reward = rand() % 30 + 1;
		a = 0;
		b = 0;
	}
	else if(lastName == "monster"){
		reward = -1*(rand() % 30 + 1);
		a = 0;
		b = 0;
	}
	else{
		reward = 0;
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
	}
}
string Room::getFirst(){
	return firstName;
}
string Room::getLast(){
	return lastName;
}
int Room::getReward(){
	return reward;
}
int Room::getA(){
	return a;
}
int Room::getB(){
	return b;
}
void Room::printRoom(){
	if(lastName == "monster"){
		cout << "Oh shit! It's the " << firstName << " " << 
		lastName << "! It steals " << reward << " gold!" << endl;
	}
	else if(lastName == "elf"){
		cout << "Woohoo! You found the " << firstName << " " << lastName
		<< "! It gives you " << reward << " gold!" << endl;
	}
	else{
		cout << "Oh thank god! Its the wise " << firstName << " " << lastName
		<< "! He does some magic shit to multiple your gold by " << a
		<< " plus an extra " << b << "!" << endl;
	}
}
void Room::operator=(Room other){
	firstName = other.getFirst();
	lastName = other.getLast();
	reward = other.getReward();
	a = other.getA();
	b = other.getB();
}
//Ensures wizards are always at the end, otherwise places in the tree based on first name
bool Room::operator<(Room other){
	if(lastName == "wizard" && other.getLast() == "wizard"){
		return true;
	}
	return firstName < other.getFirst();
}
bool Room::operator>(Room other){
	return firstName > other.getFirst();
}
bool Room::operator<=(Room other){
	return firstName <= other.getFirst();
}
bool Room::operator>=(Room other){
	if(lastName == "wizard" && other.getLast() == "wizard"){
		return true;
	}
	return firstName >= other.getFirst();
}

	
#endif
