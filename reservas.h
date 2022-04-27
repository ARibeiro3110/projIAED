/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _ESTRUTURAS_
#define _ESTRUTURAS_


#include "proj2.h"
#include "data_hora.h"
#include "aeroportos.h"
#include "voos.h"
#include "hashtable.h"


#define TAM_CODIGO_RESERVA 10	/* Dimensão mínima do código de reserva */

/* Strings que podem ser imprimidas pelos comandos */
#define ERRO_INVALID_RESERVATION_CODE "invalid reservation code\n"
#define ERRO_FLIGHT_DOES_NOT_EXIST ": flight does not exist\n"
#define ERRO_RESERVATION_ALREADY_USED ": flight reservation already used\n"
#define ERRO_TOO_MANY_RESERVATIONS "too many reservations\n"
#define ERRO_INVALID_PASSENGER_NUMBER "invalid passenger number\n"
#define ERRO_NOT_FOUND "not found\n"


struct nodeReserva {
	struct nodeReserva *anterior;
	Voo *voo;
    char *cod_r;
	int numPassageiros;
	struct nodeReserva *seguinte;
};

extern int _numAeroportos;
extern Aeroporto _aeroportos[MAX_AEROPORTOS];
extern int _numVoos;
extern Voo _voos[MAX_VOOS];
extern Data _hoje;


void adicionaListaReservas(Reserva *_reservas);
Bool validaReserva(char cod_v[], Data d, char *cod_r, int numPassageiros,
				   int len_cod_r, int i_voo, Reserva *_reservas);
Bool validaCodigoReserva(char *cod_r, int len_cod_r);
Reserva encontraReserva(char *cod_r, Reserva *_reservas);
Reserva novaReserva(int i_voo, char *cod_r, int numPassageiros,
					Reserva *_reservas);
void insereReservaOrdenada(Reserva nova_reserva, int i_voo);
Bool validaVooReserva(char cod_v[], Data data, int i_voo);
void mostraReservas(Reserva head);
void mostraReserva(Reserva r);

void eliminaVoosReserva(Reserva *_reservas);
void eliminaVoos(char *cod_v, Reserva *_reservas);
void libertaVoo(int i_voo, Reserva *_reservas);
void eliminaReserva(Reserva r);

void libertaMemoria(Reserva *_reservas);


#endif