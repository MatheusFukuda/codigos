#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agenda{
    char nome[10];
    int telefone;
}agenda;

typedef struct var{
    int i, Npessoas, op;
}var;

void *pbuffer;
var *aux;
agenda *aponta;

void Insere ();
void Imprimir ();

int main (){

    pbuffer = malloc(sizeof(var));
    if(pbuffer == NULL){
        printf("\nERRO\n");
    }
    aux = pbuffer;
    aux->op = 0;
    aux->Npessoas = 0;
    aux->i = 0;


    while(284){
        printf("\n");
        printf("Agenda: \n");
        printf("1: Insere\n");
        printf("2: Lista\n");
        printf("3: Busca\n");
        printf("4: Apaga\n");
        printf("5: SAIR\n");
        printf("Op.: ");
        scanf("%d", &aux->op);
        getchar();

        switch (aux->op){
            case 1: (aux->Npessoas)++;
            Insere();
            break;
            case 2: if(aux->Npessoas == 0){
                printf("\n");
                printf("VAZIO\n");
            }else{
                Imprimir();
            }
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            printf("\n");
            printf("----------------SAINDO----------------\n");
            printf("\n");
            exit(0); 
            free(pbuffer);
            break;
            default:
            printf("\n");
            printf("== Op. Invalido ==\n");
            printf("\n");
            break;
        }
    }
    return 0;
}
void Insere (){
    pbuffer = realloc(pbuffer, sizeof(var) + sizeof(agenda)*(aux->Npessoas));
    if(pbuffer == NULL){
        printf("\n");
        printf("ERRO\n");
    }
    aux = pbuffer;
    aponta = pbuffer + sizeof(var) + sizeof(agenda)*(aux->Npessoas) - sizeof(agenda);
    printf("\n");
    printf("----------------ADICIONANDO PESSOAS----------------\n\n\n");
    printf("Digite um nome: ");
    scanf("%s", aponta->nome);
    printf("\n");
    printf("Digite um telefone: ");
    scanf("%d", &aponta->telefone);
}

void Imprimir (){
    aponta = pbuffer + sizeof(var);
    for (aux->i = 0; (aux->i)<(aux->Npessoas); (aux->i)++){
        printf("----------------LISTANDO PESSOAS----------------\n\n");
        printf("Nome: %s\n", aponta->nome);
        printf("Telefone: %d\n", aponta->telefone);
        printf("------------------------------------------------\n\n");
        aponta++;
    }
}

void Buscar (){

}
