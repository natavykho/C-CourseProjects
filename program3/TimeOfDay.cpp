#include "TimeOfDay.h"

int TimeOfDay::getHH() {
    return HH;
}
int TimeOfDay::getMM() {
    return MM;
}
int TimeOfDay::getSS() {
    return SS;
}
string TimeOfDay::getAmOrPM() {
    return amOrPm;
}
int TimeOfDay::getDay() {
    return day;
}
void TimeOfDay::setHH(int h) {
    HH = h;
}
void TimeOfDay::setMM(int m) {
    MM = m;
}
void TimeOfDay::setSS(int s) {
    SS = s;
}
void TimeOfDay::setAmOrPm(int amPm) {
    amOrPm = amPm;
}
void TimeOfDay::setDay(int d) {
    day = d;
}

//constructor definitions
TimeOfDay::TimeOfDay(){
    HH = 0;
    MM = 0;
    SS = 0;
    amOrPm = "am";
}

TimeOfDay::TimeOfDay(int h, int m, int s, string amPm){
    HH=h;
    MM=m;
    SS=s;
    amOrPm = amPm;
}

TimeOfDay::TimeOfDay(int h, int m, int s, string amPm, int d){
    HH = h;
    MM = m;
    SS = s;
    amOrPm = amPm;
    day = d;
}

// takes in an enumerated value and does the calculation depending on which enum it is
double TimeOfDay::getTimeSinceMidnight(time t){
    if(t == HOURS){
        double theHours = 0;
        theHours = HH + ((double)MM)/60 + ((double)SS)/3600;
        if(amOrPm == "PM"){
            theHours += 12;
        }
        if(HH == 12){
            theHours -= 12;
        }
        return theHours;

    } else if(t == MINUTES){
        double theMins = 0;
        theMins = HH*60 + MM + (SS)/60;
        if(amOrPm == "PM"){
            theMins += 720;
        }
        if(HH == 12){
            theMins -= 720;
        }
        return theMins;

    } else { // if(t == SECONDS){
        double theSec = 0;
        theSec = HH*3600 + MM*60 + SS;
        if(amOrPm == "PM"){
            theSec += 43200;
        }
        if(HH == 12){
            theSec -= 43200;
        }
        return theSec;
    }
}

// to string declarations
string TimeOfDay::toString() {
    string s, m;
    if(SS == 0 || SS < 10){
        s = "0" + to_string(SS);
    } else{
        s = to_string(SS);
    }
    if(MM == 0 || MM < 10){
        m = "0" + to_string(MM);
    } else {
        m = to_string(MM);
    }

    return to_string(HH) + ":" + m + ":" + s + " " + amOrPm;

}


string TimeOfDay::toStringVer2() {
    string s, m, dayStr;
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

    return dayStr + "  " + to_string(HH) + ":" + m + " " + amOrPm;
}


//changes time to military time format
string TimeOfDay::toMilitary() {
    string mil;
    string h, m;
    if(HH == 12){
        HH-=12;
    }
    if(amOrPm == "PM"){
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

// changes time depending on what timezone
string TimeOfDay::timeZone(int n) {
    int h = HH;
    int d = day;
    string ampm;
    ampm = amOrPm;

    h += n;
    if(h >= 24){
        d++;
        h = h-24;
    }

    if(h >= 12){
        if(ampm == "AM"){
            ampm = "PM";
        } else {
            ampm = "AM";
            d++;
        }
        h = h-12;
    }
    TimeOfDay t(h, MM, SS, ampm, d);
    return t.toStringVer2();
}
