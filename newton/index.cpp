#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "./index.h"

using namespace std;

/*  
    Método de Newton-Rhapson para o calculo de raízes reais de polinômios.
*/

float newton(float x, float accuracy, int max, polynomial p){

    polynomial p2 = detPolynomial(p);

    float x1;
    
    float currentAcc;
    
    float flag = calcPolynomial(p2, x);
    if(flag != 0){
        x1 = x - (calcPolynomial(p, x)) / flag;
    }else{
        printf("Impossível dividir por 0");
        exit(5);
    }
    for(int i = 0; i <= max; i++){
        if(currentAcc >= accuracy){
            x = x1;
            x1 = x - calcPolynomial(p, x) / flag;
            currentAcc = abs(x1 - x);
        }else{
            cout << x1 << endl;
            exit(0);
            return x1;
        }                                                        
    }
    cout << x1 <<endl;
    exit(0);
    return x1;
    
}