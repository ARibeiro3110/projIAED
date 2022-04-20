/* Afonso da Conceição Ribeiro, 102763 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "voos.h"


void mostraVoo(int index) {

	printf("%s %s %s ", _voos[index].cod_v, _voos[index].partida,
	    			    _voos[index].chegada);
	mostraData(_voos[index].data);
	printf(" ");
	mostraHora(_voos[index].hora);
	printf("\n");
}

void mostraVooPartida(int index) {

	printf("%s %s ", _voos[index].cod_v, _voos[index].chegada);
	mostraData(_voos[index].data);
	printf(" ");
	mostraHora(_voos[index].hora);
	printf("\n");
}

void mostraVooChegada(int index) {
	Hora h = converteNumHora(_voos[index].horaChegada);
	
	printf("%s %s ", _voos[index].cod_v, _voos[index].partida);
	mostraData(converteNumData(_voos[index].horaChegada));
	printf(" ");
	mostraHora(h);
	printf("\n");
}

int encontraVoo(char cod_v[], Data d) {
	int numData = converteDataNum(d);
	int i;

	for (i = 0; i < _numVoos; i++)
		if (!strcmp(cod_v, _voos[i].cod_v)
		    && numData == converteDataNum(_voos[i].data))
			return i;

	return NAO_EXISTE;
}

Bool validaCodigoVoo(char cod_v[]) {
	int i, c;

	if(!(eh_maiuscula(cod_v[0]) && eh_maiuscula(cod_v[1])))
		return FALSE;

	for(i = 2; (c = cod_v[i]) != '\0'; i++)
		if (!eh_digito(c))
			return FALSE;
	
	return TRUE;
}

Bool validaVoo(Voo v) {

	if (!validaCodigoVoo(v.cod_v))
		printf(ERRO_INVALID_FLIGHT_CODE);
	
	else if (encontraVoo(v.cod_v, v.data) != NAO_EXISTE)
		printf(ERRO_FLIGHT_ALREADY_EXISTS);
	
	else if (encontraAeroporto(v.partida) == NAO_EXISTE)
		printf("%s" ERRO_NO_SUCH_AIRPORT_ID, v.partida);
	
	else if (encontraAeroporto(v.chegada) == NAO_EXISTE)
		printf("%s" ERRO_NO_SUCH_AIRPORT_ID, v.chegada);
	
	else if (_numVoos == MAX_VOOS)
		printf(ERRO_TOO_MANY_FLIGHTS);
	
	else if (!validaData(v.data))
		printf(ERRO_INVALID_DATE);
	
	else if (!validaHora(v.duracao))
		printf(ERRO_INVALID_DURATION);
	
	else if (v.capacidade < 10)
		printf(ERRO_INVALID_CAPACITY);
	
	else
		return TRUE;
	
	return FALSE;
}

void criaVoo(Voo v) {

	_voos[_numVoos].i_voo = _numVoos;
	strcpy(_voos[_numVoos].cod_v, v.cod_v);	
	strcpy(_voos[_numVoos].partida, v.partida);	
	strcpy(_voos[_numVoos].chegada, v.chegada);	
	_voos[_numVoos].data = v.data;	
	_voos[_numVoos].hora = v.hora;	
	_voos[_numVoos].duracao = v.duracao;	
	_voos[_numVoos].capacidade = v.capacidade;
	_voos[_numVoos].horaPartida = converteDataHoraNum(_voos[_numVoos].data,
													  _voos[_numVoos].hora);
	_voos[_numVoos].horaChegada = _voos[_numVoos].horaPartida +
							      converteHoraNum(_voos[_numVoos].duracao);
	_voos[_numVoos].primeira = NULL;
	
	_numVoos++;
}

void adicionaListaVoos() {
	Voo v;
	int i;

	if (leProximaPalavra(v.cod_v))
		for (i = 0; i < _numVoos; i++)
			mostraVoo(i);
	
	else {
		leProximaPalavra(v.partida);
		leProximaPalavra(v.chegada);
		v.data = leData();
		v.hora = leHora();
		v.duracao = leHora();
		scanf("%d", &v.capacidade);
		leAteFimDeLinha();

		if (validaVoo(v))
			criaVoo(v);
	}
}

Bool cmpVoosPartida(int a, int b) {
	return (_voos[a].horaPartida > _voos[b].horaPartida);
}

Bool cmpVoosChegada(int a, int b) {
	return (_voos[a].horaChegada > _voos[b].horaChegada);
}

void listaVoosPartida() {
	int indexVoos[MAX_VOOS], i, n = 0;
	char partida[MAX_CODIGO_AEROPORTO];

	lePalavraAteFimDeLinha(partida);

	if (encontraAeroporto(partida) == NAO_EXISTE)
		printf("%s" ERRO_NO_SUCH_AIRPORT_ID, partida);

	for (i = 0; i < _numVoos; i++)
		if (!strcmp(_voos[i].partida, partida))
			indexVoos[n++] = i;

	bubbleSort(indexVoos, n, cmpVoosPartida);

	for (i = 0; i < n; i++)
		mostraVooPartida(indexVoos[i]);
}

void listaVoosChegada() {
	int indexVoos[MAX_VOOS], i, n = 0;
	char chegada[MAX_CODIGO_AEROPORTO];

	lePalavraAteFimDeLinha(chegada);

	if (encontraAeroporto(chegada) == NAO_EXISTE)
		printf("%s" ERRO_NO_SUCH_AIRPORT_ID, chegada);

	for (i = 0; i < _numVoos; i++)
		if (!strcmp(_voos[i].chegada, chegada))
			indexVoos[n++] = i;

	bubbleSort(indexVoos, n, cmpVoosChegada);

	for (i = 0; i < n; i++)
		mostraVooChegada(indexVoos[i]);
}