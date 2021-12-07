#include <iostream>
#include <iomanip>
using namespace std;

class TimeOfDay{

private:
    //variables
    int HH, MM, SS;
    int amOrPm, day;
    int hsm, msm, ssm;


public:
//constructor
    TimeOfDay();
    TimeOfDay(int HH, int MM, int SS, int amOrPm, int day);
//methods
    TimeOfDay operator +(int n);
    TimeOfDay operator +(double n);
    TimeOfDay operator *(int n);
    TimeOfDay operator /(int n);
    TimeOfDay operator -(int n);
    TimeOfDay operator -(double n);
    TimeOfDay operator &(int n);
    TimeOfDay operator ^(int n);
    int& operator [](int n);
    string operator !();
    string toString();


};