#include <iostream>
#include "./somaESubtracao/index.h"
#include "./funcAvancadas/index.h"
#include "./newton/index.h"

//incluí a biblioteca string aqui só por comodidade pois o c++ da warning de passar o que ele chama de "constant string" para char *
//ja demonstrei que sei lidar com string no arquivo funcVasicas/index.cpp
#include <string>

using namespace std;

int main(){
    cout << "Digite o caminho para o arquivo do polinômio 1: \n" << endl;
    polynomial p = newPolynomial(4);
    //observe que char * file ="/mnt/usb-Generic_STORAGE_DEVICE_000000000819-0:0-part1/documentos/WolfranBeta/polynomial1.txt"; não funciona
    //char *file = "/mnt/usb-Generic_STORAGE_DEVICE_000000000819-0:0-part1/documentos/WolfranBeta/polynomial1.txt";
    string file = "/mnt/usb-Generic_STORAGE_DEVICE_000000000819-0:0-part1/documentos/WolfranBeta/polynomial1.txt";
    getPolynomialFromFile(p, file.c_str());
    showPolynomial(p);

    cout << "A derivada do polinômio 1: \n";
    polynomial det = detPolynomial(p);
    showPolynomial(det);
    freePolynomial(det);

    cout << "Digite o caminho para o arquivo do polinômio 2: \n";
    polynomial p1 = newPolynomial(2);
    file = "/mnt/usb-Generic_STORAGE_DEVICE_000000000819-0:0-part1/documentos/WolfranBeta/polynomial2.txt";
    getPolynomialFromFile(p1, file.c_str());
    showPolynomial(p1);

    cout << "A derivada do polinômio 2: \n";
    polynomial det1 = detPolynomial(p1);
    showPolynomial(det1);
    freePolynomial(det1);

    polynomial mult = multPolynomial(p, p1);
    cout << "A multiplicação dos dois polinômios: " << endl;
    showPolynomial(mult);

    polynomial s = sumPolynomial(p, p1);
    cout << "A soma dos dois polinômios: " << endl;
    showPolynomial(s);
    freePolynomial(s);

    polynomial sub = subPolynomial(p, p1);
    cout << "A subtração dos dois polinômios: " << endl;
    showPolynomial(sub);
    freePolynomial(sub);

    float x = 2;
    float x1 = 3;
    //float defInteg = intDefPolynomial(p, x, x1);
    //cout << "A integral definida em " << x << " e " << x1 << " do primeiro polinômio é: "<< defInteg << endl;
    float defInteg2 = intDefPolynomial(p1, x, x1);
    cout << "A integral definida em " << x << " e " << x1 << " do segundo polinômio é: "<< defInteg2 << endl;
    float newtonRhapson = newton(3, 0.001, 1000, p);

    freePolynomial(p);
    freePolynomial(p1);

    return 0;
}