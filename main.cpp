#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Doctori{
    string doc_name;
    string specializare_name_doc;
};
struct Problema {
    string problema_name;
    string specializare_name_prob;
};
int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    bool status;

    vector<Doctori>doc;
    vector<Problema>prob;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        prob.push_back({ name,speciality });
        cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doc.push_back({ name,speciality });
        cout << name << ' ' << speciality << '\n';
    }
    for (const auto& p : prob) {
        bool status = false;
        for (const auto& d :doc) {
            if (p.specializare_name_prob == d.specializare_name_doc) {
                status = true;
                break;
            }
            
        }
        if (status) {
            cout << p.problema_name << " Acceptat" << endl;
        }
        else {
            cout << p.problema_name << " Respins" << endl;
        }
      
    }
    return 0;
}