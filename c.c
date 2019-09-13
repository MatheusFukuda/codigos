#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct agenda{
        char nome[90];
        int telefone;
        struct agenda *prox;
    }agenda;

struct agenda *cria (void);
void insere_nomes(agenda *idk);
void lista_agenda(agenda *idk);

int main(){

    agenda *idk;
    idk = cria();

    int op;

    do{
        printf("Digite uma opcao: \n1: Grava um nome\n2: Lista os nomes gravados\n3: SAIR\nOP: ");
        scanf("%d", &op);
        switch(op){
            case 1: insere_nomes(idk);
            break;
            case 2: lista_agenda(idk);
            break;
            case 3: printf("\n-----FIM-----\n");
            break;
            default: printf("ERRO\n");
            break;
        }
    }while(op != 3);
    return 0;
}
struct agenda *cria (void){
    agenda *cab;
    
    cab=(agenda *)malloc(sizeof(agenda));
    cab->prox = NULL;

    return cab;
}

void insere_nomes(agenda *idk){
    int i = 0;
    agenda *ini, *fim;

    ini=(agenda *)malloc(sizeof(agenda));
    printf("nome: ");
    scanf("%s", ini->nome);
    printf("telefone: ");
    scanf("%d", &ini->telefone);
    for(fim = idk; fim->prox != NULL; fim = fim->prox);
    ini->prox = fim->prox;
    fim->prox = ini;
}
void lista_agenda (agenda *idk){
    agenda *tsipn;

        printf("\n");
		printf("nome: %s\n", tsipn->nome);
		printf("telefone: %d\n", tsipn->telefone);
        printf("\n");

	for(tsipn = idk->prox; idk->prox != NULL; idk = idk->prox)
        printf("\n");
		printf("nome: %s\n", tsipn->nome);
		printf("telefone: %d\n", tsipn->telefone);
        printf("\n");
}