#include <stdio.h>
#include <iostream>
#include <vector>
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


int main() {
    return 0;
}