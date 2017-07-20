#include "base.h"
#define MAX 400000

	double sort(void);
	void lerarq(void);
	void arqtempo(void);
	
	FILE *fa;	
	int vetor[MAX];
	int i, j, temp, calculo = 0;
	unsigned int troca = 0;
	int menor, cont;
	double tempo;
	char titulo[] = "Selection Sort C";
	
main(){
	
	cont = learq();
	
	sort();
	
	line;
		printf("V[3] = [%2i]\n", vetor[3]);
		printf("V[65] = [%2i]\n", vetor[65]);
		printf("V[153] = [%2i]\n", vetor[153]);
		printf("V[520] = [%2i]\n", vetor[520]);
		printf("V[756] = [%2i]\n", vetor[756]);
		printf("V[1942] = [%2i]\n", vetor[1942]);
		printf("V[3156] = [%2i]\n", vetor[3156]);
		printf("V[6983] = [%2i]\n", vetor[6983]);
		printf("V[9573] = [%2i]\n", vetor[9573]);
		printf("V[26463] = [%2i]\n", vetor[26463]);
		printf("V[43896] = [%2i]\n", vetor[43896]);
		printf("V[75224] = [%2i]\n", vetor[75224]);
		printf("V[95356] = [%2i]\n", vetor[95356]);
		printf("V[159865] = [%2i]\n", vetor[159865]);
		printf("V[265898] = [%2i]\n", vetor[265898]);
		printf("V[354987] = [%2i]\n", vetor[354987]);
		printf("V[398351] = [%2i]\n", vetor[398351]);
	
	printf("\n\n\tTrocas: %u",troca);
	printf("\tComparações: %i", calculo);
	printf("\tTempo gasto: %g ms.", tempo);
	arqtempo();
	getch();
	return 0;
}

arqtempo(){
	FILE *gravar;
	gravar = fopen("tempos.dat", "a+");
	fprintf(gravar, "Nome: %s, Trocas: %u, Comparações: %i, Tempo: %g ms\n", titulo, troca,calculo,tempo);
	fclose(gravar);
}

double sort(){
	clock_t Ticks[2];
	Ticks[0] = clock();	
	for(i=0;i<MAX;i++){
		menor = i;
		for(j=i+1;j<MAX;j++){
			if(vetor[j]<vetor[menor]){
				menor = j;
			}
		}
		if(i!=menor){
			temp = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = temp;
			troca += 1;			
		}
		calculo ++;
	}
	Ticks[1] = clock();
	tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	return tempo;
}



int learq(){ // ler aquivo
	int contador = 0;
	fa = fopen("Dados/VetorAleatorio.txt", "r");
	if(fa == NULL){
		puts("\nErro na abertura de agenda.dat");
		puts("Programa sera finalizado. ");
		getch();
		exit(1);
	}// if verificação de erro
	while(fscanf(fa,"%i\n", &vetor[contador]) != EOF){
		printf("[%2i] \t", vetor[contador]);
		contador++;	
	}
	puts("\n");
	fclose(fa);
	return contador;		
}

