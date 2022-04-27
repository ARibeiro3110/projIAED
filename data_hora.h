/* Afonso da Conceição Ribeiro, 102763 */


#ifndef _DATA_HORA_
#define _DATA_HORA_


#include "proj2.h"


#define ANO_INICIO 2022				/* Ano inicial do sistema */
#define DIAS_ANO 365				/* Número de dias num ano */
#define HORAS_DIA 24				/* Número de horas num dia */
#define MINUTOS_HORA 60				/* Número de minutos numa hora */
#define MINUTOS_DIA 1440			/* Número de minutos num dia */

/* Strings que podem ser imprimidas pelos comandos */
#define ERRO_INVALID_DATE "invalid date\n"
#define ERRO_INVALID_DURATION "invalid duration\n"


typedef struct data {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct hora {
	int hora;
	int minuto;
} Hora;


extern Data _hoje;
extern const int _diasMesAc[];


Data leData();
Hora leHora();
void mostraData(Data d);
void mostraHora(Hora h);
int converteDataNum(Data d);
int converteHoraNum(Hora h);
int converteDataHoraNum(Data d, Hora h);
Data converteNumData(int num);
Hora converteNumHora(int num);
Bool validaData(Data d);
Bool validaHora(Hora h);
Bool datasIguais(Data d1, Data d2);
Bool ehPassado(Data d);
void alteraData();


#endif