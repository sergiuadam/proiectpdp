#pragma once
#include <vector>
#include <boost/array.hpp>
using namespace std;

class Disponibilitate {
    vector<pair<string, vector<int>>> zile;
public:
    Disponibilitate() {
        vector<int> ore {8, 9, 10, 11, 12, 13, 14};
        vector<string> numeZile {"Luni", "Marti", "Miercuri", "Joi", "Vineri"};

        for(const auto& zi : numeZile) {
            zile.emplace_back(zi, ore);
        }
    };

    bool rezerva(const string& ziua, int ora) {
        for(auto& zi : zile) {
            if(zi.first == ziua) {
                for(auto iter = zi.second.begin(); iter != zi.second.end(); iter++) {
                    if(*iter == ora) {
                        zi.second.erase(iter);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};