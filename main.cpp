#include <iostream>
#include "tank.cpp" //Tank(string identifier, string name, string armament, string nation, string bday);
#include <string>



void New();    //adds a new entry to the list
void Print();  //prints a node based on the given identifier
void Remove(); //removes a node based on the given identifier
void Save();   //saves the current linked list to a file
void Quit();   //saves the linked list and exits the program


int main (int argc, char *argv[]) {
  std::string userCommand;

  while (true) {
    std::cout << "> ";
    std::cin >> userCommand;
     if (userCommand.compare("New\n")) {
      std::cout << "Works";
      break;
     }
  }
  return 0;
}
