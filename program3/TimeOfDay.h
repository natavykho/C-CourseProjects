#include <iostream>
#include <iomanip>
using namespace std;

class TimeOfDay{

private:
    //variables
    int HH, MM, SS;
    string amOrPm;
    int day;

public:
    enum time {HOURS, MINUTES, SECONDS};

public:
//constructor
    TimeOfDay();
    TimeOfDay(int HH, int MM, int SS, string amOrPm);
    TimeOfDay(int HH, int MM, int SS, string amOrPm, int day);

//methods
    double getTimeSinceMidnight(time t);
    string toString();
    string toStringVer2();
    int getHH();
    int getMM();
    int getSS();
    string getAmOrPM();
    int getDay();
    void setHH(int h);
    void setMM(int m);
    void setSS(int s);
    void setAmOrPm(int amPm);
    void setDay(int d);
    string toMilitary();
    string timeZone(int n);

};