/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _HASHTABLE_
#define _HASHTABLE_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h" /* ??? deveria ser "reserva" */
#include "proj2.h"


#define NULLitem (NULL)
#define key(a) (a->cod_r)
#define eq(A,B) (!strcmp(A,B))
#define index(a) ((a->voo)->i_voo) /* ??? */
#define marker(a) (a->numPassageiros)

#define M 20011
#define HASH_A 31415
#define HASH_B 27183

typedef Reserva Item;
typedef char* Key;


int hash(char *v);
/*void*/ Item* STinit(int m/*, Item *st*/);
void STinsert(Item item, Item *st);
Item STsearch(Key v, Item *st);
void STdelete(Item item, Item *st);
void expand(Item *st);


#endif