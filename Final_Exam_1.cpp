#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//Prototype function incorporated during development of Milestone 3
void printAirportsInRange(int low, int high, map<string, int> aT);

int main() {
    //Start of Milestone 1
    map<string, int> airportTraffic;
    string origin, destination;

    ifstream fin("210-final-1-FA25.txt");
    
    if (fin.is_open()) {
        while(fin >> origin >> destination) {
            airportTraffic[origin]++;
            airportTraffic[destination]++;
        }
    }
    else {
        cout << "Could not open designated text file. Please try again.\n";
    }

    fin.close();

    cout << "All airport traffic counts:\n";
    for (const auto& pair : airportTraffic) {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << endl;
    //End of Milestone 1

    //Start of Milestone 2
    int maxTraffic = 0;

    for (const auto& pair : airportTraffic) {
        if (maxTraffic < pair.second) {
            maxTraffic = pair.second;
        }
    }

    cout << "Busiest airport(s) with count " << maxTraffic << ":\n";
    for (const auto& pair : airportTraffic) {
        if (pair.second == maxTraffic) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    cout << endl;
    //End of Milestone 2

    //Start of Milestone 3
    printAirportsInRange(5, 8, airportTraffic);
    cout << endl;
    printAirportsInRange(9, 12, airportTraffic);
    //End of Milestone 3
}

//Implementation of the prototype function created for Milestone 3
void printAirportsInRange(int low, int high, map<string, int> aT) {
    cout << "Airports with traffic in range [" << low << ", " << high << "]:\n";
    for (const auto& pair : aT) {
        if (pair.second >= low && pair.second <= high) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
}