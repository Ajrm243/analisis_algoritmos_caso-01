#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
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

// Funcion 1: detectar AM o PM y restar a la hora si es PM
// es muy tedioso revisar todos los diferentes casos de esta manera
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

    if (!am) {
        // si es PM hay que hacer cambios
        // las 12 PM corresponde al mediodía, sigue siendo las 12 en formato 24h
        if (partesNumeros[0] == 12) {
            res += "12";
        } else {
            // de 1 a 11 PM se suma 12 a la hora
            std::stringstream horaTemp;
            // Hace que numeros como 1 o 3 se completen como 01 o 03
            horaTemp << std::setw(2) << std::setfill('0') << partesNumeros[0] + 12;
            res += horaTemp.str();
        }
    } else {
        // si es am se mantiene la hora a menos que sean las 12 (medianoche)
        // las 12 medianoche se registra como 00 en formato 24h
        if (partesNumeros[0] == 12) {
            res += "00";
        }
    }

    // añade el resto de la estampa del tiempo, que no se ve afectada por el formato de horas
    res += ":" + partesDigitos[1] + ":" + partesDigitos[2];
    return res;
}

// utiliza el operador ternario para ahorrar lineas de codigo
string timeConversion_2(string input) {
    string res = "";
    bool am = (input.compare(8,1,"A") == 0);
    string soloDigitos = input.substr(0, 8);
    string partesDigitos[] = {
        soloDigitos.substr(0,2),
        soloDigitos.substr(3,2),
        soloDigitos.substr(6,2),
    };
    int hora = stoi(partesDigitos[0]);

    // solucion que hace en una linea el cambio de la hora
    hora = am ? (hora==12 ? 0 : hora) : (hora==12 ? 12 : hora + 12);
    std::stringstream horaTemp;
    horaTemp << std::setw(2) << std::setfill('0') << hora;
    res += horaTemp.str();
    res += ":" + partesDigitos[1] + ":" + partesDigitos[2];
    return res;
}

int main() {
    cout << "Original: 03:40:23PM" << endl << "24h: " + timeConversion_2("03:40:23PM") << endl;
    cout << "Original: 12:20:20AM" << endl << "24h: " + timeConversion_2("12:20:20AM") << endl;
    return 0;
}