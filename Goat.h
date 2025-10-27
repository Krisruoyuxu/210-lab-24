// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    //  three  constructors
    Goat(const std::string& name)
    : name(name), age(0), color("Gray") {}

    Goat(const std::string& name, int age)
    : name(name), age(age), color("Gray") {}

    Goat(const std::string& name, int age, const std::string& color)
    : name(name), age(age), color(color) {}

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator<(const Goat& rhs) const {
    if (name < rhs.name) {return true;}
    if (name > rhs.name) {return false;}
    if (age  < rhs.age)  {return true;}
    if (age  > rhs.age)  {return false;}
    return color < rhs.color;
}
};

#endif