/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #2: Version C
 Due Date: March 7, 2020
 Purpose: Take in different times and display them in hours, minutes, and seconds since midnight.
 ********/

#include <sstream>
#include <string>
#include "TimeOfDay.h"

int main() {


    cout << " TIME          HOURS   MINUTES    SECONDS" << endl;
    string value, otherValue;

    //only loops if value is not quit or QUIT
    while(!cin.eof()){

        //reads in first string (the HH:MM:SS) and if it is quit or QUIT, terminates
        cin >> value;
        if(value == "quit" || value == "QUIT"){
            exit(0);
        }
        //reads in second input (AM or PM) if first input was not quit or QUIT
        cin >> otherValue;

        //divides the string input into int HH, MM, and SS values to work with
        istringstream sstr;
        sstr.str(value);
        int hh, mm, ss;
        char delim;
        sstr >> hh >> delim >> mm >> delim >> ss;

        //creates TimeOFDay object and prints output
        TimeOfDay theTime(hh, mm, ss, otherValue);
        cout << setw(11) << theTime.toString();
        cout << setw(9) << fixed << setprecision(3) << theTime.getTimeSinceMidnight(TimeOfDay::HOURS);
        cout << setw(10) << fixed << setprecision(0) << theTime.getTimeSinceMidnight(TimeOfDay::MINUTES);
        cout << setw(11) << fixed << setprecision(0) <<  theTime.getTimeSinceMidnight(TimeOfDay::SECONDS) << endl;

    }

    return 0;
}