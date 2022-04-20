/* Afonso da Conceição Ribeiro, 102763 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reservas.h"


/* Recebe a hashtable das Reservas e executa a ação referente ao comando 'r':
adicionar uma reserva ou listar as reservas de um voo. */
void adicionaListaReservas(Reserva *_reservas) {
	int c, len_cod_r, i_voo, numPassageiros;
	char cod_v[MAX_CODIGO_VOO], *cod_r, aux_cod_r[MAX_INSTRUCAO];
	Data data;
	Reserva r;
	
	leProximaPalavra(cod_v);
	
	i_voo = encontraVoo(cod_v, data = leData());

	 /* Se o comando tiver parâmetros opcionais, adiciona uma Reserva. */
	if ((c = getchar()) != '\n') {
		scanf("%s %d", aux_cod_r, &numPassageiros);
		len_cod_r = strlen(aux_cod_r);

		cod_r = (char *) _malloc(sizeof(char) * (len_cod_r + 1), _reservas);
		strcpy(cod_r, aux_cod_r);

		if (validaReserva(cod_v, data, cod_r, numPassageiros, len_cod_r, i_voo,
						  _reservas)) {
			r = novaReserva(i_voo, cod_r, numPassageiros, _reservas);
			insereReservaOrdenada(r, i_voo);
			STinsert(r, _reservas);
			_voos[i_voo].capacidade -= numPassageiros;
		}
		
		else 
			_free(cod_r);
	}

	/* Se o comando não tiver parâmetros opcionais, listas as Reservas de um
	Voo. */	
	else if (validaVooReserva(cod_v, data, i_voo))
		mostraReservas(_voos[i_voo].primeira);
}

/* Recebe os campos necessários à criação de uma Reserva, verifica os casos de
erro referentes aos mesmos e, caso exista algum erro, imprime a respetiva
mensagem de erro e retorna FALSE, caso contrário, retorna TRUE. */
Bool validaReserva(char cod_v[], Data d, char *cod_r, int numPassageiros,
				   int len_cod_r, int i_voo, Reserva *_reservas) {
	
	if (!validaCodigoReserva(cod_r, len_cod_r))
		printf(ERRO_INVALID_RESERVATION_CODE);
	
	else if (i_voo == NAO_EXISTE)
		printf("%s" ERRO_FLIGHT_DOES_NOT_EXIST, cod_v);
	
	else if (encontraReserva(cod_r, _reservas) != NULL)
		printf("%s" ERRO_RESERVATION_ALREADY_USED, cod_r);
	
	else if (_voos[i_voo].capacidade < numPassageiros)
		printf(ERRO_TOO_MANY_RESERVATIONS);
	
	else if (!validaData(d))
		printf(ERRO_INVALID_DATE);
	
	else if (numPassageiros <= 0)
		printf(ERRO_INVALID_PASSENGER_NUMBER);
	
	else
		return TRUE;
	
	return FALSE;

}

/* Recebe um código de reserva e o seu tamanho e retorna TRUE caso este seja
válido, ou seja, se for uma string apenas com letras maiúsculas e dígitos e de
tamanho igual ou superior ao tamanho mínimo, e FALSE caso contrário. */
Bool validaCodigoReserva(char *cod_r, int len_cod_r) {
	int i, c;

	if (len_cod_r < TAM_CODIGO_RESERVA)
		return FALSE;
	
	for (i = 0; (c = cod_r[i]) != '\0'; i++)
		if (!(eh_maiuscula(c) || eh_digito(c)))
			return FALSE;

	return TRUE;
}

/* Recebe um código de reserva e a hashtable das Reservas e retorna a Reserva
da hashtable com o mesmo código, ou NULL, caso não seja encontrada nenhuma. */
Reserva encontraReserva(char *cod_r, Reserva *_reservas) {
	return STsearch(cod_r, _reservas);
}

/* Recebe um índice do vetor "_voos", um código de reserva e um inteiro
correspondente ao número de passageiros e cria e retorna a Reserva com tais
campos. */
Reserva novaReserva(int i_voo, char *cod_r, int numPassageiros,
					Reserva *_reservas) {
	Reserva r = (Reserva) _malloc(sizeof(struct nodeReserva), _reservas);

	r->anterior = NULL;
	r->voo = &_voos[i_voo];
	r->cod_r = cod_r;
	r->numPassageiros = numPassageiros;
	r->seguinte = NULL;
	
	return r;
}

/* Recebe uma Reserva e um índice do vetor "_voos" e insere-a, por ordem
lexicográfica dos códigos de reserva, na lista de Reservas do respetivo Voo. */
void insereReservaOrdenada(Reserva nova_reserva, int i_voo) {
	Reserva aux;

	/* Caso o Voo ainda não tenha reservas. */
	if (_voos[i_voo].primeira == NULL)
		_voos[i_voo].primeira = nova_reserva;

	/* Caso a nova reserva fique antes da atual primeira reserva do Voo, pela
	ordem lexicográfica dos códigos de reserva. */
	else if (strcmp(nova_reserva->cod_r, _voos[i_voo].primeira->cod_r) < 0) {
		_voos[i_voo].primeira->anterior = nova_reserva;
		nova_reserva->seguinte = _voos[i_voo].primeira;
		_voos[i_voo].primeira = nova_reserva;
	}

	/* Caso contrário. */
	else {
		aux = _voos[i_voo].primeira;

		while (aux->seguinte != NULL
			   && strcmp(aux->seguinte->cod_r, nova_reserva->cod_r) < 0)
			aux = aux->seguinte;
		
		nova_reserva->seguinte = aux->seguinte;

		/* Caso a nova reserva não fique em úlimo lugar. */
		if (aux->seguinte != NULL)
			nova_reserva->seguinte->anterior = nova_reserva;

		aux->seguinte = nova_reserva;
		nova_reserva->anterior = aux;
	}
}

/* Recebe os campos necessários à listagem das Reservas de um Voo, verifica os
casos de erro referentes aos mesmos e, caso exista algum erro, imprime a
respetiva mensagem de erro e retorna FALSE, caso contrário, retorna TRUE. */
Bool validaVooReserva(char cod_v[], Data data, int i_voo) {

	if (i_voo == NAO_EXISTE)
		printf("%s" ERRO_FLIGHT_DOES_NOT_EXIST, cod_v);
	
    else if (!validaData(data))
		printf(ERRO_INVALID_DATE);
	
    else
		return TRUE;
	
    return FALSE;
}

/* Recebe a head de uma lista de Reservas e lista todas as Reservas da mesma. */
void mostraReservas(Reserva head) {
	Reserva aux;

	for(aux = head; aux != NULL; aux = aux->seguinte)
		mostraReserva(aux);
}

/* Recebe uma Reserva e lista-a. */
void mostraReserva(Reserva r) {
	printf("%s %d\n", r->cod_r, r->numPassageiros);
}


/* Recebe a hashtable das Reservas e executa a ação referente ao comando 'e':
eliminar voos ou reserva. */
void eliminaVoosReserva(Reserva *_reservas) {
	char *codigo, aux_codigo[MAX_INSTRUCAO];
	Reserva r;
	int len_codigo;

	scanf(" %s", aux_codigo);
	len_codigo = strlen(aux_codigo);

	codigo = (char *) _malloc(sizeof(char) * (len_codigo + 1), _reservas);
	strcpy(codigo, aux_codigo);

	/* Caso o tamanho do código, inferior ao tamanho mínimo de um código de
	reserva, seja superior ao tamanho máximo de um código de voo, a função
	eliminaVoos() imprime a mensagem de erro. */
	if (len_codigo < TAM_CODIGO_RESERVA)
		eliminaVoos(codigo, _reservas);

	/* Caso não seja encontrada uma reserva com tal código de reserva, a
	função eliminaReserva() imprime a mensagem de erro. */
	else {
		r = encontraReserva(codigo, _reservas);
		if (r != NULL)
			STdelete(codigo, _reservas);
		eliminaReserva(r);
	}

	_free(codigo);
}

/* Recebe um código de voo e a hashtable das reservas e, caso existam, no vetor
"_voos", Voos com tal código, elimina-os e liberta a memória associada aos
mesmos, caso contrário, imprime a mensagem de erro. */
void eliminaVoos(char *cod_v, Reserva *_reservas) {
	int i, j;
    Bool found = FALSE;

	for (i = 0; i < _numVoos; i++)
		if(!strcmp(_voos[i].cod_v, cod_v)) {
			libertaVoo(i, _reservas);

			for (j = i; j < _numVoos - 1; j++) 
				_voos[j] = _voos[j + 1];

			found = TRUE;
			i--;
			_numVoos--;
		}
	
	if (!found)
		printf(ERRO_NOT_FOUND);
}

/* Recebe um índice do vetor "_voos" e a hashtable das Reservas e elimina todas
as Reservas da hashtable associadas ao Voo com tal índice, bem como a lista de
Reservas do Voo. */
void libertaVoo(int i_voo, Reserva *_reservas) {
	Reserva aux;
	char *cod_r;

	while (_voos[i_voo].primeira != NULL) {
		cod_r = _voos[i_voo].primeira->cod_r;
		STdelete(cod_r, _reservas);
		aux = _voos[i_voo].primeira;
		_voos[i_voo].primeira = _voos[i_voo].primeira->seguinte;
		_free(aux->cod_r);
		_free(aux);
	}
}

/* Recebe uma Reserva e elimina-a da lista de Reservas do respetivo Voo. */
void eliminaReserva(Reserva r) {
	int i_voo;

	if (r == NULL)
        printf(ERRO_NOT_FOUND);

    else {
		i_voo = r->voo->i_voo;
        _voos[i_voo].capacidade += r->numPassageiros;

        /* Caso a reserva a eliminar seja a primeira. */
        if (_voos[i_voo].primeira->cod_r == r->cod_r)
            _voos[i_voo].primeira = r->seguinte;

        /* Caso a reserva a eliminar não seja a última. */
        if (r->seguinte != NULL)
            r->seguinte->anterior = r->anterior;

        /* Caso a reserva a eliminar não seja a primeira. */
        if (r->anterior != NULL)
            r->anterior->seguinte = r->seguinte;

        _free(r->cod_r);
        _free(r);
    }
}


/* Liberta toda a memórica alocada para criação de reservas, bem como a
hashtable das mesmas. */
void libertaMemoria(Reserva *_reservas) {
	int i;

	if(_reservas != NULL) {
		for(i = 0; i < _numVoos; i++)
			libertaVoo(i, _reservas);
		
		_free(_reservas);
	}
}