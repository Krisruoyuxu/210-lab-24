#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    //==================test================================
    Goat g1("Vida");                    
    Goat g2("Nola", 7);                 
    Goat g3("Todd", 12, "Red");         

    cout << g1.get_name() << " (" << g1.get_age() << ", " << g1.get_color() << ")" <<endl;
    cout << g2.get_name() << " (" << g2.get_age() << ", " << g2.get_color() << ")" <<endl;
    cout << g3.get_name() << " (" << g3.get_age() << ", " << g3.get_color() << ")" <<endl;

    return 0;
}

