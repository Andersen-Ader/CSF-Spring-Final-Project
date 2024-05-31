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
        void SearchFor(const Tank target);
};

TankList::TankList() {
    m_head = nullptr;
    m_tail = nullptr;
}

TankList::TankList(const Tank tankarray[], int size) {
    m_head = &Node(tankarray[0]);

    for (int i = 1; i < size-1; i++) {
        
    }
    m_tail = &Node(tankarray[size-1]);
}