#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void main(){
	
	//Cria uma semente
	srand(time(NULL));
	
	//Cria um struct como sendo a tabela a ser criada
	struct tabela{
		unsigned int sexo : 1;
		unsigned int idade : 7;
		unsigned int renda : 10;
		unsigned int escolaridade : 2;
		unsigned int idioma : 12;
		unsigned int pais : 8;
		unsigned int localizador : 24;
	};
	
	//Cria uma ponteira e abre um arquivo para escrita
	FILE * fp;
	fp = fopen("database.dat", "wb");
	
	//Cria um array de 100000 posições de struct
	struct tabela table[100000];
	
	//Inicia o clock
	clock_t inicio = clock();
	int i,j;
	
	//A cada 100000 iterações, escreve no arquivo. Repete isso 10000 vezes.
	for(j=0;j<10000;j++){
		for(i = 0;i<100000;i++){
			table[i].sexo = rand() % 2; //Cria valor aleatório de 0 a 1 de sexo
			table[i].idade = rand() % 128; //Cria valor aleatório de 0 a 127 de idade
			table[i].renda = rand() % 1024; //Cria valor aleatório de 0 a 1023 de renda
			table[i].escolaridade = rand() % 3; //Cria valor aleatório de 0 a 2 de escolaridade
			table[i].idioma = rand() % 4096; //Cria valor aleatório de 0 a 4095 de idioma
			table[i].pais = rand() % 256; //Cria valor aleatório de 0 a 255 de pais
			table[i].localizador = rand() % 16777216; //não soubemos como gerar o localizador, então ele só gera algo até o limite representado
		}
	
		fwrite(&table,sizeof(table),1,fp);
	}
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;
	printf("Tempo decorrido: %gseg",elapsed);
	
	fclose(fp)

}
