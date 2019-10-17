#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void funcao(int qntnomes, char** lista);

int main(){

	int qntnomes, i;
	char **lista;

	scanf("%d", &qntnomes);
	lista = (char **)malloc(sizeof(char *) * qntnomes);

	for(i = 0; i < qntnomes; i++){
		lista[i] = (char *)malloc(sizeof(char) * 10);
		scanf("%s", lista[i]);
	}

	funcao(qntnomes, lista);

	for(i = 0; i < qntnomes; i++){
		printf("\n%s", lista[i]);
	}

	return 0;
}

void funcao(int qntnomes, char** lista){
	int i, j, min;
	char aux[10];

	for(i = 0; i < qntnomes; i++){
		min = i;
		for(j = i + 1; j < qntnomes; j++){
			if(strlen(lista[j]) < strlen(lista[min])){
				min = j;
			}
		}
		strcpy(aux, lista[min]);
		strcpy(lista[min], lista[i]);
		strcpy(lista[i], aux);
	}
}