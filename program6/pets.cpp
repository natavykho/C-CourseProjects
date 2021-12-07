/********
 Author: Nataliya Vykhovanets
 Program: Program Assignment #6 -  Polymorphic Pets Program
 Due Date: April 25, 2020
 Purpose: uses virtual functions to perform polymorphism
 ********/


#include <iostream>
#include <string>
using namespace std;

// Base class: Pet
class Pet {
private:
    string pname;
public:

    Pet(const string& petName) : pname(petName) {
        pname = petName;
    }
    virtual string name() const {
        return pname;
    }
    virtual string speak() const {
        return "";
    }
    virtual string eat() const {
        return "";
    }
    virtual string sit() const {
        return "";
    }
};


// Derived Class Dog
class Dog : public Pet {
private:
    string name;
public:
    Dog(const string& petName) : Pet(petName) {
        name = petName;
    }
    // New virtual function in the Dog class:
    virtual string sit() const {
        return Pet::name() + " sits boldly";
    }
    virtual string eat() const {
        return Pet::name() + " eats dog food";
    }
    virtual string speak() const { // Override
        return Pet::name() + " says 'Bark!'";
    }
};

// Derived class Cat
class Cat : public Pet {
private:
    string name;
public:
    Cat (const string& petName) : Pet(petName){
        name = petName;
    }
    virtual string speak() const {
        return Pet::name() + " says 'Meow!'";
    }
    virtual string eat() const {
        return Pet::name() + " eats cat food";
    }
    virtual string sit() const {
        return Pet::name() + " sits proudly";
    }

};

// Derived class Poodle (derived from Dog class)
class Poodle : public Dog {
private:
    string name;
public:
    Poodle (const string& petName) : Dog(petName){
        name = petName;
    }
    virtual string speak() const {
        return Pet::name() + " says 'Bark!'";
    }
    virtual string sit() const {
        return Pet::name() + " sits precisely";
    }
    virtual string eat() const {
        return Pet::name() + " eats dog food";
    }
};


#define MAXPETS 100

    int main() {

        // variables for numbers of pets, pet type, pet name, and which pet to select
        int numPets;
        string petType;
        string name;
        int index;

        cin >> numPets;
        Pet * pet[MAXPETS];

        //input into array
        for (int i = 0; i < numPets; i++){
            cin >> petType >> name;
            if (petType == "dog"){
                pet[i] = new Dog(name);
            } else if (petType == "cat"){
                pet[i] = new Cat(name);
            } else if (petType == "poodle"){
                pet[i] = new Poodle(name);
            } else if (petType == "pet"){
                pet[i] = new Pet(name);
            }
        }

        // read in which pet to select and print out functions until invalid input
        cin >> index;
        while (index >=1 && index <= numPets){
            cout << pet[index-1]-> speak() << endl;
            cout << pet[index-1]-> eat() << endl;
            cout << pet[index-1]-> sit() << endl;
            cin >> index;
        }

        //delete allocated objects
        for (int i = 0; i < numPets; i++){
            delete pet[i];
        }

    return 0;
}