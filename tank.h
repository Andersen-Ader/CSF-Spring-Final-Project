#ifndef tank_h
#define tank_h
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

#endif