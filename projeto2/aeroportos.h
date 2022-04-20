/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _AEROPORTOS_
#define _AEROPORTOS_


#include "proj2.h"


#define MAX_AEROPORTOS 40			/* Número máximo de aeroportos */
#define MAX_CODIGO_AEROPORTO 4		/* Dimensão do código do aeroporto */
#define MAX_NOME_PAIS 31			/* Dimensão do nome do pais */
#define MAX_NOME_CIDADE 51			/* Dimensão do nome da cidade */

/* Strings que podem ser imprimidas pelos comandos */
#define AIRPORT "airport "
#define ERRO_INVALID_AIRPORT_ID "invalid airport ID\n"
#define ERRO_TOO_MANY_AIRPORTS "too many airports\n"
#define ERRO_DUPLICATE_AIRPORT "duplicate airport\n"
#define ERRO_NO_SUCH_AIRPORT_ID ": no such airport ID\n"


typedef struct aeroporto {
	char id[MAX_CODIGO_AEROPORTO];
	char pais[MAX_NOME_PAIS];
	char cidade[MAX_NOME_CIDADE];
	int numVoos;
} Aeroporto;


extern int _numAeroportos;
extern Aeroporto _aeroportos[MAX_AEROPORTOS];


Bool aeroportoInvalido(char id[]);
int encontraAeroporto(char id[]);
void adicionaAeroporto();
void mostraAeroporto(int index);
Bool cmpAeroportos(int a, int b);
void listaTodosAeroportos();
void listaAeroportos();


#endif