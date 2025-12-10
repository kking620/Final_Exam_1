#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> airportTraffic;
    string origin;
    string destination;

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
}