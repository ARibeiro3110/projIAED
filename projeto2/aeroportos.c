/* Afonso da Conceição Ribeiro, 102763 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aeroportos.h"


Bool aeroportoInvalido(char id[]) {
	int i;

	for (i = 0; id[i] != '\0'; i++)
		if (!eh_maiuscula(id[i]))
			return TRUE;

	return FALSE;
}

int encontraAeroporto(char id[]) {
	int i;

	for (i = 0; i < _numAeroportos; i++)
		if (!strcmp(id, _aeroportos[i].id))
			return i;
	
	return NAO_EXISTE;
}

void adicionaAeroporto() {
	Aeroporto a;

	leProximaPalavra(a.id);
	leProximaPalavra(a.pais);
	lePalavraAteFimDeLinha(a.cidade);

	if (aeroportoInvalido(a.id))
		printf(ERRO_INVALID_AIRPORT_ID);

	else if (_numAeroportos == MAX_AEROPORTOS)
		printf(ERRO_TOO_MANY_AIRPORTS);

	else if (encontraAeroporto(a.id) != NAO_EXISTE)
		printf(ERRO_DUPLICATE_AIRPORT);

	else {
		strcpy(_aeroportos[_numAeroportos].id, a.id);
		strcpy(_aeroportos[_numAeroportos].pais, a.pais);
		strcpy(_aeroportos[_numAeroportos].cidade, a.cidade);
		_aeroportos[_numAeroportos].numVoos = 0;
		_numAeroportos++;
		printf(AIRPORT "%s\n", a.id);
	}
}

void mostraAeroporto(int index) {

	printf("%s %s %s %d\n", _aeroportos[index].id, _aeroportos[index].cidade,
							_aeroportos[index].pais,_aeroportos[index].numVoos);
}

Bool cmpAeroportos(int a, int b) {
	return strcmp(_aeroportos[a].id, _aeroportos[b].id) > 0;
}

void listaTodosAeroportos() {
	int i;
	int indexAeroportos[MAX_AEROPORTOS];

	for (i = 0; i < _numAeroportos; i++)
		indexAeroportos[i] = i;

	bubbleSort(indexAeroportos, _numAeroportos, cmpAeroportos);

	for (i = 0; i < _numAeroportos; i++)
		mostraAeroporto(indexAeroportos[i]);
}

void listaAeroportos() {
	char id[MAX_CODIGO_AEROPORTO];
	int indexAeroporto, ultima = 0;

	ultima = leProximaPalavra(id);

	if (strlen(id) == 0)
		listaTodosAeroportos();

	else
		while (strlen(id) != 0) {
			indexAeroporto = encontraAeroporto(id);

			if (indexAeroporto == NAO_EXISTE)
				printf("%s" ERRO_NO_SUCH_AIRPORT_ID, id);
			else
				mostraAeroporto(indexAeroporto);
			
			if (!ultima)
				ultima = leProximaPalavra(id);
			else
				break;
		}
}