#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./index.h"

using namespace std;

polynomial detPolynomial(polynomial p){
    polynomial det = newPolynomial(p.n-1);
    
    for(int i=p.n; i >= 1; i--){
        det.a[i-1] = i*p.a[i];
    }
    return det;
}

polynomial intPolynomial(polynomial p, float c){
    polynomial integ = newPolynomial(p.n+1);
    
    for(int i=p.n; i >= 0; i--){

        integ.a[i + 1] = p.a[i]/(i+1);
    }
    integ.a[0] = c;
    return integ;
}

float intDefPolynomial(polynomial p, float x0, float x1){
    polynomial integ = intPolynomial(p,0);
    float r;
    r = calcPolynomial(integ, x1) - calcPolynomial(integ, x0);
    freePolynomial(integ);
    return abs(r);
}