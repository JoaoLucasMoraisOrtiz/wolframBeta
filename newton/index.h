/* 
    Aqui temos um problema (não aqui, na verdade o problema surgiu ao se criar o somaESubtração/index.h): múltiplas inclusões de cabeçalho dão bug no compilador. Portanto vamos fazer
    o compilador entender o que precisamos e não incluír coisas duas veses.
    A idéia disto eu achei parecida com os namespaces do PHP, apesar de os namespaces fazerem mais sentido
    na minha cabeça;
*/
#ifndef INDEX_NEWTON
#define INDEX_NEWTON
#include "../funcBasicas/index.h"
#include "../funcAvancadas/index.h"

float newton(float x, float accuracy, int max, polynomial p);

#endif //aqui termina a inclusão que deve ser feita vinda deste .h caso ela já não tenha sido feita