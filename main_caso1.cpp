#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Funciones para "compare_triplets"

// Funcion 1: utiliza ciclo for y 2 if por cada iteracion
vector<int> compareTriplets_1(vector<int> a, vector<int> b) {
    vector<int> res = {0,0};
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            res[0]++;
        }
        else if (a[i] < b[i]) {
            res[1]++;
        }
    }
    return res;
}

// Funcion 2: elimina ciclo for y hace 6 ifs sin iterar
vector<int> compareTriplets_2(vector<int> a, vector<int> b) {
    vector<int> res = {0,0};
    res[0] += (a[0]>b[0]?1:0) + (a[1]>b[1]?1:0) + (a[2]>b[2]?1:0);
    res[1] += (a[0]<b[0]?1:0) + (a[1]<b[1]?1:0) + (a[2]<b[2]?1:0);
}


// Funciones para "time_conversion"

// Funcion 1:
string timeConversion_1(string input) {
    // am indica si es AM o PM. true = am, false = PM
    string res = "";
    bool am = (input.compare(8,1,"A") == 0);
    string soloDigitos = input.substr(0, 8);
    string partesDigitos[] = {
        soloDigitos.substr(0,2),
        soloDigitos.substr(3,2),
        soloDigitos.substr(6,2),
    };
    int partesNumeros[] = {
        stoi(partesDigitos[0]),
        stoi(partesDigitos[1]),
        stoi(partesDigitos[2])
    };

    if (am) {
        // si son las 12 AM se entiende como medianoche o las 0 en formato 24h
        if (partesNumeros[0] == 12) {
            res += "00";
        }
    }


    //std::cout << partesNumeros[0] << endl << partesNumeros[1] << endl << partesNumeros[2] << endl << endl;
}

int main() {
    timeConversion_1("03:40:23PM");
    return 0;
}