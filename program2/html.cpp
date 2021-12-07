/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #2: Version B
 Due Date: February 19th, 2020
 Purpose: prompts user to enter inforamtion to print into an html file which it creates
 ********/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // declares variables
    string name, description, webTitle;
    ofstream file;
    file.open("About Me.html");

    // prompts user to enter information
    cout << "Enter Your Name: " << endl;
    getline(cin,name);
    cout << "Describe yourself:" << endl;
    getline(cin, description);
    cout << "Enter a title for your web page: " << endl;
    getline(cin, webTitle);


    // prints the information in HTML format into a file
    file << "<html>" << endl;
    file << "<head>" << endl;
    file << "  <title>" << webTitle << "</title>" << endl;
    file << "</head>" << endl;
    file << "<body>" << endl;
    file << "  <center>" << endl;
    file << "  <h1>" << name << "</h1>" << endl;
    file << "  </center>" << endl;
    file << "  <hr>" << endl;
    file << "  " << description << endl;
    file << "  <hr>" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;

    return 0;
}