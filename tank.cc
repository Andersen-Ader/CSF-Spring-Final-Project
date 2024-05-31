#include <iostream>
#include <string>

using namespace std;

class Tank {
    private:
        string m_name;
        string m_identifier;
        string m_armament; 
        string m_nation;
        string m_bday;
        
    public:
        Tank(string identifier, string name, string armament, string nation, string bday);
        void print();
        string getIdentifier();
        string getName();
        string getArmament();
        string getNation();
        string getBday();
};

Tank::Tank(string identifier, string name, string armament, string nation, string bday) {
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

