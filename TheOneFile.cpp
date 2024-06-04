#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Tank {
    private:
        string m_name;
        string m_identifier;
        string m_armament; 
        string m_nation;
        string m_bday;
        
    public:
        Tank();
        void TankSetter(string identifier, string name, string armament, string nation, string bday);
        void print();
        void filePrint(ostream &out);
        string getIdentifier();
        string getName();
        string getArmament();
        string getNation();
        string getBday();
};

class Node { 
    public: 
        Tank m_tank; 
        Node* m_next; 
  
        Node() { 
            m_tank = Tank(); 
            m_next = nullptr; 
        } 
  
        Node(Tank tank) { 
            m_tank = tank; 
            m_next = nullptr; 
        }

        Node* getNext() {
            return m_next;
    } 
};

class TankList {
    private:
        Node* m_head;
        Node* m_tail;

    public:
        TankList();
        TankList(const Tank tankarray[], int size);
        TankList(const string FILENAME);
        Node* getHead();
        Node* getTail();
        Tank* searchFor(string target);
        void pushBack(const Tank newItem);
        void pushBack(const Tank tankarray[], int size);
        void pushFront(const Tank newItem);
        void insertAfter(const Tank target);
        void remove(const Tank target);
        
};

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

  Tank tank;
  tank.TankSetter(identifier, name, armament, nation, bday);

  tanklist->pushBack(tank);

  return;
}

void Print(TankList* tanklist) {
  string userIn;
  cout << "Identifier: ";
  cin >> userIn;
  Tank* tank = tanklist->searchFor(userIn);
  tank->print();
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

Tank::Tank() {
    string nullStr = "Null";
    m_identifier = nullStr;
    m_name = nullStr;
    m_armament = nullStr;
    m_nation = nullStr;
    m_bday = nullStr;
}

void Tank::TankSetter(string identifier, string name, string armament, string nation, string bday) {
    m_identifier = identifier;
    m_name = name;
    m_armament = armament;
    m_nation = nation;
    m_bday = bday;
}

void Tank::print() {
    cout << "___" << endl << endl;
    cout << "Identifier - \"" << m_identifier << "\"" << endl;
    cout << "Name - \"" << m_name << "\"" << endl;
    cout << "Armament - \"" << m_armament << "\"" << endl;
    cout << "Nation - \"" << m_nation << "\"" << endl;
    cout << "Birthday - \"" << m_bday << "\"" << endl << endl;
    cout << "___" << endl;
}

void Tank::filePrint(ostream &out) {
  out << m_identifier << " " << m_name << " " << m_armament << " " << m_nation << " " << m_bday << " " << endl;
}

string Tank::getIdentifier() {
    return m_identifier;
}

string Tank::getName() {
    return m_name;
}

string Tank::getArmament() {
    return m_armament;
}

string Tank::getNation() {
    return m_nation;
}

string Tank::getBday() {
    return m_bday;
}

TankList::TankList() {
    m_head = nullptr;
    m_tail = nullptr;
}

TankList::TankList(const string FILENAME) {
  string identifier, name, armament, nation, bday;
  ifstream tanksFile("tanks.txt");

  tanksFile >> identifier >> name >> armament >> nation >> bday;

  Tank tank;
  tank.TankSetter(identifier, name, armament, nation, bday);

  m_head = new Node(tank);
  Node* currNode = m_head;

  if (tanksFile.is_open()) {
    while (tanksFile >> identifier >> name >> armament >> nation >> bday) { 
      Tank tank;
      tank.TankSetter(identifier, name, armament, nation, bday);

      Node* nextNode = new Node(tank);
      currNode -> m_next = nextNode;
      currNode = nextNode;
    }
  }

  m_tail = currNode;
}

Node* TankList::getHead() {
    return m_head;
}

Node* TankList::getTail() {
    return m_tail;
}

void TankList::pushBack(const Tank newItem) {
    //Create a new node, instantiated with the new tank object
    Node* newNode = new Node(newItem);
    m_tail -> m_next = newNode;
    m_tail = newNode;
}

Tank* TankList::searchFor(string target) {
    Node* currNode = m_head;
    while (currNode != nullptr) {
        //Search through each of the data fields to see if the search term matches
        //Any of the tank's fields.
        if (target.compare(currNode -> m_tank.getArmament())    ||
            target.compare(currNode -> m_tank.getBday())        ||
            target.compare(currNode -> m_tank.getIdentifier())  ||
            target.compare(currNode -> m_tank.getName())        ||
            target.compare(currNode -> m_tank.getNation())      ){
                //HIT! Return the tank node
                return &currNode -> m_tank;
            } else {
                currNode = currNode -> m_next;
            }
    }
    //Did not find tank
    return nullptr;
}
