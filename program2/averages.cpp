/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #2: Version A
 Due Date: February 19th, 2020
 Purpose: take in a series of test scores, making sure the score is
 between 0 and 100. then computes averages of each letter grade
 ********/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    // declaring variables
    int value = 0;
    int sumA = 0, sumB = 0, sumC = 0, sumD = 0, sumF = 0;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0, countInvalid = 0;


    //taking in input from file and storing all letter grades together and keeps track of how many there are
    while (!cin.eof()) {
        cin >> value;
//        while (in >> value) {
            //cin >>value;
            if (value >= 90 && value <= 100) {
                sumA += value;
                countA++;
            } else if (value >= 80 && value <= 89) {
                sumB += value;
                countB++;
            } else if (value >= 70 && value <= 79) {
                sumC += value;
                countC++;
            } else if (value >= 60 && value <= 69) {
                sumD += value;
                countD++;
            } else if (value >= 0 && value <= 59) {
                sumF += value;
                countF++;
            } else {
                countInvalid ++;
            }
        }

        // prints out the average of each letter grade and if none, prints N/A
        if (countA == 0) {
            cout << "A N/A" << endl;
        } else {
            cout << "A " << fixed << setprecision(2) << (double)sumA / countA << endl;
        }

        if (countB == 0) {
            cout << "B N/A" << endl;
        } else {
            cout << "B " << fixed << setprecision(2) << (double)sumB / countB << endl;
        }

        if (countC == 0) {
            cout << "C N/A" << endl;
        } else {
            cout << "C " << fixed << setprecision(2) << (double)sumC / countC << endl;
        }

        if (countD == 0) {
            cout << "D N/A" << endl;
        } else {
            cout << "D " << fixed << setprecision(2) << (double)sumD / countD << endl;
        }

        if (countF == 0) {
            cout << "F N/A" << endl;
        } else {
            cout << "F " << fixed << setprecision(2) << (double)sumF / countF << endl;
        }

        //prints out the count of invalid scores
        cout << "invalid " << countInvalid << endl;

        return 0;
    }
