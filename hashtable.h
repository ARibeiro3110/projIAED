/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _HASHTABLE_
#define _HASHTABLE_


#include "proj2.h"
#include "reservas.h"


#define NULLitem (NULL)
#define key(a) (a->cod_r)
#define eq(A,B) (!strcmp(A,B))

#define HASH_M 60013
#define HASH_A 31415
#define HASH_B 27183


typedef Reserva Item;
typedef char* Key;


int hash(char *v);
Item* STinit(int m, Reserva *_reservas);
void STinsert(Item item, Item *st);
Item STsearch(Key v, Item *st);
void STdelete(Key v, Item *st);


#endif