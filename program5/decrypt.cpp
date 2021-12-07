/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #5
 Due Date: April 18, 2020
 Purpose: uses I/O File operations to write a decryption program
 ********/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {

    string fname = argv[1];
    string fname2 = argv[2];
    char key;
    char ch;

    ifstream file1 (fname, ios::in |ios::binary);
    if(!file1.is_open()){
        cout << "Error in opening file!";
        exit(1);
    }

    ofstream file2 (fname2, ios::out | ios::binary);
    if(!file2.is_open()){
        cout << "Error in opening file!";
        exit(2);
    }

    file1.get(key);
    unsigned char theKey = static_cast<unsigned char>(key);

    int theNum = (int)theKey;
    int reverse=0, rem;
    while(theNum != 0){
        rem = theNum%10;
        reverse = reverse*10 + rem;
        theNum/=10;
    }
    //cout << (int)theKey << endl;
    //cout << reverse << endl;

    while(file1.get(ch)){// !file1.eof()){
        
        ch = (ch - theKey - reverse) % 256;
        file2.put(ch);
        

    }

    file1.close();
    file2.close();


}