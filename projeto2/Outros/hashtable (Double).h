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
#define HASH_TWO_A 127
#define NOT_FOUND -1
#define DELETED -2

typedef Reserva Item;
typedef char* Key;


Item* STinit();
int hash(char *v);
int hashtwo(char *v);
void STinsert(Item item, Item *st);
Item STsearch(Key v, int *hash_index, Item *st);
void freeItem(Item a);
int STdelete(int hash_index, Item *st);
int ST_search_delete(Key v, Item *st);
void expand(Item *st);


#endif