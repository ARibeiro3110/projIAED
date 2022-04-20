/*
 * Projeto 2 - Sistema de gestão de voos entre aeroportos - 20/04/2022
 * 
 * Afonso da Conceição Ribeiro, 102763, 1.º Ano
 *
 * afonsodaconceicaoribeiro@tecnico.ulisboa.pt
 *
 * Unidade Curricular de Introdução aos Algoritmos e Estruturas de Dados
 * 
 * Licenciatura em Engenharia Informática e de Computadores - Alameda
 * 
 * Instituto Superior Técnico - Universidade de Lisboa
 * 
 * Ano Letivo 2021/2022, Semestre 2, Período 3
*/



#include "proj2.h"
#include "aeroportos.h"
#include "voos.h"
#include "reservas.h"


/* Variáveis Globais */

int _numAeroportos = 0;			      	/* Número de aeroportos introduzidos */
Aeroporto _aeroportos[MAX_AEROPORTOS];	/* Vetor de aeroportos */

int _numVoos = 0;						/* Número de voos introduzidos */
Voo _voos[MAX_VOOS];					/* Vetor de voos */

Data _hoje = { 1, 1, 2022 };			/* Data atual do sistema */

const int _diasMesAc[] =				/* Dias acumulados por mês (jan=1) */
{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };


int main() {
	int c;

	Reserva *_reservas = NULL;
	_reservas = STinit(HASH_M, _reservas);

	while ((c = getchar()) != 'q')
		switch (c) {
			case 'a': adicionaAeroporto();
				break;
			case 'l': listaAeroportos();
				break;
			case 'v': adicionaListaVoos();
				break;
			case 'p': listaVoosPartida();
				break;
			case 'c': listaVoosChegada();
				break;
			case 't': alteraData();
				break;
			case 'r': adicionaListaReservas(_reservas);
				break;
			case 'e': eliminaVoosReserva(_reservas);
				break;
		}

	libertaMemoria(_reservas);

	return 0;
}


/* Função "malloc" que, caso a memória se esgote, termina o programa de forma
controlada, exibindo a mensagem de erro. */
void* _malloc(int size, Reserva *_reservas) {
	void* n = malloc(size);
	if (n != NULL)
		return n;

	libertaMemoria(_reservas);
	printf(ERRO_NO_MEMORY);
	exit(EXIT_CODE_NO_MEMORY);
	return NULL;
}

/* Função "free" que, após libertar a memória, atribui "NULL" ao ponteiro. */
void _free(void* ptr) {
	if (ptr != NULL) {
		free(ptr);
		ptr = NULL;
	}
}

int leProximaPalavra(char str[]) {
	char c = getchar();
	int i = 0;
	while (c == ' ' || c == '\t')
		c = getchar();
	while (c != ' ' && c != '\t' && c != '\n') {
		str[i++] = c;
		c = getchar();
	}
	str[i] = '\0';
	return (c == '\n');
}

void lePalavraAteFimDeLinha(char str[]) {
	char c = getchar();
	int i = 0;
	while (c == ' ' || c == '\t')
		c = getchar();
	while (c != '\n') {
		str[i++] = c;
		c = getchar();
	}
	str[i] = '\0';
}

void leAteFimDeLinha() {
	char c = getchar();
	while (c != '\n')
		c = getchar();
}

void bubbleSort(int indexes[], int size, Bool (*cmpFunc) (int a, int b)) {
	int i, j, done;

	for (i = 0; i < size-1; i++) {
		done = 1;

		for (j = size-1; j > i; j--)

		if ((*cmpFunc)(indexes[j-1], indexes[j])) {
			int aux = indexes[j];
			indexes[j] = indexes[j-1];
			indexes[j-1] = aux;
			done = 0;
		}

		if (done) break;
	}
}

/* Recebe um caráter e retorna TRUE caso este seja um dígito, e FALSE caso
contrário. */
Bool eh_digito(char c) {
    return c >= '0' && c <= '9';
}

/* Recebe um caráter e retorna TRUE caso este seja uma letra maiúscula, e FALSE
caso contrário. */
Bool eh_maiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}