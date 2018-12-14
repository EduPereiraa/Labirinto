#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char grelha[16][16];

void preenche (char* file){
	int linha=0;
	int coluna=0;
	int iterador=0;
	while(file[iterador]!=NULL){
		if (file[iterador]!='\n')
		{
			grelha[linha][coluna]=file[iterador];
			coluna++;
		}
		else
		{
			linha++;
			coluna=0;
		}
		iterador++;
	}
}

void carrega (char* ficheiro){
	char labirinto[1000];
	FILE *fp = fopen(ficheiro,"r");
	
	if(fp==NULL)
	{
		printf("Erro a carregar labirinto");
		return;
	}
	char c;
	int i=0;
    while(fscanf(fp,"%c",&c)!=EOF){
    	labirinto[i]=c;
    	i++;
	}
	labirinto[i]='\0';
	
    
	preenche(labirinto);
	fclose(fp);
}

main () {
	carrega("Labirinto.txt");
	int j;
	int i;
	for (i=0;i<16;i++){
		for (j=0;j<16;j++)
			printf("%c",grelha[i][j]);
			if (j==16) printf("\n");
	}
}




      


