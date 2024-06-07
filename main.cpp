#include <iostream>
#include "tank.h"
#include "tanklist.h"
#include <string>
#include <fstream>

using namespace std;

void New(TankList* tanklist);           //adds a new entry to the list
void Print(TankList* tanklist);         //prints a node based on the given identifier
void Remove(TankList* tanklist);        //removes a node based on the given identifier
void Save(TankList* tanklist);          //saves the current linked list to a file
void Quit(TankList* tanklist);          //saves the linked list and exits the program

int main (int argc, char *argv[]) {
  string userCommand;

  TankList tanklist("tanks.txt");

  while (true) {  //parses user input to call correct function
    cout << ">> ";
    cin >> userCommand;
    if (!userCommand.compare("New")) {
      New(&tanklist);
    }
    if (!userCommand.compare("Print")) {
      Print(&tanklist);
    }
    if (!userCommand.compare("Remove")) {
      Remove(&tanklist);
    }
    if (!userCommand.compare("Save")) {
      Save(&tanklist);
    }
    if (!userCommand.compare("Quit")) {
      Quit(&tanklist);
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

  tanklist -> pushBack(tank); //see TankList::pushBack in tanklist.h 

  return;
}

void Print(TankList* tanklist) {
  string userIn;
  cout << "Enter Identifier: ";
  cin >> userIn;
  Tank* tank = tanklist->searchFor(userIn); //see TankList::searchFor in tanklist.h
  if (tank != nullptr) {
    tank->print();  //see Tank::print in tank.h
  } else {
    std::cout << userIn << " is not a valid identifier" << endl;
  }
  return;
}

void Remove(TankList* tanklist) {
  string userIn;
  
  Node* currNode = tanklist->getHead();  // see tanklist.h
  Node* previousNode = tanklist->getHead();

  cout << "Enter Identifier: ";
  cin >> userIn;

  if(currNode->m_tank.getIdentifier() == userIn) { // checks if chosen tank is head and if so runs pushHead to remove the head from the list and promote next node to head
    tanklist->pushHead();
    cout << "Entry Removed\n";
    return;
  }

  currNode = currNode->m_next;
  while (currNode->m_tank.getIdentifier() != userIn) { // loops through the list till it finds the users chose node and removes it
    currNode = currNode->m_next;
    previousNode = previousNode->m_next;
  }

  previousNode->m_next = currNode->m_next;
  cout << "Entry Removed\n";

  free(currNode);
  
  return;
} 

void Save(TankList* tanklist) {
  ofstream tanksFile;
  tanksFile.open("tanks.txt"); // saves the current list to the same file as it is read in from 

  Node* currNode = tanklist->getHead();
  while (currNode != nullptr) {
    Tank currTank = currNode->m_tank;
    currTank.filePrint(tanksFile);
    currNode = currNode->m_next;
  }

  tanksFile.close();
  return;
}

void Quit(TankList* tanklist) { // saves the list to disk using the same function as Save then frees the memory
  Save(tanklist);
  tanklist->freeList();
}
