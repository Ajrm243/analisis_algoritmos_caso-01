#include <iostream>
using namespace std;

int main() {
    // variables para manejo de tiempo de ejecucion
    // tripletas de ejemplo
    int ana[] = {10,32,14};
    int bob[] = {5, 34, 17};
    // arreglo con los valores del restultado en orden Ana, Bob
    int res[] = {0,0};

    // algoritmo 1: brute force/deducción instantánea

    // for loop para iterar las tripletas
    for (int i = 0; i < 3; i++) {
        if (ana[i] > bob[i]) {
            res[0]++;
        }
        else if (ana[i] < bob[i]) {
            res[1]++;
        }
    }
    cout << "Resultado alg1: " << res[0] << " | " <<  res[1] << endl;
    
    // reinicia los valores
    res[0] = 0; res[1] = 0;

    // algoritmo 2: reduccion de ciclos y minimizacion de ifs
    // extracto de la clase del profesor
    res[0] += ana[0]>bob[0]?1:0 + ana[1]>bob[1]?1:0 + ana[2]>bob[2]?1:0;
    res[1] += (ana[0]<bob[0]?1:0) + (ana[1]<bob[1]?1:0) + (ana[2]<bob[2]?1:0);
    cout << "Resultado alg2: " << res[0] << " | " <<  res[1] <<endl;

    return 0;   // g++ no acepta void main() entonces siempre hay que devolver un 0 explícitamente, a diferencia de MSVC
}