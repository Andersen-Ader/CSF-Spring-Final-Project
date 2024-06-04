#include <iostream>
#include "tank.h"
#include "tanklist.h"
#include <string>
#include <fstream>

using namespace std;

void New(TankList* tanklist);           //adds a new entry to the list
void Print(TankList* tanklist);         //prints a node based on the given identifier
void Remove();        //removes a node based on the given identifier
void Save();          //saves the current linked list to a file
void Quit();          //saves the linked list and exits the program

int main (int argc, char *argv[]) {
  string userCommand;

  TankList tanklist("tanks.txt");

  while (true) {
    cout << "> ";
    cin >> userCommand;
    if (!userCommand.compare("New")) {
      New(&tanklist);
    }
    if (!userCommand.compare("Print")) {
      Print(&tanklist);
    }
    if (!userCommand.compare("Remove")) {
      Remove();
    }
    if (!userCommand.compare("Save")) {
      Save();
    }
    if (!userCommand.compare("Quit")) {
      Save();
      break;
    }
  }
  return 0;
}

void New(TankList* tanklist) {
  string identifier, name, armament, nation, bday;
  cout << "Identifier: ";
  cin >> identifier;
  cout << "Name: ";
  cin >> name;
  cout << "Armament: ";
  cin >> armament;
  cout << "Nation: ";
  cin >> nation;
  cout << "Birthday: ";
  cin >> bday;

  Tank tank(identifier, name, armament, nation, bday);

  tanklist -> pushBack(tank);

  return;
}

void Print(TankList* tanklist) {
  string userIn;
  cout << "Enter Identifier: ";
  cin >> userIn;
  Tank* tank = tanklist->searchFor(userIn);
  if (tank != nullptr) {
    tank->print();
  } else {
    std::cout << userIn << " is not a valid identifier" << endl;
  }
  return;
}

void Remove() {
  return;
} 

void Save() {
  return;
}

void Quit() {
  return;
}
