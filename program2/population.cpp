/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #2: Version C
 Due Date: February 19th, 2020
 Purpose: takes in the values of the population and prints an asterick for each
          1000 people in format of a graph
 ********/
#include <iostream>
#include<fstream>
using namespace std;


int main() {

    //prototype of the function and the declaration of the variables
    string printGraph(int);
    int population1, population2, population3, population4, population5, population6;

    //reads in input from file
    while(!cin.eof()){
        cin >> population1 >> population2 >> population3 >> population4 >> population5 >> population6;
    }

    //prints out the data
    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "1910 " << printGraph(population1) << endl;
    cout << "1930 " << printGraph(population2) << endl;
    cout << "1950 " << printGraph(population3) << endl;
    cout << "1970 " << printGraph(population4) << endl;
    cout << "1990 " << printGraph(population5) << endl;
    cout << "2010 " << printGraph(population6) << endl;

    return 0;
}

//function which uses for loop to print an asterick for every 1000 people
string printGraph(int population){
    string asterick = "";
    for(int i = 0; i < population; i+=1000){
        asterick +="*";
    }
    return asterick;
}