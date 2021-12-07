/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #5
 Due Date: April 18, 2020
 Purpose: use I/O File operations to write a simple encryption program
 ********/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]) {

    string fname = argv[1];
    string fname2 = argv[2];
    int num = atoi(argv[3]);
    char ch;


    int num2 = num, reverse=0, rem;
    while(num2 != 0){
        rem = num2%10;
        reverse = reverse*10 + rem;
        num2/=10;
    }

    ifstream file1 (fname, ios::in | ios::binary);
    if(!file1.is_open()){
        cout << "Error inn opening file.";
        exit(1);
    }


    ofstream file2 (fname2, ios::out | ios::binary);
    if(!file2.is_open()){
        cout << "Error in opening file.";
        exit(2);
    }

    //file2 << num;
    file2 << (char)num;
    while(file1.get(ch)){
        //!file1.eof()) {
        //file1.get(ch);
            ch = (ch + num + reverse) % 256;
            file2.put(ch);
    }

    file1.close();
    file2.close();

    //cout << endl << "success" << endl;

    return 0;
}