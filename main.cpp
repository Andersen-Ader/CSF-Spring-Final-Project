#include <iostream>
#include "tank.cpp" //Tank(string identifier, string name, string armament, string nation, string bday);


void New();
void Print();
void Remove();
void Save();
void Quit();


int main (int argc, char *argv[]) {
  
  while (true) {
    std::cout << "> ";
    std::cin >> userCommand;
    
  }
  return 0;
}
