/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #3: Version A
 Due Date: March 7, 2020
 Purpose: take in a time (Atlanta) and display the time in different time zones.
 ********/


#include <sstream>
#include "TimeOfDay.h"
using namespace std;

int main() {

    int day = 0;
    string dayy, time, amPm;
    while(!cin.eof()){

        //reads in input
        cin >> dayy >> time >> amPm;
        //changes the day to a number so easier to work with
        if(dayy == "Sun"){
            day = 0;
        } else if(dayy == "Mon"){
            day = 1;
        } else if(dayy == "Tue"){
            day = 2;
        } else if(dayy == "Wed"){
            day = 3;
        } else if(dayy == "Thu"){
            day = 4;
        } else if(dayy == "Fri"){
            day = 5;
        } else if (dayy == "Sat"){
            day = 6;
        }

        //divides the first string into integer values for HH, MM, and SS
        istringstream sstr;
        sstr.str(time);
        int hh, mm, ss;
        char delim;
        sstr >> hh >> delim >> mm >> delim >> ss;

        //declare the TimeOfDay object
        TimeOfDay theTime(hh, mm, ss, amPm, day);

        //prints out output
        cout << left << setw(13)  << "Atlanta"   << " " << theTime.timeZone(0) << endl;
        cout << left << setw(13) << "Amsterdam"  << " " << theTime.timeZone(6) << endl;
        cout << left << setw(13) << "Bangkok"  << " " << theTime.timeZone(12)<< endl;
        cout << left << setw(13) << "Bejing"  << " " << theTime.timeZone(13) << endl;
        cout << left << setw(13) << "Halifax"  << " " << theTime.timeZone(1) << endl;
        cout << left << setw(13) << "Jerusalem"  << " " << theTime.timeZone(7) << endl;
        cout << left << setw(13) << "Kiritimati"  << " " << theTime.timeZone(19) << endl;
        cout << left << setw(13) << "Moscow" <<  " " << theTime.timeZone(8) << endl;
        cout << left << setw(13) << "Singapore" <<  " " << theTime.timeZone(13) << endl;
        cout << left << setw(13) << "Warsaw" <<  " " << theTime.timeZone(6) << endl;

    }

    return 0;
}