// TimeDate.cpp
// Author: Ben Foltz
#include <iostream>

using namespace std;

class TimeDate {
    private:
        int hour, minute, day;  //24 hr, min, day of the month
        string month;           //Jan, Feb, ... Nov, Dec
    public:
        TimeDate(int hour, int minute, int day, string month) : //constructor
            hour(hour),                                         //member initialization list
            minute(minute),
            day(day),
            month(month) {};                                    //empty constructor
        string getTimeDate() {                                  //Prints out object
            //Convert hour to string
            string print_hour = to_string(hour);
            //Check if am or pm
            string am_pm = (hour < 12 ? "am" : "pm");
            if (hour == 0) {
                print_hour = "12";
            }
            if (hour > 12) {
                print_hour = to_string(hour - 12);
            }
            //return date information as a string
            return month + " " + to_string(day) + " at " + print_hour + ":" + (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
        }
};

class Event {
    private:
        TimeDate start_time, end_time; //Time when Event starts and ends
        string description;            //Description of event
    public:
        Event(int start_hour, int start_minute, int start_day, string start_month, int end_hour, int end_minute, int end_day, string end_month, string description) :   //constructor
                start_time(start_hour, start_minute, start_day, start_month),                                                              //member initialization list
                end_time(end_hour, end_minute, end_day, end_month),
                description(description) {};                                                                                                                            //empty constructor
        string getEvent() {
            //return event information as a string
            return description + " starts at " + start_time.getTimeDate() + ", ends at " + end_time.getTimeDate();
        }
};

int main() {
    //Create an event
    Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.","My Birthday Party") ;
    //Print out party object
    cout << party.getEvent() << endl ;

    //Create an event
    Event concert(19, 30, 24, "Oct.", 0, 0, 24, "Oct.", "Hail the Sun concert");
    //Print out concert object
    cout << "The " << concert.getEvent() << endl ;
}