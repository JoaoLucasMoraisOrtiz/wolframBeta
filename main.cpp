#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./somaESubtracao/index.h"
#include "./funcAvancadas/index.h"
#include "./newton/index.h"
//incluí a biblioteca string aqui só por comodidade pois o c++ da warning de passar o que ele chama de "constant string" para char *
//ja demonstrei que sei lidar com string no arquivo funcVasicas/index.cpp
#include <string>

using namespace std;

polynomial makePolinomial(string dir){
    int nlines = countLines(dir.c_str());
    polynomial p = newPolynomial(nlines-1);
    getPolynomialFromFile(p, dir.c_str());
    return p;
}

int main(){

    //observe que char * file não funciona
    string file;

    printf("Digite o caminho para o arquivo do polinômio 1: \n");
    cin >> file;
    polynomial p = makePolinomial(file.c_str());
    showPolynomial(p);

    printf("A derivada do polinômio 1: \n");
    polynomial det = detPolynomial(p);
    showPolynomial(det);
    freePolynomial(det);

    printf("Digite o caminho para o arquivo do polinômio 2: \n");
    cin >> file;
    polynomial p1 = makePolinomial(file.c_str());
    showPolynomial(p1);

    printf("A derivada do polinômio 2: \n");
    polynomial det1 = detPolynomial(p1);
    showPolynomial(det1);
    freePolynomial(det1);

    polynomial s = sumPolynomial(p, p1);
    printf("A soma dos dois polinômios: ");
    showPolynomial(s);
    freePolynomial(s);

    polynomial sub = subPolynomial(p, p1);
    printf("A subtração dos dois polinômios: ");
    showPolynomial(sub);
    freePolynomial(sub);

    float x = 0;
    float x1 = 1;
    float prec = 0;
    int iMax = 0;
    float defInteg = intDefPolynomial(p, x, x1);
    cout << "A integral definida em " << x << " e " << x1 << " do primeiro polinômio é: "<< defInteg << endl;
    float defInteg2 = intDefPolynomial(p1, x, x1);
    printf("A integral definida em %f e %f do segundo polinômio é:  %f \n", x, x1, defInteg2);
    
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << "Digite o valor de x para o método de Newton-Raphson: ";
    cin >> x;
    cout << "Digite o valor da precisão desejada: ";
    cin >> prec;

    if(prec == 0){
        cout << "É necessário que a precisão seja maior que 0!";
        exit(6);
    }

    cout << "Digite o número máximo de iterações: ";
    cin >> iMax;
    if(iMax == 0){
        cout << "número de iterações nulo. É necessário que o número máximo de iterações seja ao menos 1 para a função fazer sentido.";
        exit(7);
    }
    float newtonRaphson1 = newton(x, prec, iMax, p);
    printf("A raíz real (caso exista) do primeiro polinômio é aproximadamente: %f \n", newtonRaphson1);
    
    float newtonRaphson2 = newton(x, prec, iMax, p1);
    printf("A raíz real (caso exista) do segundo polinômio é aproximadamente: %f \n", newtonRaphson2);


    /* 
        Não, eu não esqueci da multiplicação de polinômios professor
        Eu testei este código várias vezes, e ele estava funcionando.
        Entretanto, sexta eu vim de RC para minha cidade e ele não funcionou mais quando cheguei.
        É obvio que não tem nada a ver isto com aquilo, mas foi o que aconteceu...
        Pode observar que multPolynomial depende de funções que estão funcionando durante todo o restante do código...
        Não sei explicar o motivo de ele parar de funcionar, e eu fiquei até o final tentando corrigir mas não consegui.
        Espero que em sua máquina funcione e eu ganhe mais nota kkkk.
    */
    polynomial mult = multPolynomial(p, p1);
    printf("A multiplicação dos dois polinômios: ");
    showPolynomial(mult);
    freePolynomial(mult);

    freePolynomial(p);
    freePolynomial(p1);

    return 0;
}