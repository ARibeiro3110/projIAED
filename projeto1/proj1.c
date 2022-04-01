/*
 * Projeto 1 - Sistema de gestão de voos entre aeroportos - 01/04/2022
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



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



/* Definições de constantes */


/* Tamanhos máximos de strings */
#define TAM_ID 4
#define TAM_PAIS 31
#define TAM_CIDADE 51
#define TAM_CODIGOVOO 7

/* Números máximos de aeroportos/voos suportados */
#define MAX_AEROPORTOS 40
#define MAX_VOOS 30000

/* Constantes relativas a tempo */
#define MINUTOS 60
#define HORAS 24
#define MESES 12

/* Strings que podem ser imprimidas pelos comandos */
#define AIRPORT "airport "
#define INVALID_AIRPORT_ID "invalid airport ID\n"
#define TOO_MANY_AIRPORTS "too many airports\n"
#define DUPLICATE_AIRPORT "duplicate airport\n"
#define NO_SUCH_AIRPORT_ID ": no such airport ID\n"
#define INVALID_FLIGHT_CODE "invalid flight code\n"
#define FLIGHT_ALREADY_EXISTS "flight already exists\n"
#define TOO_MANY_FLIGHTS "too many flights\n"
#define INVALID_DATE "invalid date\n"
#define INVALID_DURATION "invalid duration\n"
#define INVALID_CAPACITY "invalid capacity\n"



/* Definições de estruturas e tipos */


typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Hora {
    int horas;
    int minutos;
} Hora;

typedef struct Momento {
    Data data;
    Hora hora;
} Momento;

typedef struct Aeroporto {
    char ID[TAM_ID];
    char pais[TAM_PAIS];
    char cidade[TAM_CIDADE];
    int numVoos;
} Aeroporto;

typedef struct Voo {
    char codigoVoo[TAM_CODIGOVOO];
    char IDPartida[TAM_ID];
    char IDChegada[TAM_ID];
    Momento partida;
    Hora duracao;
    Momento chegada;
    int capacidade;
} Voo;

typedef enum Bool {
    false = 0,
    true = 1
} Bool;



/* Declarações de funções */


void a();
void l();
void v();
void p();
void c();
void t();

Bool erros_a(char ID[]);
Bool erros_v_1(Voo voo);
Bool erros_v_2(Voo voo);

void ordenar_aeroportos();
void ordenar_voos_p();
void ordenar_voos_c();

void listar_aeroporto(int pos);
void ler_listar_aeroportos();
void listar_voo(int pos, char comando);

Bool existe_aeroporto(char ID[]);
void erro_aeroporto_inexistente(char ID[]);
Bool existe_voo(char codigoVoo[], Data dataPartida);

Bool eh_digito(char c);
Bool eh_maiuscula(char c);

void ler_resto_linha();
void incrementar_numVoos(char ID[]);
Bool eh_codigo_valido(char codigoVoo[]);

Data ler_data();
Hora ler_hora();
Momento obter_momento_chegada(Momento partida, Hora duracao);

Bool eh_data_anterior(Data d1, Data d2);
Bool eh_hora_anterior(Hora h1, Hora h2);
Bool eh_momento_anterior(Momento m1, Momento m2);

Bool datas_iguais(Data d1, Data d2);

Bool eh_data_valida(Data data);
Bool eh_duracao_valida(Hora duracao);

void imprimir_data(Data d);
void imprimir_hora(Hora h);
void imprimir_momento(Momento m);



/* Variáveis Globais */


/* Vetor de Aeroportos */
Aeroporto aeroportos[MAX_AEROPORTOS];

/* Vetor de Voos */
Voo voos[MAX_VOOS]; 

/* Vetor de inteiros correspondentes aos índices dos Voos no vetor "voos" por
uma determinada ordem */
int ord_voos[MAX_VOOS]; 

/* Número de Aeroportos no vetor "aeroportos" */
int i_a;

/* Número de Voos no vetor "voos" */
int i_v;

/* Data atual */
Data data_atual; 

/* No início, a data é 1 de janeiro de 2022 */
Data data_atual = {1, 1, 2022}; 

/* Vetor de inteiros em que a cada índice de 1 a 12 corresponde o número de
dias do respetivo mês */
int dias_mes[MESES + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                           


/* Definições de funções */


/* Recebe o input de comandos. Caso seja lido o comando 'q', o programa é
terminado, e, para os restantes comandos, é chamada a função que executa a ação
referente ao comando. */
int main()
{
    char command;

    while ((command = getchar()) != 'q') {
        switch (command) {
            case 'a':
                a();
                break;
            
            case 'l':
                l();
                break;
            
            case 'v':
                v();
                break;
            
            case 'p':
                p();
                break;
            
            case 'c':
                c();
                break;
            
            case 't':
                t();
                break;
        }
    }

    return 0;
}


/* Executa a ação referente ao comando 'a': adicionar um novo aeroporto ao
sistema. */
void a()
{
    int c, i;
    Aeroporto aux;

    scanf(" %s", aux.ID);

    if(!erros_a(aux.ID)) {

        strcpy(aeroportos[i_a].ID, aux.ID);
        
        scanf(" %s ", aeroportos[i_a].pais);

        for(i = 0; (c = getchar()) != '\n'; i++)
            aeroportos[i_a].cidade[i] = c;
        
        /* Esta variável será incrementada quando for criado um Voo com partida
        no Aeroporto sendo o seu valor utilizado para listar o Aeroporto. */
        aeroportos[i_a].numVoos = 0;

        printf(AIRPORT "%s\n", aeroportos[i_a].ID);

        i_a ++;
    }

    else
        ler_resto_linha();
}



/* Executa a ação referente ao comando 'l': listar os aeroportos. */
void l()
{
    int c, i = 0;

    /* Se o comando não tiver parâmetros opcionais, lista todos os Aeroportos
    por ordem alfabética do código. */
    if((c = getchar()) == '\n') {
        ordenar_aeroportos();

        for(i = 0; i < i_a; i++)
            listar_aeroporto(i);
    }

    /* Se o comando tiver parâmetros opcionais (identificadores de aeroportos),
    os Aeroportos são listados pela ordem dos identificadores no comando. */
    else
        ler_listar_aeroportos();
}


/* Executa a ação referente ao comando 'v': adicionar um voo ou listar todos os
voos. */
void v()
{
    int c, i;
    Voo aux;
    
    /* Se o comando não tiver parâmetros opcionais, lista todos os Voos por
    ordem de criação */
    if((c = getchar()) == '\n') {
        for(i = 0; i < i_v; i++)
            listar_voo(i, 'v');
    }

    /* Se o comando tiver parâmetros opcionais, cria um novo Voo. */
    else {
        scanf("%s %s %s ", aux.codigoVoo, aux.IDPartida, aux.IDChegada);
        aux.partida.data = ler_data();
        aux.partida.hora = ler_hora();
        aux.duracao = ler_hora();
        scanf("%d", &aux.capacidade);

        if(!erros_v_1(aux) && !erros_v_2(aux)) {

            aux.chegada = obter_momento_chegada(aux.partida, aux.duracao);

            voos[i_v] = aux;

            ord_voos[i_v] = i_v;

            incrementar_numVoos(voos[i_v].IDPartida);

            i_v++;
        }
    }
}


/* Executa a ação referente ao comando 'p': listar os voos com partida de um
aeroporto. */
void p()
{
    int i;
    char ID[TAM_ID];

    scanf(" %s\n", ID);

    if(!existe_aeroporto(ID)) /* Caso de erro. */
        erro_aeroporto_inexistente(ID);

    else {
        /* Os Voos são listados por ordem de data e hora de partida. */
        ordenar_voos_p();

        for(i = 0; i < i_v; i++)
            /* Listar os Voos no vetor "voos" com "IDPartida" igual a "ID". */
            if(!strcmp(ID, voos[ord_voos[i]].IDPartida))
                listar_voo(ord_voos[i], 'p');
    }
}


/* Executa a ação referente ao comando 'c': listar os voos com chegada a um
aeroporto. */
void c()
{
    int i;
    char ID[TAM_ID];

    scanf(" %s\n", ID);

    if(!existe_aeroporto(ID)) /* Caso de erro. */
        erro_aeroporto_inexistente(ID);

    else {
        /* Os Voos são listados por ordem de data e hora de chegada. */
        ordenar_voos_c();

        for(i = 0; i < i_v; i++)
            /* Listar os Voos no vetor "voos" com "IDChegada" igual a "ID". */
            if(!strcmp(ID, voos[ord_voos[i]].IDChegada))
                listar_voo(ord_voos[i], 'c');
    }
}


/* Executa a ação referente ao comando 't': avançar a data do sistema. */
void t()
{
    Data nova_data;

    nova_data = ler_data();

    if(eh_data_valida(nova_data)) {
        data_atual = nova_data;
        imprimir_data(data_atual);
        printf("\n");
    }

    else
        printf(INVALID_DATE); /* Caso de erro. */
}


/* Recebe um identificador de aeroporto, verifica os casos de erro do comando
'a' e, caso exista algum erro, imprime a respetiva mensagem de erro e retorna
true, caso contrário, retorna false. */
Bool erros_a(char ID[])
{
    int i;

    for(i = 0; i < TAM_ID - 1; i++)
        if(!eh_maiuscula(ID[i])) {
            printf(INVALID_AIRPORT_ID);
            return true;
        }
    
    if(i_a == MAX_AEROPORTOS) {
        printf(TOO_MANY_AIRPORTS);
        return true;
    }

    if(existe_aeroporto(ID)) {
        printf(DUPLICATE_AIRPORT);
        return true;
    }
    
    return false;
}


/* Recebe um Voo, verifica os casos de erro do comando 'v' referentes ao código
de Voo, à repetição de Voos e aos aeroportos de partida e chegada e, caso
exista algum erro, imprime a respetiva mensagem de erro e retorna true, caso
contrário, retorna false. */
Bool erros_v_1(Voo voo)
{
    if(!eh_codigo_valido(voo.codigoVoo)) {
        printf(INVALID_FLIGHT_CODE);
        return true;
    }

    else if(existe_voo(voo.codigoVoo, voo.partida.data)) {
        printf(FLIGHT_ALREADY_EXISTS);
        return true;
    }

    else if(!existe_aeroporto(voo.IDPartida)) {
        erro_aeroporto_inexistente(voo.IDPartida);
        return true;
    }

    else if(!existe_aeroporto(voo.IDChegada)) {
        erro_aeroporto_inexistente(voo.IDChegada);
        return true;
    }

    else
        return false;
}


/* Recebe um Voo, verifica os casos de erro do comando 'v' referentes ao número
máximo de Voos, à data de partida, à duração e à capacidade e, caso exista
algum erro, imprime a respetiva mensagem de erro e retorna true, caso contrário,
retorna false. */
Bool erros_v_2(Voo voo)
{
    if(i_v == MAX_VOOS) {
        printf(TOO_MANY_FLIGHTS);
        return true;
    }

    else if(!eh_data_valida(voo.partida.data)) {
        printf(INVALID_DATE);
        return true;
    }

    else if(!eh_duracao_valida(voo.duracao)) {
        printf(INVALID_DURATION);
        return true;
    }

    else if(voo.capacidade < 10 || voo.capacidade > 100) {
        printf(INVALID_CAPACITY);
        return true;
    }

    else
        return false;
}


/* Modifica o vetor "aeroportos", ordenando os Aeroportos por ordem alfabética
dos seus identificadores. */
void ordenar_aeroportos()
{
    int i, j, estado;
    Aeroporto aux;

    for(i = 0; i < i_a - 1; i++) {
        estado = 1;

        for(j = 0; j < i_a - 1; j++)
            if(strcmp(aeroportos[j].ID, aeroportos[j + 1].ID) > 0) {
                aux = aeroportos[j];
                aeroportos[j] = aeroportos[j + 1];
                aeroportos[j + 1] = aux;

                estado = 0;
            }

        if(estado)
            break;
    }
}


/* Modifica o vetor "ord_voos", ordenando os inteiros, referentes a índices de
Voos no vetor "voos", por data e hora de partida dos mesmos. */
void ordenar_voos_p()
{
    int i, j, estado, aux;

    for(i = 0; i < i_v - 1; i++) {
        estado = 1;
    
        for(j = 0; j < i_v - 1; j++)
            if(eh_momento_anterior(voos[ord_voos[j + 1]].partida,
                                   voos[ord_voos[j]].partida)) {
                aux = ord_voos[j];
                ord_voos[j] = ord_voos[j + 1];
                ord_voos[j + 1] = aux;

                estado = 0;
            }

        if(estado)
            break;
    }
}


/* Modifica o vetor "ord_voos", ordenando os inteiros, referentes a índices de
Voos no vetor "voos", por data e hora de chegada dos mesmos. */
void ordenar_voos_c()
{
    int i, j, estado, aux;

    for(i = 0; i < i_v - 1; i++) {
        estado = 1;
    
        for(j = 0; j < i_v - 1; j++)
            if(eh_momento_anterior(voos[ord_voos[j + 1]].chegada,
                                   voos[ord_voos[j]].chegada)) {
                aux = ord_voos[j];
                ord_voos[j] = ord_voos[j + 1];
                ord_voos[j + 1] = aux;

                estado = 0;
            }

        if(estado)
            break;
    }
}


/* Recebe um inteiro correspondente a um índice do vetor "aeroportos" e lista
o Aeroporto existente nessa posição. */
void listar_aeroporto(int pos)
{
    printf("%s %s %s %d\n", aeroportos[pos].ID, aeroportos[pos].cidade,
                            aeroportos[pos].pais, aeroportos[pos].numVoos);
}


/* Lê um ou mais identificadores de aeroportos e lista os respetivos Aeroportos
pela mesma ordem. */
void ler_listar_aeroportos()
{
    int c, i = 0, j, estado, num_ids_listar = 0;
    char ids_listar[MAX_AEROPORTOS][TAM_ID];

    do {
        scanf("%s", ids_listar[i++]);
        num_ids_listar++;
    } while((c = getchar()) != '\n');

    for(i = 0; i < num_ids_listar; i++) {
        estado = 1;

        /* Listar os Aeroportos do vetor "aeroportos" cujos identificadores
        estão no vetor "ids_listar". */
        for(j = 0; j < i_a; j++)
            if(!strcmp(ids_listar[i], aeroportos[j].ID)) {
                estado = 0;
                listar_aeroporto(j);
                break;
            }
        
        if(estado) /* Caso de erro. */
            erro_aeroporto_inexistente(ids_listar[i]);
    }
}



/* Recebe um inteiro correspondente a um índice do vetor "voos" e um caráter
indicador da função em que esta função é chamada, que determina quais campos da
estrutura "Voo" se pretende listar, e lista tais campos do Voo existente na
posição desse índice. */
void listar_voo(int pos, char comando)
{
    printf("%s ", voos[pos].codigoVoo);

    switch (comando) {
        case 'v':
            printf("%s %s ", voos[pos].IDPartida, voos[pos].IDChegada);
            imprimir_momento(voos[pos].partida);
            break;
        
        case 'p':
            printf("%s ", voos[pos].IDChegada);
            imprimir_momento(voos[pos].partida);
            break;
        
        case 'c':
            printf("%s ", voos[pos].IDPartida);
            imprimir_momento(voos[pos].chegada);
            break;
    }

    printf("\n");
}


/* Recebe um identificador de aeroporto e retorna true caso já exista, no vetor
"aeroportos", um Aeroporto com o mesmo identificador, e false caso contrário. */
Bool existe_aeroporto(char ID[])
{
    int i;
    
    for(i = 0; i < i_a; i++)
        if(!strcmp(aeroportos[i].ID, ID))
            return true;
    
    return false;
}


/* Recebe um identificador de aeroporto e imprime o erro de aeroporto
inexistente.*/
void erro_aeroporto_inexistente(char ID[])
{
    printf("%s" NO_SUCH_AIRPORT_ID, ID);
}


/* Recebe um código de voo e uma data e retorna true caso já exista, no vetor
"voos", um Voo com os mesmos código e data de partida, e false caso contrário.*/
Bool existe_voo(char codigoVoo[], Data dataPartida)
{
    int i;

    for(i = 0; i < i_v; i++)
        if(!strcmp(voos[i].codigoVoo, codigoVoo) &&
           datas_iguais(voos[i].partida.data, dataPartida))  
            return true;

    return false;
}


/* Recebe um caráter e retorna true caso este seja um dígito, e false caso
contrário. */
Bool eh_digito(char c)
{
    return c >= '0' && c <= '9';
}


/* Recebe um caráter e retorna true caso este seja uma letra maiúscula, e false
caso contrário. */
Bool eh_maiuscula(char c)
{
    return c >= 'A' && c <= 'Z';
}


/* Lê os restantes caráteres da linha atual do input, para que a seguinte
leitura comece no início da linha seguinte. Utilizada quando os parâmetros já
lidos levam a um erro e, portanto, o resto da linha do input é irrelevante. */
void ler_resto_linha()
{
    int c;

    while((c = getchar()) != '\n')
        continue;
}


/* Recebe um identificador de aeroporto e incrementa o número de voos com
origem no respetivo Aeroporto, na sequência da criação de um novo Voo com
partida no mesmo. */
void incrementar_numVoos(char ID[])
{
    int i;
    
    for(i = 0; i < i_a; i++)
        if(!strcmp(aeroportos[i].ID, ID)) {
            aeroportos[i].numVoos++;
            break;
        }
}


/* Recebe um código de voo e retorna true caso este seja válido, ou seja, se
for uma string com duas maiúsculas seguidas de entre 1 e 4 dígitos, e false
caso contrário. */
Bool eh_codigo_valido(char codigoVoo[])
{
    int i, len_codigoVoo = strlen(codigoVoo);

    if(!eh_maiuscula(codigoVoo[0]) || !eh_maiuscula(codigoVoo[1]))
        return false;
    
    for(i = 2; i < len_codigoVoo; i++)
        if(!eh_digito(codigoVoo[i]))
            return false;

    return true;
}


/* Lê uma data no formato definido e devolve-a. */
Data ler_data()
{
    Data data;

    scanf("%d-%d-%d ", &data.dia, &data.mes, &data.ano);

    return data;
}


/* Lê uma hora no formato definido e devolve-a. */
Hora ler_hora()
{
    Hora hora;

    scanf("%d:%d ", &hora.horas, &hora.minutos);

    return hora;
}


/* Recebe o momento de partida e a duração de um Voo, e retorna o Momento em
que o mesmo chega ao destino. */
Momento obter_momento_chegada(Momento momento, Hora duracao)
{
    momento.hora.minutos += duracao.minutos;
    momento.hora.horas += duracao.horas;

    if(momento.hora.minutos >= MINUTOS) {
        momento.hora.minutos -= MINUTOS;
        momento.hora.horas++;
    }
    
    if(momento.hora.horas >= HORAS) {
        momento.hora.horas -= HORAS;
        momento.data.dia++;
    }
    
    if(momento.data.dia > dias_mes[momento.data.mes]) {
        momento.data.dia -= dias_mes[momento.data.mes];
        momento.data.mes++;
    }
    
    if(momento.data.mes > MESES) {
        momento.data.mes -= MESES;
        momento.data.ano++;
    }
    
    return momento;
}


/* Recebe duas Datas e retorna true caso a Data "d1" seja anterior à Data "d2",
e false caso contrário. */
Bool eh_data_anterior(Data d1, Data d2)
{
    return
    (d1.ano < d2.ano ||
     (d1.ano == d2.ano && (d1.mes < d2.mes || 
                           (d1.mes == d2.mes && d1.dia < d2.dia))
     )
    );
}


/* Recebe duas Horas e retorna true caso a Hora "h1" seja anterior à Hora "h2",
e false caso contrário. */
Bool eh_hora_anterior(Hora h1, Hora h2)
{
    return h1.horas < h2.horas || (h1.horas == h2.horas &&
                                   h1.minutos < h2.minutos);
}


/* Recebe duas Datas e duas Horas e retorna true caso o Momento "m1" seja
anterior ao momento "m2", e false caso contrário. */
Bool eh_momento_anterior(Momento m1, Momento m2)
{
    return
    eh_data_anterior(m1.data, m2.data) || (datas_iguais(m1.data, m2.data) &&
                                           eh_hora_anterior(m1.hora, m2.hora));
}


/* Recebe duas Datas e retorna true caso sejam iguais, e false caso contrário.*/
Bool datas_iguais(Data d1, Data d2)
{
    return d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano;
}


/* Recebe uma Data e retorna true caso esta não seja no passado nem mais de um
ano no futuro (ou seja, se "data" não for anterior a "data_atual" e "futuro"
não for anterior a "data"), e false caso contrário. */
Bool eh_data_valida(Data data)
{
    /* Data correspondente a "data_atual" mais um ano. */
    Data futuro;

    futuro = data_atual;
    futuro.ano++;

    return !eh_data_anterior(data, data_atual) &&
           !eh_data_anterior(futuro, data);
}


/* Recebe uma Hora e retorna true caso esta não seja superior a 12 horas, e
false caso contrário. */
Bool eh_duracao_valida(Hora duracao)
{
    return duracao.horas < 12 || (duracao.horas == 12 && duracao.minutos == 0);
}


/* Recebe uma Data e imprime-a no formato definido. */
void imprimir_data(Data d)
{
    printf("%02d-%02d-%d", d.dia, d.mes, d.ano);
}


/* Recebe uma Hora e imprime-a no formato definido. */
void imprimir_hora(Hora h)
{
    printf("%02d:%02d", h.horas, h.minutos);
}


/* Recebe um Momento e imprime-o no formato definido. */
void imprimir_momento(Momento m)
{
    imprimir_data(m.data);
    printf(" ");
    imprimir_hora(m.hora);
}