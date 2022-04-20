/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _VOOS_
#define _VOOS_


#include "proj2.h"
#include "data_hora.h"
#include "aeroportos.h"


#define MAX_VOOS 30000				/* Número máximo de voos */
#define MAX_CODIGO_VOO 7			/* Dimensão do código do voo */

/* Strings que podem ser imprimidas pelos comandos */
#define ERRO_INVALID_FLIGHT_CODE "invalid flight code\n"
#define ERRO_FLIGHT_ALREADY_EXISTS "flight already exists\n"
#define ERRO_TOO_MANY_FLIGHTS "too many flights\n"
#define ERRO_INVALID_CAPACITY "invalid capacity\n"


typedef struct voo {
	int i_voo;
	char cod_v[MAX_CODIGO_VOO];
	char partida[MAX_CODIGO_AEROPORTO];
	char chegada[MAX_CODIGO_AEROPORTO];
	Data data;
	Hora hora;
	Hora duracao;
	int capacidade;
	int horaPartida;
	int horaChegada;
	Reserva primeira;
} Voo;


extern int _numAeroportos;
extern Aeroporto _aeroportos[MAX_AEROPORTOS];
extern int _numVoos;
extern Voo _voos[MAX_VOOS];
extern Data _hoje;


void mostraVoo(int index);
void mostraVooPartida(int index);
void mostraVooChegada(int index);
int encontraVoo(char cod_v[], Data d);
Bool validaCodigoVoo(char cod_v[]);
Bool validaVoo(Voo v);
void criaVoo(Voo v);
void adicionaListaVoos();
Bool cmpVoosPartida(int a, int b);
Bool cmpVoosChegada(int a, int b);
void listaVoosPartida();
void listaVoosChegada();


#endif