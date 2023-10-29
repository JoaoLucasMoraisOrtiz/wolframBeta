#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "./index.h"
#include "../funcBasicas/index.h"

using namespace std;

polynomial sumPolynomial(polynomial p1, polynomial p2)
{

    if (p1.n > p2.n)
    {
        polynomial p = newPolynomial(p1.n);
        for (int i = 0; i <= p2.n; i++)
        {
            p.a[i] = p1.a[i] + p2.a[i];
        }
        for (int i = p2.n + 1; i <= p1.n; i++)
        {
            p.a[i] = p1.a[i];
        }
        return p;
    }
    else if (p2.n > p1.n)
    {
        polynomial p = newPolynomial(p2.n);
        for (int i = 0; i <= p1.n; i++)
        {
            p.a[i] = p2.a[i] + p1.a[i];
        }
        for (int i = p1.n + 1; i <= p2.n; i++)
        {
            p.a[i] = p2.a[i];
        }
        return p;
    }
    else
    {
        polynomial p = newPolynomial(p1.n);
        for (int i = 0; i <= p1.n; i++)
        {
            p.a[i] = p2.a[i] + p1.a[i];
        }
        return p;
    }
}

polynomial subPolynomial(polynomial p1, polynomial p2)
{

    if (p1.n > p2.n)
    {
        polynomial p = newPolynomial(p1.n);
        for (int i = 0; i <= p2.n; i++)
        {
            p.a[i] = p1.a[i] - p2.a[i];
        }
        for (int i = p2.n + 1; i <= p1.n; i++)
        {
            p.a[i] = p1.a[i];
        }
        return p;
    }
    else if (p2.n > p1.n)
    {
        polynomial p = newPolynomial(p2.n);
        for (int i = 0; i <= p1.n; i++)
        {
            p.a[i] = p1.a[i] - p2.a[i];
        }
        for (int i = p1.n + 1; i <= p2.n; i++)
        {
            p.a[i] = p2.a[i];
        }
        return p;
    }
    else
    {
        polynomial p = newPolynomial(p1.n);
        for (int i = 0; i <= p1.n; i++)
        {
            p.a[i] = p2.a[i] - p1.a[i];
        }
        return p;
    }
}

polynomial multPolynomial(polynomial p1, polynomial p2)
{
    polynomial answer = newPolynomial((p1.n) + (p2.n));
    if (p1.n >= p2.n)
    {
        for(int i=p2.n; i >= 0; i--){
            int len = (p1.n + p2.n) - (p2.n - i);
            polynomial aux = newPolynomial(len);

            
            for(int c=0; c <= p1.n; c++){
                aux.a[len - c] = p2.a[i] * p1.a[p1.n - c];
            }
            polynomial answerBackup = sumPolynomial(answer,aux);
            for(int i=0; i <= answer.n; i++){
                answer.a[i] = answerBackup.a[i];
            }
            freePolynomial(aux);
            freePolynomial(answerBackup);
        }

    }else{
        for(int i=p1.n; i >= 0; i--){
            int len = (p2.n + p1.n) - (p1.n - i);
            polynomial aux = newPolynomial(len);

            
            for(int c=0; c <= p2.n; c++){
                aux.a[len - c] = p1.a[i] * p2.a[p2.n - c];
            }
            polynomial answerBackup = sumPolynomial(answer,aux);
            for(int i=0; i <= answer.n; i++){
                answer.a[i] = answerBackup.a[i];
            }
            freePolynomial(aux);
            freePolynomial(answerBackup);
        }
    }
    return answer;
}

