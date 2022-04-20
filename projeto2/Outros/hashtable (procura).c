/* Afonso da Conceição Ribeiro, 102763 */


#include "hashtable.h"


static int N, m = M;


 /*explicar escolha - diminuir colisoes, usar todos os carateres*/
int hash(char *v) {
    long int h, a = HASH_A, b = HASH_B; /* usar valores diretamente contt hashA, B ??? */
    
    for (h = 0; *v != '\0'; v++, a = a*b % (m-1))
        h = (a*h + *v) % m;
    
    return h;
}

Item* STinit(int m) {
    int i;

    Item *st = (Item*) _malloc(m * sizeof(Item));
    
    for (i = 0; i < m; i++)
        st[i] = NULLitem;
    
    return st;
}

void STinsert(Item item, Item *st) {
    static int N = 0;
    int i = hash(key(item));
    
    while (st[i] != NULLitem)
        i = (i+1) % m;
    
    st[i] = item;

    if (N++ > m/2) {
        m = 2 * m;
        expand(st);
    }
}

Item STsearch(Key v, Item *st) { /* trocar key por paramentro, pa poder aplicar a cod r ou cod v */
    int i = hash(v);
    
    while (st[i] != NULLitem) {
        if (eq(v, key(st[i])))
            return st[i];
        else
            i = (i+1) % m;
    }

    return NULLitem;
}

void STdelete(Item item, Item *st) {
    Key v = key(item);
    int j, i = hash(v);
    Item aux;

    while (st[i] != NULLitem) {
        if (eq(v, key(st[i])))
            break;
        else
            i = (i+1) % m;
    }

    if (st[i] != NULLitem)
        return;
    
    st[i] = NULLitem;
    N--;

    for (j = (i+1) % m; st[j] != NULLitem; j = (j+1) % m, N--) {
        aux = st[j]; /* ??? */
        st[j] = NULLitem;
        STinsert(aux, st);
    }

    return;
}

void expand(Item *st) {
    int i;
    Item *t = st;

    st = STinit(m);

    for (i = 0; i < m/2; i++)
        if (key(t[i]) != NULLitem)
            STinsert(t[i], st);
    
    free(t);
}
