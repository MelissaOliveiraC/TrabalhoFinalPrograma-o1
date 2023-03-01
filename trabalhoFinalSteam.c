#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

//caminho para os arquivos
char FILENAME[] = "Arquivo.dat";
char FILENAME_AUX[] = "Auxiliar.dat";

typedef struct{
    int id; //do usuario
    char nomeJogo[TAM];
    char tipo[TAM];
    char plataforma[TAM];
    float preco;
    int ano;
    char fabricante[TAM];
    int classificacao;
    int rating;
}TIPOcadastro;

void troca_dados(){
    TIPOcadastro aux;

    fclose(fopen(FILENAME, "wb"));
    FILE *arquivo = fopen(FILENAME, "ab");
    FILE *arquivo2 = fopen(FILENAME_AUX, "rb");

    if (arquivo == NULL || arquivo2 == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo2)){
        fwrite(&aux, sizeof(TIPOcadastro), 1, arquivo);
    }

    fclose(arquivo2);
    fclose(arquivo);
}

int cadastrar(){
    int result;
    TIPOcadastro aux;
    FILE *arquivo = fopen(FILENAME, "ab");

    if (arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }

    puts("\n\t { CADASTRO } \n\n");

    printf("ID: ");
    scanf("%d", &aux.id);
    getchar();

    printf("Nome do Jogo: ");
    fgets(aux.nomeJogo, 50, stdin);
    aux.nomeJogo[strlen(aux.nomeJogo) - 1] = '\0';

    printf("Tipo: ");
    fgets(aux.tipo, 50, stdin);
    aux.tipo[strlen(aux.tipo) - 1] = '\0';

    printf("Ano de lancamento: ");
    scanf("%d", &aux.ano);
    getchar();

    printf("Fabricante: ");
    fgets(aux.fabricante, 50, stdin);
    aux.fabricante[strlen(aux.fabricante) - 1] = '\0';

    printf("Plataforma: ");
    fgets(aux.plataforma, 50, stdin);
    aux.plataforma[strlen(aux.plataforma) - 1] = '\0';

    printf("Classificacao: ");
    scanf("%d", &aux.classificacao);

    printf("Preco: ");
    scanf("%f", &aux.preco);


    result = fwrite(&aux, sizeof(TIPOcadastro), 1, arquivo);//retorna 1
    fclose(arquivo);

    return result;
}

void listar(){
    char letra;
    TIPOcadastro aux;
    FILE *arquivo = fopen(FILENAME, "rb");

    if (arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo)){
        printf("Id: %d\n", aux.id);
        printf("Nome do Jogo: %s\n", aux.nomeJogo);
        printf("Tipo: %s\n", aux.tipo);
        printf("Ano: %d\n", aux.ano);
        printf("Plataforma: %s\n", aux.plataforma);
        printf("Classificacao: %d\n", aux.classificacao);
        printf("Preco: %.2f\n", aux.preco);
        printf("Fabricante: %s\n", aux.fabricante);
        printf("\n");
    }
    system("pause");
    system("cls");
}

void listarAux(){
    TIPOcadastro aux;
    FILE *arquivo = fopen(FILENAME, "rb");

    if (arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo)){
        printf("Id: %d\n", aux.id);
        printf("\n");
    }
}

void consultar(){
    TIPOcadastro aux;
    int n, status = 0;
    FILE *arquivo = fopen(FILENAME, "rb");

    if (arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    system("cls");
    listarAux();
    puts("\n\t { CONSULTA POR REGISTRO } \n\n");

    printf("Digite o ID desejado: \n\n--> ");
    scanf("%d", &n);
    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo)){
        if(n == aux.id){
            status = 1;
            break;
        }
    }
    if(status){
        printf("Id: %d\n", aux.id);
        printf("Nome do Jogo: %s\n", aux.nomeJogo);
        printf("Tipo: %s\n", aux.tipo);
        printf("Ano: %d\n", aux.ano);
        printf("Plataforma: %s\n", aux.plataforma);
        printf("Classificacao: %d\n", aux.classificacao);
        printf("Preco: %.2f\n", aux.preco);
        printf("Fabricante: %s\n", aux.fabricante);
        printf("\n");
    }else{
        printf("\nRegistro nao encontrado!\n\n");
    }
    system("pause");
}

void alterar(){
    fclose(fopen(FILENAME_AUX, "wb"));
    TIPOcadastro aux, aux2;
    int n, status = 0, result;
    FILE *arquivo = fopen(FILENAME, "rb");
    FILE *arquivo2 = fopen(FILENAME_AUX, "ab");

    if (arquivo == NULL || arquivo2 == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    system("cls");
    listarAux();
    puts("\n\t { ALTERACAO DE REGISTRO } \n\n");

    printf("Digite o ID desejado: \n\n--> ");
    scanf("%d", &n);
    getchar();

    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo)){
        if(n == aux.id){
            aux2.id = aux.id;
            printf("\nNome do Jogo: ");
            fgets(aux2.nomeJogo, 50, stdin);
            aux2.nomeJogo[strlen(aux2.nomeJogo) - 1] = '\0';

            printf("Tipo: ");
            fgets(aux2.tipo, 50, stdin);
            aux2.tipo[strlen(aux2.tipo) - 1] = '\0';

            printf("Plataforma: ");
            fgets(aux2.plataforma, 50, stdin);
            aux2.plataforma[strlen(aux2.plataforma) - 1] = '\0';

            printf("Ano de lancamento: ");
            scanf("%d", &aux2.ano);
            getchar();

            printf("Fabricante: ");
            fgets(aux2.fabricante, 50, stdin);
            aux2.fabricante[strlen(aux2.fabricante) - 1] = '\0';

            printf("Classificacao: ");
            scanf("%d", &aux2.classificacao);

            printf("Preco: ");
            scanf("%f", &aux2.preco);


            result = fwrite(&aux2, sizeof(TIPOcadastro), 1, arquivo2);
            continue;
        }else{
            fwrite(&aux, sizeof(TIPOcadastro), 1, arquivo2);
            result = 0;
        }
    }

    if(result){
        printf("\nRegistro alterado com sucesso!\n\n");
    } else {
        printf("\nRegistro nao encontrado!\n\n");
    }

    fclose(arquivo2);
    fclose(arquivo);
    troca_dados();//atualiza os dados do arq 1

    system("pause");
}

void remover(){
    fclose(fopen(FILENAME_AUX, "wb"));
    TIPOcadastro aux, aux2;
    int n, status = 0, flag=0;
    FILE *arquivo = fopen(FILENAME, "rb");
    FILE *arquivo2 = fopen(FILENAME_AUX, "ab");
    if (arquivo == NULL || arquivo2 == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
        exit(1);
    }
    system("cls");
    listarAux();

    puts("\n\t { REMOCAO DE REGISTRO } \n\n");

    printf("Digite o ID desejado: \n\n--> ");
    scanf("%d", &n);
    getchar();

    while(fread(&aux, sizeof(TIPOcadastro), 1, arquivo)){
        if(n == aux.id){
            flag = 1;
            continue;
        } else {
            fwrite(&aux, sizeof(TIPOcadastro), 1, arquivo2); // para dados de arq1 para o arq2
        }
    }

    if(flag){
        printf("\nRegistro excluido com sucesso!\n\n");
    } else {
        printf("\nRegistro nao encontrado!\n\n");
    }
    fclose(arquivo2);
    fclose(arquivo);
    troca_dados();

    system("pause");
}

void escritaSteam(){
printf("|-------------------------|\n");
printf("|  { S . T . E . A . M }  |\n");
printf("|-------------------------|\n\n");

}

int main(){
    int opcMenu;
    int id;

    puts("\nINICIANDO STEAM... ... ...\n");
    do{
        sleep(1);
        escritaSteam();
        printf("\n0 -> SAIR\n1 -> EXIBIR LISTA DE REGISTROS\n2 -> CADASTRAR\n3 -> CONSULTAR\n4 -> REMOVER\n5 -> ALTERAR\n");
        printf("\n\n--> ");
        scanf("%d", &opcMenu);
        getchar();

        switch(opcMenu){

            case 1:
                system("cls");
                listar();
                system("cls");
                break;
            case 2:
                system("cls");
                cadastrar();
                system("cls");
                break;
            case 3:
                system("cls");
                consultar();
                system("cls");
                break;
            case 4:
                system("cls");
                remover();
                system("cls");
                break;
            case 5:
                system("cls");
                alterar();
                system("cls");
                break;

            default:
                if(opcMenu != 0){
                    printf("\nOpcao Invalida!\n");
                }
        }
    }while(opcMenu != 0);

    puts("\nFINALIZANDO STEAM... ... ...\n");
    sleep(2);

    return 0;
}
