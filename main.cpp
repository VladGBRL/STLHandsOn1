#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Doctori {
    string doc_name;
    string specializare_name_doc;
};

struct Problema {
    string problema_name;
    string specializare_name_prob;
    int durata;
    int prioritate;

    bool operator<(const Problema& other) const {
        return prioritate < other.prioritate;
    }
};

int main() {
    ifstream inFile("input.txt");

    int no_problems, no_doctors, durata, prioritate;
    string name, speciality;
    priority_queue<Problema> pq;

    vector<Doctori> doc;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++) {
        inFile >> name >> speciality >> durata >> prioritate;
        cout << name << ' ' << speciality << ' ' << durata << ' ' << prioritate << '\n';
        pq.push({ name, speciality, durata, prioritate });
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++) {
        inFile >> name >> speciality;
        doc.push_back({ name, speciality });
        cout << name << ' ' << speciality << '\n';
    }

    map<string, pair<int, vector<string>>> time;
    for (const auto& d : doc) {
        time[d.doc_name] = { 8, {} }; 
    }

    while (!pq.empty()) {
        Problema p = pq.top();
        pq.pop();
        bool status = false;

        for (auto& d : doc) {
            if (p.specializare_name_prob == d.specializare_name_doc) {
                if (time[d.doc_name].first >= p.durata) {
                 
                    time[d.doc_name].first -= p.durata;
                    time[d.doc_name].second.push_back(p.problema_name);
                    status = true;
                    break;
                }
            }
        }
    }

    for (const auto& d : time) {
        if(d.second.second.size()!=0)
            cout << d.first << " " << d.second.second.size() << " ";  
        for (const auto& problema : d.second.second) {
            cout << problema << " "; 
        }
        cout << endl;
    }

    return 0;
}
