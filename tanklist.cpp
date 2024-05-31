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
};

class TankList {
    private:
        Node* m_head;
        Node* m_tail;
        bool SearchFor(const Tank target);

    public:
        TankList();
        TankList(const Tank tankarray[], int size);
        Node* getHead();
        Node* getTail();
        Node* getNext();
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