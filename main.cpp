#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>        
#include <limits>    
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
int g_names_cnt = 0;  // Number of valid names read
int g_colors_cnt = 0; // Number of valid colors read

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

    list<Goat> trip;                                          

    


                                          
    return 0;
}

int select_goat(list<Goat> trip){
    if (trip.empty()) { cout << "Trip is empty." << endl; return -1; }
    cout << "Select goat to delete:" << endl;
    int idx = 1;
    for (const auto& g : trip) {
        cout << "[" << idx++ << "] "
             << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
    cout << "Choice --> ";
    int choice;
    if (!(cin >> choice)) {
        cout << "Invalid input." << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    if (choice < 1 || choice >= idx) {
        cout << "Out of range." << endl;
        return -1;
    }
    return choice;
}

void delete_goat(list<Goat> &trip){

}

void add_goat(list<Goat> &trip, string [], string []){

}

void display_trip(list<Goat> trip){

}

int main_menu() {
    while (true) {                                                   
        cout << "\n*** GOAT MANAGER 3001 ***\n"
             << "[1] Add a goat\n"
             << "[2] Delete a goat\n"
             << "[3] List goats\n"
             << "[4] Quit\n"
             << "Choice --> ";
        int c;  //the user's input
        if (cin >> c && 1 <= c && c <= 4) return c;   // Read an integer and check its range; return if valid
        cout << "Invalid input. Please enter 1-4.\n";
        cin.clear();  // Clear the error flags 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the rest of the current line to avoid infinite loops
    }
}
