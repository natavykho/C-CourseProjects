#include "TimeOfDay.h"

//constructor definitions
TimeOfDay::TimeOfDay(){
    HH = 0;
    MM = 0;
    SS = 0;
    amOrPm = 0;
}

TimeOfDay::TimeOfDay(int h, int m, int s, int amPm, int d){
    HH = h;
    MM = m;
    SS = s;
    amOrPm = amPm;
    day = d;
}


// overloads the + operator to add n seconds to time and returns new time
TimeOfDay TimeOfDay::operator+(int n) {
    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;

    if(h == 12 && ampm == 0){
        h = 0;
    }
    s+=n;
    while (s >= 60){
        m++;
        s-=60;
    }
    while (m >= 60){
        h+=1;
        m-=60;
    }
    while (h > 24){
        d++;
        h -=24;
    }
    if(h >= 12){
    //if(HH == 12 && h > HH && n >= (60-MM)) {//h >= 12 && n > (60-MM)) {

        if (ampm == 0) {  //0 = am
            ampm = 1;
        } else {
            ampm = 0;
            d++;
        }

    }

    if(h > 12) {
        h -= 12;
    }
    if(h == 0){
        h = 12;
    }

    if(d > 6){
        d = d%7;
    }
    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overloads the + operator to add n hours ( or n*60 minutes) to time.
// so if n = 1.5, add 1.5 hours (90 minutes) to time and return new time
TimeOfDay TimeOfDay::operator+(double n) {
    int h = HH, m = MM, s = SS, d = day;
    int ampm = amOrPm;

    if(h == 12 && ampm == 0){
        h = 0;
    }

    m += int(n*60);

    while (s >= 60){
        m++;
        s-=60;
    }
    while (m >= 60){
        h+=1;
        m-=60;
    }
    while (h > 24){
        d++;
        h -=24;
    }
    //if(h >=12){
    if(HH == 12 && h >= 12) {
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
            d++;
        }
        if(h > 12) {
            h -= 12;
        }
    }

    if (h >= 12) {
        h -= 12;
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
        }
    }

    if(h ==0){
        h = 12;
    }

    if(d > 6){
        d = d%7;
    }
    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overloads the * operator to add n minutes to time and returns new time
TimeOfDay TimeOfDay::operator*(int n) {
    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;

    if ( h == 12 && ampm == 0){
        h = 0;
    }
    m +=n;
    while (m >= 60){
        h+=1;
        m-=60;
    }
    while (h >= 24){
        d++;
        h -=24;
    }
    if(h >=12){
    //if(HH == 12 && h > HH) {
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
            d++;
        }

    }
    if(h > 12) {
        h -= 12;
    }
    if (h == 0){
        h = 12;
    }

    if(d > 6){
        d = d%7;
    }
    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overloads the / operator to add n number of hours to time, and returns new time
TimeOfDay TimeOfDay::operator/(int n) {
    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;
    if(h == 12 && ampm == 0){
        h =0;
    }

    h+=n;
    while (h > 24){
        d++;
        h -=24;
    }
    if(h >=12){
    //if(HH == 12 && h > HH) {
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
            d++;
        }
    }

    if(h > 12) {
        h -= 12;
    }
    if (h == 0){
        h = 12;
    }

    if(d > 6){
        d = d%7;
    }

    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overloads the - operator to subtract n seconds from time and returns new time
TimeOfDay TimeOfDay::operator-(int n) {

    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;

/*
    if (n%43200 == 0) {
        while(n != 0){

            if(ampm == 0){
                ampm = 1;
                if(n >43200){
                    d--;
                }
            } else {
                ampm = 0;
            }
            n-=43200;
        }
    }
*/


    if(h == 12 && ampm == 0){
        h = 0;
    }

    s -= n;

    while(s < 0){
        m-=1;
        s += 60;
    }

    while (m < 0){
        h -=1;
        m += 60;

    }

    if(HH == 12 && h < HH && h >= 0 && n > SS){
        if(ampm == 0){
            ampm = 1;
        } else {
            ampm = 0;
        }
    }
    while (h < 0) {
        d--;
        h += 24;
    }
    if (h >= 12) {
        h -= 12;
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
        }
    }

    if (h == 0) {
        h = 12;
    }
    while (d < 0) {
        d += 7;
    }
    if(HH == 0){
        HH = 12;
    }

    TimeOfDay t(h, m, s, ampm, d);
    return t;

}


// overload - operator to work with doubles. This multiplies n by 60 to get
// number of minutes and subtracts from time. For example, if n = 1.5, you
// are subtracting 1.5 hours (90 minutes)
// returns the new time
TimeOfDay TimeOfDay::operator-(double n){
    int h = HH, m = MM, s = SS, d = day;
    int ampm = amOrPm;

    if(h == 12 && ampm == 0){
        h = 0;
    }

    m -= int(n*60);

    while(s < 0){
        m-=1;
        s +=60;
    }

    while (m < 0){
        h -=1;
        m += 60;

        if(HH == 12 && h < HH && h >= 0){
            if(ampm == 0){
                ampm = 1;
            } else {
                ampm = 0;
            }
        }
        while (h < 0) {
            d--;
            h += 24;
        }
        if (h >= 12) {
            h -= 12;
            if (ampm == 0) {
                ampm = 1;
            } else {
                ampm = 0;
            }
        }
    }

    if (h == 0) {
        h = 12;
    }

    while (d < 0) {
        d += 7;
    }

    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overload & operator to subtract n number of minutes from time and return new time
TimeOfDay TimeOfDay::operator&(int n){
    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;

    if(h == 12 && ampm == 0){
        h = 0;
    }

    m-=n;

    while (m < 0){
        h -=1;
        m += 60;
    }

    if(HH == 12 && h < HH && h >= 0 && n > MM){ // && HH != h
        if(ampm == 0){
            ampm = 1;
        } else {
            ampm = 0;
        }
    }

    while (h < 0){
        d--;
        h+=24;
    }

    if(h >= 12){
        h-=12;
        if(ampm == 0){
            ampm = 1;
        } else {
            ampm = 0;
        }
    }

    if(h == 0){
        h = 12;
    }

    while(d < 0){
        d +=7;
    }


    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overload ^ to subtract n number of Hours from time and return new time
TimeOfDay TimeOfDay::operator^(int n) {
    int s = SS, m = MM, h = HH, d = day;
    int ampm = amOrPm;

    if(h == 12 && ampm == 0){
        h = 0;
    }

    h -= n;
    if(HH == 12 && h < HH && h >= 0){
        if(ampm == 0){
            ampm = 1;
        } else {
            ampm = 0;
        }
    }
    while (h < 0) {
        d--;
        h += 24;
    }
    if (h >= 12) {
        h -= 12;
        if (ampm == 0) {
            ampm = 1;
        } else {
            ampm = 0;
        }
    }
    if (h == 0) {
        h = 12;
    }

    while (d < 0) {
        d += 7;
    }

    TimeOfDay t(h, m, s, ampm, d);
    return t;
}


// overload ! operator to return military time
string TimeOfDay::operator!() {
    string mil;
    string h, m;
    if(HH == 12){
        HH-=12;
    }
    if(amOrPm == 1){  //if amOrPm is pm
        HH += 12;
    }
    if(HH < 10){
        h = "0" + to_string(HH);
    } else {
        h = to_string(HH);
    }

    if(MM == 0 || MM < 10){
        m = "0" + to_string(MM);
    } else {
        m = to_string(MM);
    }

    mil += h + m;
    return mil;
}


// overloading subscript operator which works as getter/setter for instance variables
// these variables are SS, MM, HH, day, amOrPm
int& TimeOfDay::operator[](int n) {
    switch(n){
        case 0:
            return SS;
            break;
        case 1:
            return MM;
            break;
        case 2:
            return HH;
            break;
        case 3:
            return day;
            break;
        case 4:
            return amOrPm;
            break;
    }
}


// toString method to print out in DAY HH:MM:SS AM/PM format
string TimeOfDay::toString() {
    string s, m, dayStr, ampmString;
    if(SS == 0 || SS < 10){
        s = "0" + to_string(SS);
    } else {
        s = to_string(SS);
    }
    if(MM == 0 || MM < 10){
        m = "0" + to_string(MM);
    } else {
        m = to_string(MM);
    }

    if(amOrPm == 0){
        ampmString = "AM";
    } else {
        ampmString = "PM";
    }

    if(day == 0){
        dayStr = "Sun";
    } else if(day == 1){
        dayStr = "Mon";
    } else if(day == 2){
        dayStr = "Tue";
    } else if(day == 3){
        dayStr = "Wed";
    } else if(day == 4){
        dayStr = "Thu";
    } else if(day == 5){
        dayStr = "Fri";
    } else if(day == 6){
        dayStr = "Sat";
    }

    return dayStr + " " + to_string(HH) + ":" + m + ":" + s + " " + ampmString;
}