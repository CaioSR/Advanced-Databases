#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//Cria um struct global representando a tabela 
struct tabela{
	unsigned int sexo : 1;
	unsigned int idade : 7;
	unsigned int renda : 10;
	unsigned int escolaridade : 2;
	unsigned int idioma : 12;
	unsigned int pais : 8;
	unsigned int localizador : 24;
};

struct tabela table;

void query1(){
	//
	
	//Inicia contagem
	clock_t inicio = clock();
	
	//Cria um struct pais para contagem de pessoas do sexo 0 e do sexo 1 
	struct pais{
		int count0;
		int count1;
	};
	//Cria 256 structs representando os 256 países
	struct pais p[256];
	
	//Inicia os dados do struct
	int i;
	for(i=0;i<256;i++){
		p[i].count0=0;
		p[i].count1=0;
	}
	
	//Cria um ponteiro para o arquivo
	FILE * fp;
	
	//Abre o arquivo para leitura binária
	fp = fopen("database.dat","rb");
	
	//Lê linha por linha do arquivo
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.sexo == 0){
			p[table.pais].count0++; //Incrementa ao contador referente ao sexo 0 de p de índice correspondente ao país
		}
		else{
			p[table.pais].count1++; //Incrementa ao contador referente ao sexo 1 de p de índice correspondente ao país
		}
	}
	
	//Finaliza contagem
	clock_t fim = clock();
	
	//Transforma para segundos
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;
	
	//Printa o resultado conforme a estrutura da consulta
	/*
	printf("Pais Sexo Count\n");
	for(i=0;i<256;i++){
		printf("%d 0 %d\n%d 1 %d\n", i, p[i].count0, i, p[i].count1);
	}
	*/
	
	printf("Tempo decorrido: %gseg\n",elapsed);

	//Fecha o arquivo
	fclose(fp);
	
}

void query2(){
	clock_t inicio = clock();
	
	struct pais{
		int count0;
		int count1;
	};
	
	//Cria uma matriz de structs onde as linhas são os países e as colunas são as idades
	struct pais p[256][128];
	
	//Inicia os dados do struct
	int i,j;
	for(i=0;i<256;i++){
		for(j=0;j<128;j++){
			p[i][j].count0=0;
			p[i][j].count1=0;
		}
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.sexo == 0){
				p[table.pais][table.idade].count0++; //Incrementa no contador 0 nos índices respectivos ao pais e a idade
			}else{
				p[table.pais][table.idade].count1++; //Incrementa no contador 1 nos índices respectivos ao pais e a idade
			}

	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	printf("Pais Sexo Idade Count\n");
	for(i=0;i<256;i++){
		for(j=0;j<128;j++){
			printf("%d 0 %d %d\n", i, j, p[i][j].count0);
		}
		for(j=0;j<128;j++){
			printf("%d 1 %d %d\n", i, j, p[i][j].count1);
		}
		
	}
	*/
	
	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query3(){
	clock_t inicio = clock();
	
	struct pais{
		long int renda0;
		long int renda1;
		long int rendaMedia0;
		long int rendaMedia1;
		int count0;
		int count1;
	};
	
	struct pais p[256];
	
	int i;
	for(i=0;i<256;i++){
		p[i].renda0=0;
		p[i].renda1=0;
		p[i].count0=0;
		p[i].count1=0;
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	long int renda = 0;
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.sexo == 0){
			p[table.pais].count0++; //Incrementa contador do sexo 0
			p[table.pais].renda0 = p[table.pais].renda0 + table.renda; //Incrementa a renda do sexo 0
		}else{
			p[table.pais].count1++;
			p[table.pais].renda1 = p[table.pais].renda1 + table.renda;
		}
	}
	
	//Calcula a media de renda dos sexos 0 e 1 de cada país
	for(i=0;i<256;i++){
		p[i].rendaMedia0 = p[i].renda0/p[i].count0;
		p[i].rendaMedia1 = p[i].renda1/p[i].count1;
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	printf("Pais Sexo RendaMedia\n");
	for(i=0;i<256;i++){
		printf("%d 0 %d\n%d 1 %d\n", i, p[i].rendaMedia0, i, p[i].rendaMedia1);
		
	}
	*/
	
	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query4(){
	clock_t inicio = clock();
	
	struct pais{
		int idade0;
		int idade1;
		int idadeMedia0;
		int idadeMedia1;
		int count0;
		int count1;
	};
	
	struct pais p[256];
	
	int i;
	for(i=0;i<256;i++){
		p[i].idade0=0;
		p[i].idade1=0;
		p[i].count0=0;
		p[i].count1=0;
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	long int idade = 0;
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.sexo == 0){
			p[table.pais].count0++;
			p[table.pais].idade0 = p[table.pais].idade0 + table.idade;
		}else{
			p[table.pais].count1++;
			p[table.pais].idade1 = p[table.pais].idade1 + table.idade;
		}
	}
	

	for(i=0;i<256;i++){
		p[i].idadeMedia0 = p[i].idade0/p[i].count0;
		p[i].idadeMedia1 = p[i].idade1/p[i].count1;
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	printf("Pais Sexo IdadeMedia\n");
	for(i=0;i<256;i++){
		printf("%d 0 %d\n%d 1 %d\n", i, p[i].idadeMedia0, i, p[i].idadeMedia1);
		
	}
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query5(){
	clock_t inicio = clock();
	
	struct pais{
		int count0;
		int count1;
	};
	
	struct pais p;
	
	p.count0=0;
	p.count1=0;
	
	FILE * fp;
	fp = fopen("database.dat","rb");

	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.pais == 15){
			if(table.sexo == 0){
				p.count0++;
			}else{
				p.count1++;
			}
		}	
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	printf("Pais Sexo Count\n");
	printf("15 0 %d\n15 1 %d\n", p.count0, p.count1);
	*/
	
	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query6(){
	clock_t inicio = clock();
	
	struct pais{
		int count1;
	};
	
	struct pais p;
	
	p.count1=0;

	FILE * fp;
	fp = fopen("database.dat","rb");

	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.pais == 15){
			if(table.sexo == 1){
				p.count1++;
			}
		}	
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	printf("Pais Sexo Count\n");
	printf("15 1 %d\n",p.count1);
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query7(){
	clock_t inicio = clock();
	
	struct pais{
		int count0;
		int count1;
	};
	
	struct pais p;
	
	p.count0 = 0;
	p.count1 = 1;
	
	FILE * fp;
	fp = fopen("database.dat","rb");

	while(fread(&table,sizeof(table),1,fp)==1){
		if((table.pais >= 0) && (table.pais <= 15)){
			if(table.sexo == 0){
				p.count0++;
			}else{
				p.count1++;
			}
		}	
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;

	/*
	int i;
	printf("Pais Sexo Count\n");
	for(i=0;i<16;i++){
		printf("%d 0 %d\n%d 1 %d\n", i, p.count0, i, p.count1);
	}
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query8(){
	clock_t inicio = clock();
	
	struct pais{
		int renda;
	};
	
	struct pais p[256][5];
	
	int i,j;
	for(i=0;i<256;i++){
		for(j=0;j<5;j++){
			p[i][j].renda=0;
		}
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	double renda = 0;
	int rendaMedia = 0;
	
	//Le o arquivo uma vez para calcular a renda media de todas as pessoas do banco (subquery)
	while(fread(&table,sizeof(table),1,fp)==1){
		renda = renda + table.renda;
	}
	rendaMedia =  (int)(renda/1000000000);
	
	fclose(fp);
	
	fp = fopen("database.dat","rb");
	
	//Le uma segunda vez para realizar a query principal
	while(fread(&table,sizeof(table),1,fp)==1){
		if((table.idade <= 4) && (table.renda >= rendaMedia)){
			p[table.pais][table.idade].renda = table.renda;
		}
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;
	
	/*
	printf("Pais Renda Idade\n");
	for(i=0;i<5;i++){
		for(j=0;j<256;j++){
			printf("%d %d %d\n", j, p[i][j].renda, i);
		}
	}
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query9(){
	clock_t inicio = clock();
	
	struct pais{
		int renda;
	};
	
	struct pais p[256][26];
	
	int i,j;
	for(i=0;i<256;i++){
		for(j=0;j<26;j++){
			p[i][j].renda=0;
		}
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	double renda = 0;
	int rendaMedia = 0;
	
	//Le o arquivo uma vez para calcular a renda media de todas as pessoas do banco (subquery)
	while(fread(&table,sizeof(table),1,fp)==1){
		renda = renda + table.renda;
	}
	rendaMedia =  (int)(renda/1000000000);
	
	fclose(fp);
	
	fp = fopen("database.dat","rb");

	//Le uma segunda vez para realizar a query principal
	while(fread(&table,sizeof(table),1,fp)==1){
		if((table.idade >= 25) && (table.idade <= 50) && (table.renda < rendaMedia)){
			p[table.pais][table.idade-25].renda = table.renda;
		}
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;
	
	/*
	printf("Pais Renda Idade\n");
	for(i=0;i<26;i++){
		for(j=0;j<256;j++){
			printf("%d %d %d\n", j, p[i][j].renda, i+25);
		}
	}
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void query10(){
	clock_t inicio = clock();
	
	struct pais{
		int count;
	};
	
	struct pais p[256];
	
	int i;
	for(i=0;i<256;i++){
		p[i].count=0;
	}
	
	FILE * fp;
	fp = fopen("database.dat","rb");
	
	int renda = 0;
	
	//Le uma vez para calcular a maior renda
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.renda > renda){
			renda = table.renda;
		}
	}
	
	fclose(fp);
	
	fp = fopen("database.dat","rb");

	//Le uma segunda vez para realizar a query principal
	while(fread(&table,sizeof(table),1,fp)==1){
		if(table.renda == renda){
			p[table.pais].count++;
		}
	}
	
	clock_t fim = clock();
	double elapsed = (fim - inicio) / CLOCKS_PER_SEC;
	
	/*
	printf("Renda Pais Count\n");
	for(i=0;i<256;i++){
		printf("%d %d %d\n", renda, i, p[i].count);
	}
	*/

	printf("Tempo decorrido: %gseg\n",elapsed);

	fclose(fp);
	
}

void main(){
	int i;
	
	//Repete 3 vezes uma query
	for(i=0;i<3;i++){
		query10();
	}

	


	


	


	
}
