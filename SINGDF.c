#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")

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

/* struct Miniusina {
    char cnpj_miniusina[TAM_MAX_CNPJ];
    char nome_miniusina[TAM_MAX_NOME_MINIUSINA];
    char capacidade_total[TAM_MAX_CAPACIDADE_TOTAL]; // Em kWh
    char id_ra[TAM_MAX_RA];
    char status_miniusina[TAM_MAX_STATUS_MINIUSINA]; // Em opera��o(funcionando) ou em implementa��o(n�o funcionando)

}; */

typedef struct {
    char cnpj_miniusina[TAM_MAX_CNPJ];
    char nome_miniusina[TAM_MAX_NOME_MINIUSINA];
    char capacidade_total[TAM_MAX_CAPACIDADE_TOTAL]; // Em kWh
    char id_ra[TAM_MAX_RA];
    char status_miniusina[TAM_MAX_STATUS_MINIUSINA]; // Em opera��o(funcionando) ou em implementa��o(n�o funcionando)

} Miniusina;


/* id_contrato;id_consumidor;cnpj_miniusina;data_inicio_contrato;data_termino_contrato;energia_contratada */
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

int validarCpf(char cnpj[]) {
    int sm, i, r, num, mult;
    char dig13, dig14;
    printf("Informe o valor do CNPJ:\n");

    // calcula o 1o. digito verificador do CNPJ
    sm = 0; mult = 2;
    for (i=11; i>=0; i--) {
        num = cnpj[i] - 48;	// transforma o caracter '0' no inteiro 0
                // (48 eh a posição de '0' na tabela ASCII)
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10)
        mult = 2;
    }
    r = sm % 11;
    if ((r == 0) || (r == 1))
        dig13 = '0';
    else
        dig13 = (11 - r) + 48;

    // calcula o 2o. digito verificador do CNPJ
    sm = 0; mult = 2;
    for (i=12; i>=0; i--) {
        num = cnpj[i] - 48;
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10)
        mult = 2;
    }
    r = sm % 11;
    if ((r == 0) || (r == 1))
        dig14 = '0';
    else
        dig14 = (11 - r) + 48;

    // compara os dígitos calculados com os dígitos informados
    if ((dig13 == cnpj[12]) && (dig14 == cnpj[13]))
        return 0;
    else
        return 1;

}

int validarCnpj(char cnpj[]) {
    if(strlen(cnpj) <= 20) {
        return 0;
    }
    return 1;
}


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


void menu(){
    printf("Menu de Opcoes\n");
    printf("1) Consultar miniusina cadastrada\n");
    printf("2) Consultar consumidor cadastrado\n");
    printf("3) Listar miniusinas cadastradas\n");
    printf("4) Listar as miniusinas em operacao por ordem decrescente de capacidade de geracao de energia\n");
    printf("5) Listar as RAs por ordem descrescente de quantidade de miniusinas\n");
    printf("6) Listar as RAs por ordem crescente de numero de contratos\n");
    printf("7) listar as RAs por ordem decrescente de capacidade de geracao\n");
    printf("8) Listar as RAs por ordem decrescente de percentual de energia disponivel\n");
    printf("9) Sair do programa\n");

}

void parseCsvContratos(FILE *arquivo, Contrato contratos[]) {
    int i = 0;
    char primeira_linha[1000];
    fscanf(arquivo, "%[^\n]", primeira_linha);
    while(i < 11) {
        fscanf(arquivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]",
            contratos[i].id_contrato,
            contratos[i].id_consumidor,
            contratos[i].cnpj_miniusina,
            contratos[i].data_inicio_contrato,
            contratos[i].energia_contratada
        );
        i++;
    }
}

void parseCsvMiniusinas(FILE *arquivo, Miniusina miniusinas[]) {
    int i = 0;
    char primeira_linha[1000];
    fscanf(arquivo, "%[^\n]\n", primeira_linha);
    while(!feof(arquivo)){
        //Ler uma linha do arquivo, salvando os dados na struct miniusina
        fscanf(arquivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            miniusinas[i].cnpj_miniusina, 
            miniusinas[i].nome_miniusina, 
            miniusinas[i].capacidade_total, 
            miniusinas[i].id_ra, 
            miniusinas[i].status_miniusina
        );
        i++;
    }

}

void parseConsumidores(FILE *arquivo, Consumidor consumidores[]){
    int i = 0;
    char primeira_linha[1000];
    fscanf(arquivo, "%[^\n]\n", primeira_linha);
    while(!feof(arquivo)){
        fscanf(arquivo, "%[^;];%[^;];%[^\n]", 
            consumidores[i].id_consumidor, 
            consumidores[i].nome, 
            consumidores[i].id_ra
        );
        i++;
    }

}

int main() {
    // abrindo arquivos
    FILE *arquivos_miniusinas;
    FILE *arquivos_contratos;
    FILE *arquivos_consumidores;

    arquivos_miniusinas = fopen("miniusinas.csv", "r");
    if(!arquivos_miniusinas) {
        printf("Erro ao abrir o arquivo de Miniusinas\n");
        return 1;
    }

    arquivos_contratos = fopen("contratos.csv", "r");
    if(!arquivos_contratos) {
        printf("Erro ao abrir o arquivo de Contratos\n");
        return 1;
    }
    arquivos_consumidores = fopen("consumidores.csv", "r");
    if(!arquivos_consumidores) {
        printf("Erro ao abrir o arquivo de Consumidores\n");
        return 1;
    }

    // Variaveis para armazenar os dados
    Miniusina miniusinas[11];
    Contrato contratos[11];
    Consumidor consumidores[11];

    parseCsvContratos(arquivos_contratos, contratos);
    parseCsvMiniusinas(arquivos_miniusinas, miniusinas);
    parseConsumidores(arquivos_consumidores, consumidores);

    fclose(arquivos_contratos);
    fclose(arquivos_miniusinas);
    fclose(arquivos_consumidores);

    for(int i = 0; i < 11; i++) {
        printf("%s", consumidores[i].id_consumidor);
    }

    int opcao;

    while(opcao != SAIR) {

        menu();
        scanf("%d", &opcao);
        char cnpj[50];
        char new_cnpj[50] = "\n";
        

        switch(opcao){
            case CONSULTAR_MINIUSINA: //1
                fflush(stdin);
                
                printf("Digite o CNPJ da miniusina: ");
                scanf("%s", cnpj);

                if(validarCnpj(cnpj) == 1) {
                    printf("CNPJ invalido\n");
                    break;
                }

                
                strcat(new_cnpj, cnpj);

                buscarMiniusina(new_cnpj, miniusinas);
                buscarContratos(cnpj, contratos);
                
                fflush(stdin);

            case CONSULTAR_CONSUMIDOR:
                fflush(stdin);

                printf("Digite o CPF ou CNPJ do consumidor: ");
                scanf("%s", cnpj);

                strcat(new_cnpj, cnpj);

                buscarConsumidor(new_cnpj, consumidores);
                buscarContratosCliente(cnpj, contratos);


            case SAIR:
                printf("Saindo do programa...\n");

                break;

        }
    }

    return 1;


    




    
    


    return 0;
}


