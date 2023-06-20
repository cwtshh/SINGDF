#ifndef bibliotecaBusca_h

#define bibliotecaBusca_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defini��es das op��es do menu
#define CONSULTAR_MINIUSINA 1
#define CONSULTAR_CONSUMIDOR 2
#define LISTAR_MINIUSINAS 3
#define LISTAR_MINIUSINAS_ORD_DECRE_ENERGIA 4
#define LISTAR_RAS_ORD_CRE_QTD_MINUSINAS 5
#define LISTAR_RAS_ORD_CRE_NUM_CTT 6
#define LISTAR_RAS_ORD_DECRE_CAPACIDADE 7
#define LISTAR_RAS_ORD_DECRE_PERCEN_ENERGIA_DISP 8
#define SAIR 9

// Defini��es para os tamanhos dos dados das miniusinas
#define TAM_MAX_CNPJ 50 // Considerando apenas alagarismos n�mericos
#define TAM_MAX_NOME_MINIUSINA 100
#define TAM_MAX_CAPACIDADE_TOTAL 100 // Apenas n�meros
#define TAM_MAX_RA 5
#define TAM_MAX_STATUS_MINIUSINA 100

// Defini��es para os tamanhos dos dados dos contratos
#define TAM_MAX_ID_CONTRATO 20 // Apenas n�meros
#define TAM_MAX_CPF 20 // Considerando apenas algarismos n�mericos
#define TAM_MAX_DATA 20 // dd/mm/aaaa.
#define TAM_MAX_ENERGIA_CTT 20


typedef struct {
    char cnpj_miniusina[TAM_MAX_CNPJ];
    char nome_miniusina[TAM_MAX_NOME_MINIUSINA];
    char capacidade_total[TAM_MAX_CAPACIDADE_TOTAL]; // Em kWh
    char id_ra[TAM_MAX_RA];
    char status_miniusina[TAM_MAX_STATUS_MINIUSINA]; // Em opera��o(funcionando) ou em implementa��o(n�o funcionando)

} Miniusina;

typedef struct {
    char id_contrato[100];
    char id_consumidor[100];
    char cnpj_miniusina[100];
    char data_inicio_contrato[100];
    char energia_contratada[100];
} Contrato;

typedef struct {
    char id_consumidor[100];
    char nome[100];
    char id_ra[100];
} Consumidor;


void buscarContratos(char cpnj[], Contrato contratos[]) {
    printf( "Contratos: \n");
    for(int i = 0; i < 11; i++) {
        if(strcmp(cpnj, contratos[i].cnpj_miniusina) == 0) {
            printf("ID Contrato: %s\n", contratos[i].id_contrato);
            printf("ID Consumidor: %s\n", contratos[i].id_consumidor);
            printf("CNPJ Miniusina: %s\n", contratos[i].cnpj_miniusina);
            printf("Data Inicio: %s\n", contratos[i].data_inicio_contrato);
            printf("Energia Contratada: %s\n", contratos[i].energia_contratada);
            printf("\n");
        }   
    }
    /* printf("Nao ha contratos para essa miniusina\n"); */
}

void buscarContratosCliente(char cnpj[], Contrato contratos[]) {
    printf( "Contratos: \n");
    for(int i = 0; i < 11; i++) {
        if(strcmp(cnpj, contratos[i].id_consumidor) == 0) {
            printf("ID Contrato: %s\n", contratos[i].id_contrato);
            printf("ID Consumidor: %s\n", contratos[i].id_consumidor);
            printf("CNPJ Miniusina: %s\n", contratos[i].cnpj_miniusina);
            printf("Data Inicio: %s\n", contratos[i].data_inicio_contrato);
            printf("Energia Contratada: %s\n", contratos[i].energia_contratada);
            printf("\n");
        }   
    }
}

void buscarMiniusina(char cnpj[], Miniusina miniusinas[]) {
    for(int i = 0; i < 11; i++) {
        if(strcmp(cnpj, miniusinas[i].cnpj_miniusina) == 0) {
            printf("CNPJ: %s\n", miniusinas[i].cnpj_miniusina);
            printf("Nome: %s\n", miniusinas[i].nome_miniusina);
            printf("Capacidade Total: %s\n", miniusinas[i].capacidade_total);
            printf("ID RA: %s\n", miniusinas[i].id_ra);
            printf("Status: %s\n", miniusinas[i].status_miniusina);
            printf("\n");
            return;

        }
    }
    printf("Miniusina não encontrada\n");
}

void buscarConsumidor(char cnpj[], Consumidor consumidores[]) {
    for(int i = 0; i < 11; i++) {

        if(strcmp(cnpj, consumidores[i].id_consumidor) == 0) {
            printf("ID Consumidor: %s\n", consumidores[i].id_consumidor);
            printf("Nome: %s\n", consumidores[i].nome);
            printf("ID RA: %s\n", consumidores[i].id_ra);
            printf("\n");
            return;

        }
    }
    printf("Consumidor não encontrado\n");
}

#endif