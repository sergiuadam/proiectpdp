#pragma once
#include "Disponibilitate.h"
#include "Clasa.h"
#include "Profesor.h"
#include <vector>
#include <iostream>
using namespace std;

class Materie {
    string name;
    vector<Clasa *> clase;
    vector<Profesor *> profesori;
    int aparitiiPeSaptamana;

public:
    Materie() {

    }
};