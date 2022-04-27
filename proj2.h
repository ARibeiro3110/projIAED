/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _PROJ_H_
#define _PROJ_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_INSTRUCAO 65535			/* Dimensão máxima de cada instrução */
#define NAO_EXISTE -1				/* Código de erro */

#define ERRO_NO_MEMORY "No memory.\n" /* Mensagem de erro de memória esgotada */
#define EXIT_CODE_NO_MEMORY 0		  /* Exit code */


typedef enum Bool {
	FALSE = 0,
	TRUE = 1
} Bool;

typedef struct nodeReserva *Reserva;


void* _malloc(int size, Reserva *_reservas);
void _free(void* ptr);
int leProximaPalavra(char str[]);
void lePalavraAteFimDeLinha(char str[]);
void leAteFimDeLinha();
void bubbleSort(int indexes[], int size, Bool (*cmpFunc) (int a, int b));
Bool eh_digito(char c);
Bool eh_maiuscula(char c);
Bool eh_minuscula(char c);


#endif