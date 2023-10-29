/* 
    Aqui temos um problema: múltiplas inclusões de cabeçalho dão bug no compilador. Portanto vamos fazer
    o compilador entender o que precisamos e não incluír coisas duas veses.
    A idéia disto eu achei parecida com os namespaces do PHP, apesar de os namespaces fazerem mais sentido
    na minha cabeça;
*/
#ifndef INDEX_SOMA_E_SUB
#define INDEX_SOMA_E_SUB
#include "../funcBasicas/index.h"

polynomial sumPolynomial(polynomial p1, polynomial p2);
polynomial subPolynomial(polynomial p1, polynomial p2);
polynomial multPolynomial(polynomial p1, polynomial p2);

#endif //aqui termina a inclusão que deve ser feita vinda deste .h caso ela já não tenha sido feita