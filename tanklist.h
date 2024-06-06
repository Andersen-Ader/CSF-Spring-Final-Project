#ifndef tanklist_h
#define tanklist_h

#include "tank.h"
#include "node.h"
#include <string>

using namespace std;

class TankList {
    private:
        Node* m_head;
        Node* m_tail;

    public:
        TankList();
        TankList(const string FILENAME);
        Node* getHead();
        Node* getTail();
        Tank* searchFor(string target);
        void pushHead();
        void pushBack(const Tank newItem);
        void freeList();
};

TankList::TankList() {
    m_head = nullptr;
    m_tail = nullptr;
}

TankList::TankList(const string FILENAME) {
  string identifier, name, armament, nation, bday;
  ifstream tanksFile;
  tanksFile.open("tanks.txt");

  tanksFile >> identifier >> name >> armament >> nation >> bday;

  Tank tank(identifier, name, armament, nation, bday);
  

  m_head = new Node(tank);
  Node* currNode = m_head;

  if (tanksFile.is_open()) {
    while (tanksFile >> identifier >> name >> armament >> nation >> bday) { 
      Tank tank(identifier, name, armament, nation, bday);;

      Node* nextNode = new Node(tank);
      currNode -> m_next = nextNode;
      currNode = nextNode;
    }
  }

  m_tail = currNode;
  tanksFile.close();
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
        //Search through each node for the tank with the target identifier
        if (target == currNode -> m_tank.getIdentifier()){
          //HIT! Return the tank node
          return &currNode -> m_tank;
        } else {
          currNode = currNode -> m_next;
        }
    }
    //Did not find tank
    return nullptr;
}

void TankList::pushHead() {
  Node* pastHead = m_head;
  m_head = pastHead->getNext();
  free(pastHead);
  return;
}

void TankList::freeList() {
    Node* currNode = m_head;
    Node* nextNode = m_head -> m_next;
    do {
        //Free the current node, set current node to next node and set next node to the node after.
        free(currNode);
        currNode = nextNode;
        if (currNode != nullptr) {
            nextNode = currNode -> m_next;
        }
        
    } while (currNode != nullptr); 
    cout << "Successfully cleared tanklist memory." << endl;
}

#endif
