/* Afonso da Conceição Ribeiro, 102763 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"


static int N, M = HASH_M;


/* Função de dispersão que minimiza colisões, pois utiliza todos os carateres
da string e recalcula com base em cada iteração. Recebe uma string "v" e
retorna um inteiro. */
int hash(char *v) {
    long int h, a = HASH_A, b = HASH_B;
    
    for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    
    return h;
}

/* Resebe um inteiro "m" e um ponteiro para Item "st", inicializa uma hashtable
de tamanho m e retorna-a. */
Item* STinit(int m, Item *st) {
    int i;
    Item *new_st;

    new_st = (Item*) _malloc(m * sizeof(Item), st);
    
    for (i = 0; i < m; i++)
        new_st[i] = NULLitem;
    
    return new_st;
}

/* Receb um Item "item" e uma hashtable "st" e insere o Item na hashtable. */
void STinsert(Item item, Item *st) {
    int i = hash(key(item));
    
    while (st[i] != NULLitem)
        i = (i+1) % M;
    
    st[i] = item;
}

/* Recebe uma Key "v" e uma hashtable "st" e procura o Item cuja chave é v na
hashtable, e devolve-o. */
Item STsearch(Key v, Item *st) {
    int i = hash(v);
    
    while (st[i] != NULLitem) {
        if (eq(v, key(st[i])))
            return st[i];
        else
            i = (i+1) % M;
    }

    return NULLitem;
}

/* Recebe uma Key "v" e uma hashtable "st", procura o Item cuja chave é v na
hashtable e elimina-o da mesma. */
void STdelete(Key v, Item *st) {
    int j, i = hash(v);
    Item aux;

    while (st[i] != NULLitem) {
        if (eq(v, key(st[i])))
            break;
        else
            i = (i+1) % M;
    }

    if (st[i] == NULLitem)
        return;
    
    st[i] = NULLitem;
    N--;

    for (j = (i+1) % M; st[j] != NULLitem; j = (j+1) % M, N--) {
        aux = st[j];
        st[j] = NULLitem;
        STinsert(aux, st);
    }
}