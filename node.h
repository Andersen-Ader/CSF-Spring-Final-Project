#ifndef node_h
#define node_h

#include "tank.h"

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



#endif