/* Afonso da Conceição Ribeiro, 102763 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data_hora.h"


Data leData() {
	Data d;
	scanf("%d-%d-%d", &d.dia, &d.mes, &d.ano);
	return d;
}

Hora leHora() {
	Hora h;
	scanf("%d:%d", &h.hora, &h.minuto);
    return h;
}

void mostraData(Data d) {
	printf("%02d-%02d-%04d", d.dia, d.mes, d.ano);
}

void mostraHora(Hora h) {
	printf("%02d:%02d", h.hora, h.minuto);
}

int converteDataNum(Data d) {
	return (d.ano - ANO_INICIO) * DIAS_ANO + _diasMesAc[d.mes - 1] + d.dia - 1;
}

int converteHoraNum(Hora h) {
	return (h.hora * MINUTOS_HORA) + h.minuto;
}

int converteDataHoraNum(Data d, Hora h) {
	return converteDataNum(d) * MINUTOS_DIA + converteHoraNum(h);
}

Data converteNumData(int num) {
	Data d;
	int i = 0;
    
	num = (num - (num % MINUTOS_DIA)) / MINUTOS_DIA;
	d.ano = (num / DIAS_ANO) + ANO_INICIO;
	num = num - ((d.ano - ANO_INICIO) * DIAS_ANO);
	while (i <= 11 && num >= _diasMesAc[i])
        i++;
	d.mes = i;
	d.dia = num - _diasMesAc[i - 1] + 1;

	return d;
}

Hora converteNumHora(int num) {
	Hora h;
	h.minuto = num % MINUTOS_HORA;
	h.hora = ((num - h.minuto) / MINUTOS_HORA) % HORAS_DIA;
	return h;
}

Bool validaData(Data d) {
	int numData = converteDataNum(d);
	Data proximoAno = _hoje;

	proximoAno.ano++;
	
    return !(numData < converteDataNum(_hoje)
             || numData > converteDataNum(proximoAno));
}

Bool validaHora(Hora h) {
	return h.hora < 12 || (h.hora == 12 && h.minuto == 0);
}

void alteraData() {
	Data d;

	d = leData();
	leAteFimDeLinha();

	if (!validaData(d))
		printf(ERRO_INVALID_DATE);
	
	else {
		_hoje = d;
		mostraData(_hoje);
		printf("\n");
	}
}