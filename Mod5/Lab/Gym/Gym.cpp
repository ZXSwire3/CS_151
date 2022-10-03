// Gym.cpp
// Author: Ben Foltz
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Membership monthly rates
const double BASIC_RATE = 28.50,
             PREMIUM_RATE = 60.00;

//Member structure
struct Member {
    static int last_id,         //count all visits from members
               active_member,   //total members active in my gym
               total_visits;    //id assigned to newest member

    int id;                     //id of this member
    string name;                // name of this member
    char type;                  //type of member (B = basic, P = premium)
    int visits;                 //visits by this member

    //Member constructor
    Member(string name, char type) {
        this->name = name;
        this->type = type;
        visits = 0;
        active_member++;
        id = last_id++;
    }

    //Member destructor
    ~Member() {
        active_member--;
    }
};

//Define static variables
int Member::total_visits = 0;
int Member::active_member = 0;
int Member::last_id = 100000;

//Visit prototype
void visit(Member &);

int main() {
    //Vector of pointers to Member structure
    vector<Member *> members;

    //Add Members to the vector
    members.push_back(new Member("Oprah Winfrey", 'P'));
    members.push_back(new Member("Fluffy Iglesias", 'P'));
    members.push_back(new Member("Charlie Sheen", 'B'));
    members.push_back(new Member("Bill Gates", 'B'));

    //Delete the pointer to Charlie's Member object
    delete members.at(2);
    //Delete Charlie's Member from the heap
    members.erase(members.begin() + 2);

    //Generate new random number on each run
    unsigned int seed = time(nullptr);
    srand(seed);
    //max value that random values can be
    int max = 20;
    int min = 5;
    //random values
    int random;

    //Loop through all members
    for (int i = 0; i < members.size(); i++) {
        //generate random number from 0 to RAND_MAX
        random = (rand() % max) + min;
        //make 'i' member visit the gym "random" number of times
        for (int j = 0; j < random; j++) {
            //Increment visits
            visit(*members.at(i));
        }
    }

    //Print out Member information
    cout << fixed << setprecision(2);
    cout << right << setw(4) << "ID" << left << setw(8) << "" << "Member" << left << setw(7) << "" << "Visits" << left << setw(6) << "" << "Type" << left << setw(6) << "" << "Rate" << endl
         << "-----------------------------------------------------" << endl;
    for (int i = 0; i < members.size(); i++) {
        double rate;
        if (members.at(i)->type == 'B') {
            rate = BASIC_RATE;
        } else {
            rate = PREMIUM_RATE;
        }
        cout << left << setw(8) << members.at(i)->id << left << setw(18) << members.at(i)->name << right << setw(3) << members.at(i)->visits << left << setw(9) << "" << left << setw(8) << members.at(i)->type << "$" << rate << endl;
    }

    cout << "-----------------------------------------------------" << endl
         << "Total Visits: " << Member::total_visits << endl
         << "Active Members: " << Member::active_member << endl;
}

//Visit function
void visit(Member &member) {
    member.visits++;
    Member::total_visits++;
}