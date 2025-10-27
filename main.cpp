#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>        
#include <limits>    
#include <ctime>
#include <set>   
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
int g_names_cnt = 0;  // Number of valid names read
int g_colors_cnt = 0; // Number of valid colors read

//  replace list<Goat> with set<Goat>
int select_goat(set<Goat> trip);                    
void delete_goat(set<Goat> &trip);                   
void add_goat(set<Goat> &trip, string [], string []); 
void display_trip(set<Goat> trip);     
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin && i < SZ_NAMES && (fin >> names[i])) ++i;   // bounded read into names[]; stops on EOF/error and prevents overflow
    fin.close();
    g_names_cnt = i; 

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];

    i = 0;
    while (fin1 && i < SZ_COLORS && (fin1 >> colors[i])) ++i;;   // bounded read into color[]; stops on EOF/error and prevents overflow
    fin1.close();
    g_colors_cnt = i;  

    if (g_names_cnt == 0 || g_colors_cnt == 0) {     // Ensure the name/color pools are non-empty before random selection;
        cout << "Failed to load names.txt or colors.txt" << endl;
        return 1;
    }

    set<Goat> trip;                                             

    again = true;
    while (again) {
        switch (main_menu()) {
            case 1: add_goat(trip, names, colors); break;
            case 2: delete_goat(trip); break;
            case 3: display_trip(trip); break;
            case 4: cout << "Bye!" << endl; again = false; break;
        }
    }
                                    
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
    int idx = select_goat(trip);                 // Get an index start from 1
    if (idx == -1) return;                       // -1 means cancel/invalid

    auto it = trip.begin();                      // iterator to the first goat
    advance(it, idx - 1);                        // move iterator to the selected position

    // Show which goat is being removed
    cout << "Deleted: " << it->get_name() << " (" << it->get_age()
         << ", " << it->get_color() << ")\n";

    trip.erase(it);                              // Erase the selected goat from the list
}

void add_goat(list<Goat> &trip, string names[], string colors[]){
    int ni = rand() % g_names_cnt;               // random index into names pool
    int ci = rand() % g_colors_cnt;              // random index into colors pool
    int age = rand() % (MAX_AGE + 1);            // random age in [0, MAX_AGE]

    Goat g(names[ni], age, colors[ci]);          
    trip.push_back(g);                           // append to the end of the list

    // confirm to the user what was added
    cout << "Added: " << g.get_name() << " (" << g.get_age()
         << ", " << g.get_color() << ")\n";
}

void display_trip(list<Goat> trip){
    if (trip.empty()) {                          // Handle empty list
        cout << "(no goats yet)\n";
        return;
    }
    int i = 1;                                   // 1 based numbering for display
    for (const auto& g : trip) {                 // Iterate in order
        cout << "[" << i++ << "] "
             << g.get_name() << " (" << g.get_age()
             << ", " << g.get_color() << ")\n";
    }
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
