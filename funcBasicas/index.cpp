#include <iostream>
#include <math.h>
#include "./index.h"

using namespace std;

/*
Esta função comentada é a função em C que realiza exatamente o que a função de baixo em C++ faz também;
ela abre um arquivo e retorna ele para nós.
O problema é que em C++, diferentemente de C, strings são um tipo, e não uma lista (ponteiro) de chars.
O problema desta função (se descomenta-la ela irá funcionar) é que o compilador aponta um warning:
ISO C++ forbids converting a string constant to ‘char*’. Por conta disto, é preciso utilizar o método
de conversão de strings para ponteiros de char, como fazemos na outra função.
Fonte: https://www.geeksforgeeks.org/convert-string-char-array-cpp/

FILE openFile(char *dir){

    FILE *f = fopen(dir, "r");
    return *f;
} */

FILE *privateOpenFile(string dir)
{
    FILE *f = fopen(dir.c_str(), "r");
    if (f == NULL)
    {
        cout << "O arquivo não foi encontrado";
        exit(2);
    }
    return f;
}

float privateStrToFloat(int c, FILE *f, polynomial p)
{
    /*
        Função responsável por transformar as linhas do arquivo de str -> float
     */

    // tamanho máximo de uma linha,pois não sabemos qual número vamos encontrar no arquivo, fonte Microsoft
    char l[240];

    // pega a linha do arquivo
    fgets(l, sizeof(l), f);
    // a mesma coisa de comparar como NULL, somente para que o compilador não de warning;
    if (l[0] == '\0')
    {
        cout << "O tamanho do polinômio é inferior a quantidade de dados do arquivo.";
        exit(3);
    }

    // se você tentar dar um casting padrão (float), ele retornará o valor ASCII do char, que não é o que queremos
    // a solução é utilizar atof():
    // p.a[c] = atof(l);

    /*
        mas como a gente quer ganhar 12 (nem 11) nesse trabalho, vamos fazer um atof do 0 aqui.
        para isto, devemos saber como funciona a tabela ASCII. Observe-a abaixo:
        48: 0
        49: 1
        50: 2
        51: 3
        52: 4
        53: 5
        54: 6
        55: 7
        56: 8
        57: 9

        é fácil perceber que se subtrairmos 0 de qualquer caractere, teremos justamente o seu valor em decimal!
        ex: 9 - 0 = 47 - 48 = 9
    */

    // delimitador
    int d = 0;

    int negative = 0;
    // com este laço saberemos exatamente qual o tamanho desta array vinda do arquivo
    for (int c = 0; l[c] != '\0'; c++)
    {
        if (l[c] == '-')
        {
            d -= 1;
            negative = 1;
        }
        d += 1;
    }

    if (c != p.n)
    {
        // agora podemos remover o valor do caractere '.' e '\0 do total de caracteres:
        d -= 2;
    }
    else
    {
        // quando estamos na última linha, talvez por conta do EOF só podemos retirar 1, caso contrário cortará o último dígito do número
        d -= 1;
    }

    // descobre em que posição está o '.' para separar a parte inteira da real:
    int i = 0;
    for (int c = 0; l[c] != '\0'; c++)
    {
        if (l[c] == '.' || l[c] == ',')
        {
            i = c;
        }
    }

    if (negative == 0)
    {
        // cria nosso número
        float n = 0;
        int flag = 0;
        int aux = 0;
        for (int count = 0; count <= d; count++)
        {
            if (l[count] == '.' || l[count] == ',')
            {
                flag += 1;
                continue;
            }
            if (flag == 0 && d > 0)
            {
                if (l[count] == '0' && count > 0 && l[count + 1] != '\0')
                {
                    if (aux == 0)
                    {
                        aux = 1 * pow(10, d - (count + 1));
                        n += aux;
                    }
                    else
                    {
                        int aux2 = 1 * pow(10, d - (count + 1));
                        n += aux2;
                        n -= aux;
                        aux = aux2;
                    }
                }
                else
                {
                    n += ((float)l[count] - '0') * pow(10, d - (count + 1));
                    n -= aux;
                    aux = 0;
                }
            }
            else
            {
                if (l[count] == '0' && count > 0 && l[count + 1] != '\0')
                {
                    if (aux == 0)
                    {
                        aux = 1 * pow(10, d - (count));
                        n += aux;
                    }
                    else
                    {
                        int aux2 = 1 * pow(10, d - (count));
                        n += aux2;
                        n -= aux;
                        aux = aux2;
                    }
                }
                else
                {
                    n += ((float)l[count] - '0') * pow(10, d - (count));
                    n -= aux;
                    aux = 0;
                }
            }
        }
        n -= aux;
        if (i == 0 && d > 0)
        {
            return n * 10;
        }
        else
        {
            return n / pow(10, d - i);
        }
    }
    else
    {
        // cria nosso número
        float n = 0;
        int flag = 0;
        int aux = 0;
        for (int count = 0; count < d+2; count++)
        {
            if (l[count] == '.' || l[count] == ',')
            {
                flag += 1;
                continue;
            }
            if (flag == 0 && d > 0)
            {
                if (l[count] == '0' && count > 0 && l[count + 1] != '\0')
                {
                    if (aux == 0)
                    {
                        aux = 1 * pow(10, d - (count + 1));
                        n += aux;
                    }
                    else
                    {
                        int aux2 = 1 * pow(10, d - (count + 1));
                        n += aux2;
                        n -= aux;
                        aux = aux2;
                    }
                }
                else
                {
                    if(l[count] != '-'){
                        n += ((float)l[count] - '0') * pow(10, d - (count + 1));
                        n -= aux;
                        aux = 0;
                    }
                }
            }
            else
            {   
                if (l[count] == '0' && count > 0 && l[count + 1] != '\0')
                {
                    if (aux == 0)
                    {
                        aux = 1 * pow(10, d - (count));
                        n += aux;
                    }
                    else
                    {
                        int aux2 = 1 * pow(10, d - (count));
                        n += aux2;
                        n -= aux;
                        aux = aux2;
                    }
                }
                else
                {
                    if(l[count] != '-'){
                        n += ((float)l[count] - '0') * pow(10, d - (count));
                        n -= aux;
                        aux = 0;
                    }
                }
            }
        }
        n -= aux;
        if (i == 0 && d > 0)
        {
            return -1* (n * 100);
        }
        else
        {
            if(i == 0){
                return -1* (n / pow(10, d-1 - i));
            }else{
                return -1* (n / pow(10, d - i));
            }
        }
    }
}

polynomial newPolynomial(int g)
{
    /*
        g é o grau do polinômio.
     */
    polynomial p;

    p.n = g;

    /*
        por algum motivo que eu não sei explicar, o C++ identifica que o vetor de retorno de um malloc é
        Void *, então é necessário fazer um casting para que ele funcione...
    */
    p.a = (float *)malloc((p.n) * sizeof(float));

    if (p.a == NULL)
    {
        cout << "erro na alocação da memória...";
        // erro diferente de 0 para identificar que o programa terminou com um erro, e não com sucesso.
        // preferi utilizar exit() para mostrar exatamente que foi um erro, e para não ficar lidando com um else gigantesco
        exit(1);
    }

    for (int c = 0; c < p.n; c++)
    {
        p.a[c] = 0;
    }

    // fica aqui uma dúvida: porque sizeof(p.a) == 8 se n=3??????
    /*
        cout << sizeof(p.a);
        exit(0);
    */
    return p;
}

void freePolynomial(polynomial p)
{
    if (p.a != NULL)
    {
        free(p.a);
        // cout << "memória desalocada com sucesso! \n";
    }
}

// declarado como constante pois quando o C++ fazum c_str() ele transforma em constante, não em variável.
void getPolynomialFromFile(polynomial p, const char *file)
{
    FILE *f = privateOpenFile(file);

    // tamanho máximo de uma linha,pois não sabemos qual número vamos encontrar no arquivo (fonte Microsoft).
    char l[240];

    int nlines = 0;
    while (fgets(l, sizeof(l), f) != NULL)
    {
        nlines += 1;
    }

    // reseta o fgets
    fseek(f, 0, SEEK_SET);

    if (p.n != nlines - 1)
    {
        cout << "O arquivo não possuí uma quantidade de dados diferêntes do necessário em: " << p.n - nlines - 1 << " parâmetros.";
        exit(4);
    }
    int leng = 0;
    for (int c = 0; c <= p.n; c++)
    {
        p.a[c] = privateStrToFloat(c, f, p);
    }
    fclose(f);
}

float calcPolynomial(polynomial p, float x){
    float result = 0;
    for (int c = 0; c <= p.n; c++)
    {   
        result += p.a[c] * pow(x, c);
        cout << p.a[c] << " * " << x << "^" << c << " += " << result << endl;
    }
    return result;
}

void showPolynomial(polynomial p)
{
    for (int i = 0; i <= p.n; i++)
    {
        cout << p.a[i] << "x^" << i << ' ';
    }
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}