#include <iostream>
#include "tank.cpp" //Tank(string identifier, string name, string armament, string nation, string bday);
#include "tanklist.cpp"
#include <string>

using namespace std;

void New();    //adds a new entry to the list
void Print();  //prints a node based on the given identifier
void Remove(); //removes a node based on the given identifier
void Save();   //saves the current linked list to a file
void Quit();   //saves the linked list and exits the program


int main (int argc, char *argv[]) {
  string userCommand;

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
  string identifier;
  string name;
  string armament;
  string nation;
  string bday;
  
  cout << "Enter identifier : ";
  cin >> identifier;
  cout << "Enter name : ";
  cin >> name;
  cout << "Enter armament : ";
  cin >> armament;
  cout << "Enter nation : ";
  cin >> nation;
  cout << "Enter Birthday : ";
  cin >> bday;

  Tank tank(identifier, name, armament, nation, bday);
  tanklist.pushback(tank);
  return;
}

void Print() {

}

void Remove()
void Save()
void Quit()
