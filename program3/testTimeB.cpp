/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #3: Version B
 Due Date: March 7, 2020
 Purpose: takes in different times and displays them in hours, minutes, and seconds since midnight. It also displays the military time
 ********/

#include <sstream>
#include <string>
#include "TimeOfDay.h"

int main() {
    
    cout << " TIME          HOURS   MINUTES    SECONDS   MILITARY" << endl;

    string value, otherValue;
    while(!cin.eof()){

        //reads in first string (HH:MM:SS) and terminates if it is quit or QUIT
        cin >> value;
        if(value == "quit" || value == "QUIT"){
            exit(0);
        }
        //reads in second string (AM or PM)
        cin >> otherValue;

        //divides string value into SS, MM, and HH int values
        istringstream sstr;
        sstr.str(value);
        int hh, mm, ss;
        char delim;
        sstr >> hh >> delim >> mm >> delim >> ss;

        //creates TimeOfDay object and prints output
        TimeOfDay theTime(hh, mm, ss, otherValue);
        cout << setw(11) << theTime.toString();
        cout << setw(9) << fixed << setprecision(3) << theTime.getTimeSinceMidnight(TimeOfDay::HOURS);
        cout << setw(10) << fixed << setprecision(0) << theTime.getTimeSinceMidnight(TimeOfDay::MINUTES);
        cout << setw(11) << fixed << setprecision(0) <<  theTime.getTimeSinceMidnight(TimeOfDay::SECONDS);
        cout << setw(11) << fixed << setprecision(0) << theTime.toMilitary() << endl;
    }

    return 0;
}