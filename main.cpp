#include <iostream>
#include "tank.cpp" //Tank(string identifier, string name, string armament, string nation, string bday);
#include "tanklist.cpp"
#include <string>
#include <fstream>

using namespace std;

void New();           //adds a new entry to the list
void Print();         //prints a node based on the given identifier
void Remove();        //removes a node based on the given identifier
void Save();          //saves the current linked list to a file
void Quit();          //saves the linked list and exits the program
void ReadFile();      //reads in file to initialize linked list

int main (int argc, char *argv[]) {
  string userCommand;

  ReadFile();

  while (true) {
    cout << "> ";
    cin >> userCommand;
    if (userCommand.compare("New\n")) {
      New();
    }
    if (userCommand.compare("Print\n")) {
      Print();
    }
    if (userCommand.compare("Remove\n")) {
      Remove();
    }
    if (userCommand.compare("Save\n")) {
      Save();
    }
    if (userCommand.compare("Quit\n")) {
      Save();
      break;
    }
  }
  return 0;
}

void New() {
}

void Print() {
}

void Remove() {
} 

void Save() {
}

void Quit() {
}

void ReadFile() {
  string identifier, name, armament, nation, bday;

  ifstream tanksFile("tanks.txt");
  if (tanksFile.is_open()) {
    while (tanksFile >> identifier >> name >> armament >> nation >> bday) {
      
    }
  }
}
