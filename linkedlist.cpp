#include <string>
#include "tank.cpp"

using namespace std;

class LinkedList {
    private:
        Tank* head;
        Tank* tail;

    public:
        void pushBack(const Tank newItem);
        void pushFront(const Tank newItem);
        void insertAfter(const Tank target);
        void remove(const Tank target);
        void SearchFor(const Tank target);
};