/* 
    Aqui temos um problema (não aqui, na verdade o problema surgiu ao se criar o somaESubtração/index.h): múltiplas inclusões de cabeçalho dão bug no compilador. Portanto vamos fazer
    o compilador entender o que precisamos e não incluír coisas duas veses.
    A idéia disto eu achei parecida com os namespaces do PHP, apesar de os namespaces fazerem mais sentido
    na minha cabeça;
*/
#ifndef INDEX_FUNC_BASICAS
#define INDEX_FUNC_BASICAS

typedef struct index
{
    /* 
        este struct representa nossos polinômios.
        dado que um polinômio, pela definição mostrada na proposta, segue:
                 P = a_0*x_0 + a_1*x_1 + ... + a_n*x_n
        precisamos de apenas um vetor *a que é um malloc de tamanho n que gurada os a's index do polinômio,
        e um n, que indica o tamanho deste malloc.
        (x não precisa de vetor, pois sempre é um valor fixo, definido pelo usuário na execução, e que
        sempre será elevado a n, ou seja, seu vetor sempre será:
        1, x, x², x³,..., x^n.
        repare que este polinômio é definido para n >= 0, assim não temos que lidar com x < 0.)
    */
    int n;
    float *a;
} polynomial;


polynomial newPolynomial(int g);
void freePolynomial(polynomial p);
void getPolynomialFromFile(polynomial p, const char * file);
float calcPolynomial(polynomial p, float x);
void showPolynomial(polynomial p);
int countLines(const char *file);

#endif //aqui termina a inclusão que deve ser feita vinda deste .h caso ela já não tenha sido feita