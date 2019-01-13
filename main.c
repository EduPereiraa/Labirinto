#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>

#define maxX 17
#define maxY 47





void preenche (char* file, char grelha [maxX][maxY], int posicao[2]){ // gerar os campos do labirinto
	int linha=0;
	int coluna=0;
	int iterador=0;
	while(file[iterador]!='\0'){
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

void carrega (char *ficheiro, char grelha [maxX][maxY], int posicao[2]){  //abrir o labirinto previamente gerado pelo bloco de notas
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
	
    
	preenche(labirinto, grelha, posicao); //atribuir o labirinto gerado no bloco de notas ao preenchimento do labirinto
	fclose(fp);
}

void gravar_jogo (char *ficheiro, char grelha [maxX][maxY], int posicao[2],int posicao_atual_m1[2],int posicao_atual_m2[2],int posicao_atual_m3[2],int posicao_atual_m4[2]){  //abrir o labirinto previamente gerado pelo bloco de notas
	char labirinto[1000];
	FILE* gravar = fopen(ficheiro,"w");
	int k;
	
	if(gravar==NULL)
	{
		printf("Erro a gravar o jogo\n");
		return;
	}
	else {
		k=0;
		int i=0;
		int j=0;
	 	for (i=0;i<maxX;i++){
	 		for (j=0;j<maxY;j++){
	 			labirinto[k]=grelha[i][j];
	 			k++;
		 	}
		 	labirinto[k]='\n';
		 	k++;
	 	}
	 	labirinto[k]='\0';
	 	
	 	char posicaoJX[3];
		char posicaoJY[3];
		char posicaoM1X[3];
		char posicaoM1Y[3];
		char posicaoM2X[3];
		char posicaoM2Y[3];
		char posicaoM3X[3];
		char posicaoM3Y[3];
		char posicaoM4X[3];
		char posicaoM4Y[3];
	 	sprintf(posicaoJX,"%d",posicao[0]);
	 	sprintf(posicaoJY,"%d",posicao[1]);
	 	sprintf(posicaoM1X,"%d",posicao_atual_m1[0]);
	 	sprintf(posicaoM1Y,"%d",posicao_atual_m1[1]);
	 	sprintf(posicaoM2X,"%d",posicao_atual_m2[0]);
	 	sprintf(posicaoM2Y,"%d",posicao_atual_m2[1]);
	 	sprintf(posicaoM3X,"%d",posicao_atual_m3[0]);
	 	sprintf(posicaoM3Y,"%d",posicao_atual_m3[1]);
	 	sprintf(posicaoM4X,"%d",posicao_atual_m4[0]);
	 	sprintf(posicaoM4Y,"%d",posicao_atual_m4[1]);
	 	
	 	strcat(labirinto,posicaoJX);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoJY);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM1X);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM1Y);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM2X);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM2Y);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM3X);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM3Y);
		strcat(labirinto,"\n");
		strcat(labirinto,posicaoM4X);
		strcat(labirinto,"\n");	
		strcat(labirinto,posicaoM4Y);
	}
	
	fprintf(gravar, "%s", labirinto);
  
    fclose(gravar);
  
  printf("Dados gravados com sucesso!\n");
}

int load (char *ficheiro,char grelha[maxX][maxY],int posicao[2],int posicao_atual_m1[2],int posicao_atual_m2[2],int posicao_atual_m3[2],int posicao_atual_m4[2]){
	char labirinto[1000];
	int pontos=483;
	FILE* jogo = fopen(ficheiro,"r");

	if(jogo==NULL)
	{
		printf("Erro a carregar o jogo\n");
		return;
	}
	else{
		int k;
		char c;
		int i=0;
		int j=0;
		char posicaoJX[2],posicaoJY[2],posicaoM1X[2],posicaoM1Y[2],posicaoM2X[2],posicaoM2Y[2],posicaoM3X[2],posicaoM3Y[2],posicaoM4X[2],posicaoM4Y[2];
		while(fscanf(jogo,"%c",&c)!=EOF){
    		labirinto[k]=c;    		
			if(labirinto[k]=='\n') i++;
			else if (i<17){
			 grelha[i][j]=labirinto[k];
			 if(labirinto[k]=='*') pontos--;
			 j++;
		 	if (j==47) j=0;
			}
			if (i==17) strcat(posicaoJX,&labirinto[c]);
			if (i==18) strcat(posicaoJY,&labirinto[c]);
			if (i==19) strcat(posicaoM1X,&labirinto[c]);
			if (i==20) strcat(posicaoM1Y,&labirinto[c]);
			if (i==21) strcat(posicaoM2X,&labirinto[c]);
			if (i==22) strcat(posicaoM2Y,&labirinto[c]);
			if (i==23) strcat(posicaoM3X,&labirinto[c]);
			if (i==24) strcat(posicaoM3Y,&labirinto[c]);
			if (i==25) strcat(posicaoM4X,&labirinto[c]);
			if (i==26) strcat(posicaoM4Y,&labirinto[c]);
			k++;
			
		}
	    
		fclose(jogo);
	}
	return pontos;
}

void imprimeMapa(int pontos, char grelha [maxX][maxY], int posicao_atual_m1[2],int posicao_atual_m2[2],int posicao_atual_m3[2],int posicao_atual_m4[2], int posicao[2]){
	int i,j,dim;
	//system("cls");
	printf("Regras do Jogo: Evitar ser apanhado pelos monstros e apanhar todos os pontos\n");
	printf("ATENCAO!---> Monstros: &\n");
    printf("Pontos: %d\n",pontos);
    
	for (i=0;i<17;i++)
	{
		for (j=0;j<47;j++)
			if ((posicao[0]==i) && (posicao[1]==j))
				printf("@");
			else if((posicao_atual_m1[0]==i) && (posicao_atual_m1[1]==j)){
				printf("&");
				}
        	else if((posicao_atual_m2[0]==i) && (posicao_atual_m2[1]==j)){
				printf("B");
				}
			else if((posicao_atual_m3[0]==i) && (posicao_atual_m3[1]==j)){
				printf("$");
				}
			else if((posicao_atual_m4[0]==i) && (posicao_atual_m4[1]==j)){
				printf("?");
				}
			else{
			printf("%c",grelha[i][j]);
			}
			if (j==47) printf("\n");
	}
	printf("Posicao do Jogador: (%d,%d)\n", posicao[0], posicao[1]);
	printf("\n Instrucoes do jogo: \n W: Movimento para cima\n A: Movimento para a esquerda\n S: Movimento para baixo\n D: Movimento para a direita \n G: Gravar o jogo \n C: Carregar o jogo\n");
}


void controlo_inimigos(char grelha [maxX][maxY], int linhas, int colunas, int posicao_monstro[2], int posicao[2]){
	
	if (posicao_monstro[0]>posicao[0]){
		if (grelha[posicao_monstro[0]-1][posicao_monstro[1]]!='#')
		{
			posicao_monstro[0]--;
		}
		else if (posicao_monstro[1]>posicao[1] && grelha[posicao_monstro[0]][posicao_monstro[1]-1]!='#')
			posicao_monstro[1]--;
		else if (posicao_monstro[1]<posicao[1] && grelha[posicao_monstro[0]][posicao_monstro[1]+1]!='#')
			posicao_monstro[1]++;
	}	
	else if (posicao_monstro[0]<posicao[0]){
		if (grelha[posicao_monstro[0]+1][posicao_monstro[1]]!='#') 
		{
			posicao_monstro[0]++;
		}
		else if (posicao_monstro[1]>posicao[1] && grelha[posicao_monstro[0]][posicao_monstro[1]-1]!='#')
			posicao_monstro[1]--;
		else if (posicao_monstro[1]<posicao[1] && grelha[posicao_monstro[0]][posicao_monstro[1]+1]!='#')
			posicao_monstro[1]++;
	
		}
	else if(posicao_monstro[1]>posicao[1]) {
		if(grelha[posicao_monstro[0]][posicao_monstro[1]-1] != '#')
		{
			posicao_monstro[1]--;
		}
		else if (posicao_monstro[0]>posicao[0] && grelha[posicao_monstro[0]-1][posicao_monstro[1]]!='#')
			posicao_monstro[0]--;
		else if (posicao_monstro[1]<posicao[1] && grelha[posicao_monstro[0]-1][posicao_monstro[1]]!='#')
			posicao_monstro[0]++;
	
	}
	else if (posicao_monstro[1]<posicao[1]){
		if(grelha[posicao_monstro[0]][posicao_monstro[1]+1] != '#')
		{
			posicao_monstro[1]++;
		}
		else if (posicao_monstro[0]>posicao[0] && grelha[posicao_monstro[0]-1][posicao_monstro[1]]!='#')
			posicao_monstro[0]--;
		else if (posicao_monstro[1]<posicao[1] && grelha[posicao_monstro[0]-1][posicao_monstro[1]]!='#')
			posicao_monstro[0]++;
	}
}


int controla_personagem (char controlo, int pontos, char grelha [maxX][maxY], int posicao[2], int posicao_atual_m1[2], int posicao_atual_m2[2],int posicao_atual_m3[2],int posicao_atual_m4[2],int linhas, int colunas)    // (posX,posY) é a posição atual da personagem
{
												          
//Movimentos
switch(controlo)
{
	case 's': if(grelha[posicao[0]+1][posicao[1]] != '#')  // A posição inicial do labirinto é 1,1 e ao andar para baixo a personagem vai andar mais uma casa
				{
				if(grelha[posicao[0]+1][posicao[1]] == '*')
				{
					pontos++;
				}
				grelha[posicao[0]][posicao[1]] = ' ';
				posicao[0]++;  	           
				
				}
				break;
	case 'a':  if(grelha[posicao[0]][posicao[1]-1] != '#') // Ao andar para a esquerda a personagem vai andar uma para casa para a esquerda daí ser -1
				{
				if(grelha[posicao[0]][posicao[1]-1] == '*')
				{
					pontos++;
				}
				grelha[posicao[0]][posicao[1]] = ' ';
				posicao[1]--;  
            
				}
				 break;
	case 'w':  if(grelha[posicao[0]-1][posicao[1]] != '#') // Ao andar para cima a personagem vai andar uma casa para cima descendo na coordenada x daí ser -1
             	{
             	if(grelha[posicao[0]-1][posicao[1]] == '*')
             	{
             		pontos++;
				}
		        grelha[posicao[0]][posicao[1]] = ' ';
		        posicao[0]--;
            
             	}
             	 break;
    case 'd':	if(grelha[posicao[0]][posicao[1]+1] != '#') //Ao andar para a direita a personagem vai andar uma casa para a direita, subindo na coordenada y daí ser +1
	    		{
	            if(grelha[posicao[0]][posicao[1]+1] == '*')
	            {
	            	pontos++;
				}
				
	           	grelha[posicao[0]][posicao[1]] = ' ';
	           	posicao[1]++;
            	
			    }       
			    break;
	}
return pontos;
}


main()
{
	int pontos=0;
	int linhas=17,colunas=47;
	int posicao[2]={1,1};
	int posicao_atual_m1[2];
	int posicao_atual_m2[2];
	int posicao_atual_m3[2];
	int posicao_atual_m4[2];
	char grelha[maxX][maxY], controlo=1;
	carrega("Labirinto.txt", grelha, posicao);
	int i=0;
	
	posicao_atual_m1[0]=4; 
	posicao_atual_m1[1]=9; 
	posicao_atual_m2[0]=15;
	posicao_atual_m2[1]=35;
    posicao_atual_m3[0]=15;
    posicao_atual_m3[1]=10;
    posicao_atual_m4[0]=11;
    posicao_atual_m4[1]=31;
	imprimeMapa(pontos, grelha, posicao_atual_m1,posicao_atual_m2,posicao_atual_m3,posicao_atual_m4, posicao);
	do{{
			if (controlo=='g') gravar_jogo("jogo.txt",grelha,posicao,posicao_atual_m1,posicao_atual_m2,posicao_atual_m3,posicao_atual_m4);
			else if (controlo=='c') pontos=load("jogo.txt",grelha,posicao,posicao_atual_m1,posicao_atual_m2,posicao_atual_m3,posicao_atual_m4);
			else{
				pontos = controla_personagem(controlo, pontos, grelha,posicao, posicao_atual_m1, posicao_atual_m2, posicao_atual_m3,posicao_atual_m4,linhas, colunas);
				controlo_inimigos(grelha,linhas,colunas,posicao_atual_m1,posicao);
	        	controlo_inimigos(grelha,linhas,colunas,posicao_atual_m2,posicao);
	        	controlo_inimigos(grelha,linhas,colunas,posicao_atual_m3,posicao);
	        	controlo_inimigos(grelha,linhas,colunas,posicao_atual_m4,posicao);
	        	if((posicao_atual_m1[0]==posicao[0] && posicao_atual_m1[1]==posicao[1])
					|| (posicao_atual_m2[0]==posicao[0] && posicao_atual_m2[1]==posicao[1])
					|| (posicao_atual_m3[0]==posicao[0] && posicao_atual_m3[1]==posicao[1])
					|| (posicao_atual_m4[0]==posicao[0] && posicao_atual_m4[1]==posicao[1])){
					printf("GAME OVER\n");
					break;
				}
				if(pontos==483){
					printf("Completou o jogo!");
					break;
				}
			}
	    	imprimeMapa(pontos, grelha, posicao_atual_m1, posicao_atual_m2, posicao_atual_m3, posicao_atual_m4,posicao);
		}
	    controlo = getch();
	}while(1);
	
}
