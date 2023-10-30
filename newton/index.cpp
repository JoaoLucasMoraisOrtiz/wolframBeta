#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./index.h"

using namespace std;

/* 
    método que calcula newton-raphson para números reais
*/
float newton(float x, float accuracy, int maxInteraction, polynomial p) {

    //polinômio de resposta
    polynomial p2 = detPolynomial(p);
    float x1;
    float currentAcc = 0;

    for (int i = 0; i < maxInteraction; i++) {

        float flag = calcPolynomial(p2, x);

        //verifica para não dividir por 0
        if (flag != 0) {
            x1 = x - calcPolynomial(p, x) / flag;

            /* 
                definindo a nova acuracia.
                Tem que utilizar fabs pq estamos lidando com um float.
            */
            currentAcc = fabs(x1 - x);
            x = x1;
            if (currentAcc < accuracy) {
                return x1;
            }
        } else {
            printf("Impossível dividir por 0");
            exit(5);
        }
    }
    return x1;
}