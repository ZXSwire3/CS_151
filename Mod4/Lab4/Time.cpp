// Time.cpp
// Author: Ben Foltz
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    //Instantiate time variable
    time_t now = time(NULL);

    //Create array for days of the week
    string daysOfTheWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    //Create array for months of the year
    string monthsOfTheYear[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //Instantiate local time structure
    tm *local = localtime(&now);

    //Print out today's date using local variable
    cout << "Here is today's date in various formats:" << endl;
    cout << 1 + local->tm_mon << "/" << local->tm_mday << "/" << -100 + local->tm_year << endl
         << monthsOfTheYear[local->tm_mon] << " " << local->tm_mday << ", " << 1900 + local->tm_year << endl
         << local->tm_mday << "-" << monthsOfTheYear[local->tm_mon].substr(0,3) << "-" << 1900 + local->tm_year << endl << endl;

    //Instantiate char array
    char time[50];
    //Instantiate time string
    string timeString;

    //Print out today's date using strftime function
    cout << "Same information using the strftime function:" << endl;
    strftime(time, sizeof(time), "%D", local);
    timeString = time;
    cout << timeString.substr(1, timeString.size()-1) << endl;
    strftime(time, sizeof(time), "%B %e, %Y", local);
    cout << time << endl;
    strftime(time, sizeof(time), "%e-%b-%Y", local);
    cout << time << endl << endl;

    //Print out the current time in two different formats using strftime
    cout << "Here's the current time in two formats:" << endl;
    strftime(time, sizeof(time), "%H:%M", local);
    cout << time << endl;
    strftime(time, sizeof(time), "%I:%M%p", local);
    timeString = time;
    //isolate AM or PM
    string dayOrNight = timeString.substr(timeString.size()-2, 2);
    //make AM or PM lowercase
    dayOrNight[0] = tolower(dayOrNight[0]);
    dayOrNight[1] = tolower(dayOrNight[1]);
    cout << timeString.substr(1, timeString.size()-3) << dayOrNight << endl << endl;

    //Instantiate a new tm variable
    tm event;
    //Set time information for the new event
    event.tm_year = 2001 - 1900;
    event.tm_mon = 11;
    event.tm_wday = 1;
    event.tm_mday = 3;
    event.tm_hour = 0;
    event.tm_min = 0;
    event.tm_sec = 0;
    event.tm_isdst = 0;
    //Initialize a new time variable at event time
    time_t time_of_event = mktime(&event);

    //Use strftime to write out the day of the week and day of the year of event
    strftime(time, sizeof(time), "%A, day of the year: %j", &event);

    //Calculate a week in seconds
    int secondsInAWeek = 60*60*24*7;
    //Initialize a new time variable a week before event
    time_t weekBefore = time_of_event - secondsInAWeek;

    //Print out information about the big event
    cout << "The big event occurred on " << ctime(&time_of_event)
         << "and occurred " << time_of_event << " seconds after epoch!" << endl
         << "There are " << secondsInAWeek << " seconds in a week" << endl
         << "The week before was " << ctime(&weekBefore)
         << "The event was on a " << time;
}