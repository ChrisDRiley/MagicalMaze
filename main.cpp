#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Room.h"
#include "Girl.h"
#include "tree.h"
#ifndef MAIN_CPP
#define MAIN_CPP

using namespace std;

int main( int argc, char *argv[] )
{
	// Open initial file
	if(argc != 2){
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else{
		ifstream the_file (argv[1]);
		if(!the_file.is_open()){
			cout << "Could not open file\n";
		}
		// Core game loop
		else{
			bool playing = true;
			while(playing){
				Girl myGirl;
				TreeType<Room> tree;
				cout << "Welcome to the SPOOKY maze of GOLD and DEATH" << endl;
				cout << "Make it to the end of the maze without losing all your gold or you'll DIE and be POOR" << endl;
				// Read first line of file to get gold amount at start
				string line;
				getline(the_file,line);
				string Sgold = line.substr(line.find(" "));
				int startGold = atoi(Sgold.c_str());
				int count = 0;
				// Make tree
				while(getline(the_file,line)){
					Room room(line);
					tree.Insert(room);
				}
				the_file.close();
				tree.setCurrentToRoot();
				myGirl.reward(startGold);
				// Start game, iterate until no gold or win
				while(!myGirl.isGameOver()){
					int rooms = 0;
					cout << "You have " << myGirl.getGold() << " gold" << endl;
					cout << "You have visited " << rooms << " rooms" << endl << endl;
					cout << "There are two SPOOKY looking DOORS ahead of YOU" << endl;
					cout << "CHOOSE a DOOR, type 'left' or 'right'" << endl;
					string choice;
					bool valid = false;
					while(!valid){
						cin >> choice;
						if(!myGirl.nextMove(choice,tree)){
							cout << "Umm girl? Your choices are 'left' or 'right', dont screw this up again" << endl;
						}
						else{
							valid = true;
							rooms++;
						}
					}
	
				}
				//Print final stats and ask to play again
				myGirl.printGirlStatus();
				cout << "Do you want to play again? (Y) - yes, (N) - no" << endl;
				string choice;
				bool valid = false;
				while(!valid){
					cin >> choice;
					if(choice == "Y"){
						valid = true;
					}
					else if(choice == "N"){
						playing = false;
						valid = true;
					}
					else{
						cout << "Uh, valid option PLEASE, (Y) - yes, (N) - no" << endl;
					}
				}
				valid = false;
				//New file
				while(!valid){
					cout << "Enter the name of a file: " << endl;
					cin >> choice;
					char c[100];
					strncpy(c, choice.c_str(), sizeof(c));
					the_file.open(c);
					if(!the_file.is_open()){
						cout << "Could not open file." << endl;
					}
					else{
						valid = true;
					}
							
				}
				
			}
		}
	}
}
#endif			
