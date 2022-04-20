/* Afonso da Conceição Ribeiro, 102763 */


#include "hashtable.h"


static int m;


 /*explicar escolha - diminuir colisoes, usar todos os carateres*/
int hash(char *v) {
    long int h, a = HASH_A, b = HASH_B; /* usar valores diretamente contt hashA, B ??? */
    
    for (h = 0; *v != '\0'; v++, a = a*b % (m-1))
        h = (a*h + *v) % M;
    
    return h;
}

int hashtwo(char *v) {
    long int h, a = HASH_TWO_A; /* usar valores diretamente contt hashtwo H, A ??? */
    
    for (h = 0; *v != '\0'; v++)
        h = (a*h + *v) % m;
    
    return h;
}

Item* STinit() {
    int i;
    Item *st;

    m = M;

    st = (Item*) _malloc(m * sizeof(Item));
    
    for (i = 0; i < m; i++)
        st[i] = NULLitem;

    return st;
}

void STinsert(Item item, Item *st) {
    static int N = 0;
    Key v = key(item);
    int i = hash(v);
    int k = hashtwo(v);
    
    while (st[i] != NULLitem) {
        if (marker(st[i]) == DELETED) {
            _free(st[i]);
            break;
        }
        i = (i+k) % m;
    }
    
    st[i] = item;
    if (N++ > m/2) {
        m = 2 * m;
        expand(st);
    }
}

Item STsearch(Key v, int *hash_index, Item *st) { /* trocar key por paramentro, pa poder aplicar a cod r ou cod v */
    int i = hash(v);
    int k = hashtwo(v);
    
    while (st[i] != NULLitem) {
        if (marker(st[i]) != DELETED && eq(v, key(st[i]))) {
            *hash_index = i;
            return st[i];
        }
        else
            i = (i+k) % m;
    }

    return NULLitem;
}

void freeItem(Item a) {
    _free(key(a));
}

int STdelete(int hash_index, Item *st) {

    if (st[hash_index] != NULLitem) {
        _free(key(st[hash_index]));
        marker(st[hash_index]) = DELETED;
        return hash_index;
    }

    else
        return NOT_FOUND;
    
}

int ST_search_delete(Key v, Item *st) {
    int hash_index = 0, *hash_index_ptr = &hash_index;

    STsearch(v, hash_index_ptr, st);

    return STdelete(hash_index, st);
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
