#include <string>
#include "tank.cpp"

using namespace std;
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

TankList::TankList() {
    m_head = nullptr;
    m_tail = nullptr;
}

TankList::TankList(const Tank tankarray[], int size) {
    //Set the head node to the first item in the array
    m_head = new Node(tankarray[0]);
    Node* currNode = m_head;
    for (int i = 1; i < size-1; i++) {
        Node* nextNode = new Node(tankarray[i]);
        currNode -> m_next = nextNode;
        currNode = nextNode;
    }
    //Set tail for this list as the last item in the array
    m_tail = new Node(tankarray[size-1]);
    //Set the last node from the loop above's next node to the tail node
    currNode -> m_next = m_tail;
}

TankList::TankList(const string FILENAME) {
  string identifier, name, armament, nation, bday;
  ifstream tanksFile("tanks.txt");

  tanksFile >> identifier >> name >> armament >> nation >> bday

  m_head = new Node(Tank tank(identifier, name, armament, nation, bday));
  Node* currNode = m_head;

  if (tanksFile.is_open()) {
    while (tanksFile >> identifier >> name >> armament >> nation >> bday) { 
      Node* nextNode = new Node(Tank tank(identifier, name, armement, nation, bday));
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

void TankList::pushBack(const Tank tankarray[], int size) {
    TankList bufferList = TankList(tankarray, size);
    m_tail -> m_next = bufferList.getHead();
    m_tail = bufferList.getTail();
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
