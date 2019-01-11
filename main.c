#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>

#define maxX 18
#define maxY 18



int posX=1;
int posY=1;


void preenche (char* file, char grelha [maxX][maxY]){ // gerar os campos do labirinto
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
	grelha[posX][posY]='@';
	
}

void carrega (char *ficheiro, char grelha [maxX][maxY]){  //abrir o labirinto previamente gerado pelo bloco de notas
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
	
    
	preenche(labirinto, grelha); //atribuir o labirinto gerado no bloco de notas ao preenchimento do labirinto
	fclose(fp);
}

void imprimeMapa(int pontos, char grelha [maxX][maxY], int posicao_atual_m1[2], int posX, int posY){
	int i,j,dim;
	system("cls");
    printf("Pontos: %d\n",pontos);
	for (i=0;i<17;i++)
	{
		for (j=0;j<17;j++)
		
			printf("%c",grelha[i][j]);
			if (j==17) printf("\n");
			if(i == 0 || i == (dim-1) || j == 0 || j == (dim-1))
                   grelha[i][j] = '#'; 
	}
	printf("Posicao do Jogador: (%d,%d)\n",posX,posY);
}



int controla_personagem (char controlo, int pontos, char grelha [maxX][maxY], int posX, int posY, int, posicao_atual_m1)    // (posX,posY) é a posição atual da personagem
{
												          
//Movimentos
switch(controlo)
{
	case 's': if(grelha[posX+1][posY] != '#')  // A posição inicial do labirinto é 1,1 e ao andar para baixo a personagem vai andar mais uma casa
				{
				if(grelha[posX+1][posY] == '*')
				{
					pontos++;
				}
				grelha[posX][posY] = ' ';
				posX++;  
				grelha[posX][posY] = '@';
				imprimeMapa(pontos, grelha,posicao_atual_m1, posX,posY);
				}
				break;
	case 'a':  if(grelha[posX][posY-1] != '#') // Ao andar para a esquerda a personagem vai andar uma para casa para a esquerda daí ser -1
				{
				if(grelha[posX][posY-1] == '*')
				{
					pontos++;
				}
				grelha[posX][posY] = ' ';
				posY--;  
				grelha[posX][posY] = '@';
				imprimeMapa(pontos, grelha);
				}
				 break;
	case 'w':  if(grelha[posX-1][posY] != '#') // Ao andar para cima a personagem vai andar uma casa para cima descendo na coordenada x daí ser -1
             	{
             	if(grelha[posX-1][posY] == '*')
             	{
             		pontos++;
				}
		        grelha[posX][posY] = ' ';
		        posX--;
		        grelha[posX][posY] = '@';
				imprimeMapa(pontos, grelha);
             	}
             	 break;
    case 'd':	if(grelha[posX][posY+1] != '#') //Ao andar para a direita a personagem vai andar uma casa para a direita, subindo na coordenada y daí ser +1
	    		{
	            if(grelha[posX][posY+1] == '*')
	            {
	            	pontos++;
				}
				
	           	grelha[posX][posY] = ' ';
	           	posY++;
	           	grelha[posX][posY] = '@';
				imprimeMapa(pontos, grelha);
			    }       
			    break;
	}
return pontos;
}

//	posicao_atual[0] = rand() % linhas;
//	posicao_atual[1] = rand() % colunas;

void controlo_inimigos(char grelha [maxX][maxY], int linhas, int colunas, int posicao_atual[2],  int posicao_memoria[2]){

	int cont_livres;
	int celulas_livres[4];

	srand(time(NULL));
	
	cont_livres=-1;
	if(posicao_atual[1]-1 != '#' && posicao_atual[1]-1 != posicao_memoria[1])
	{
		cont_livres ++;
		celulas_livres[cont_livres] = 1;
	}
	if(posicao_atual[0]+1 != '#' && posicao_atual[0]+1 != posicao_memoria[0])
	{
		cont_livres ++;
		celulas_livres[cont_livres] = 2;
	}
	if(posicao_atual[1]+1 != '#' && posicao_atual[1]+1 != posicao_memoria[1])
	{
		cont_livres ++;
		celulas_livres[cont_livres] = 3;
	}
	if(posicao_atual[0]-1 != '#' && posicao_atual[0]-1 != posicao_memoria[0])
	{
		cont_livres ++;
		celulas_livres[cont_livres] = 4;
	}
	
	if(cont_livres<0)
	{
		cont_livres = rand() % (cont_livres +1);
		
		switch(celulas_livres[cont_livres]) {
			case 1:{
				posicao_memoria[1]= posicao_atual[1];
				posicao_atual[1]--;
			break;
			}
			case 2:{
				posicao_memoria[0]= posicao_atual[0];
				posicao_atual[0]++;
			break;
			}
			case 3:{
			posicao_memoria[1]= posicao_atual[1];
			posicao_atual[1]++;
			break;
			}
			case 4:{
			posicao_memoria[0]= posicao_atual[0];
			posicao_atual[0]--;
			break;
			}	
			case 0:{
			printf("\n\nErro");
			break;
			}
		}
	}
	
}



main ()
{
	int pontos=0;
	int linhas=17,colunas=17;
	int posicao_memoria_m1[2]={0,0}, posicao_atual_m1[2];
	char grelha[maxX][maxY], controlo=1;
	carrega("Labirinto.txt", grelha);
	int i=0;

	while(posicao_atual_m1[0]!=1 && posicao_atual_m1[1]!=1){
	posicao_atual_m1[0] = rand() % linhas;
	posicao_atual_m1[1] = rand() % colunas;
	}
	imprimeMapa(pontos, grelha, posicao_atual_m1);
	do{

	     
//	    while(controlo != 'a' && controlo != 's' && controlo!= 'd' && controlo != 'w' && controlo!='\0')
	    
	   	
		
		
		if(pontos==157){
			printf("Completou o nivel!");
			break;
		}
		
		else{
			controlo_inimigos(grelha,linhas,colunas,posicao_atual_m1,posicao_memoria_m1);
			pontos = controla_personagem(controlo, pontos, grelha);
		}
	    controlo = getch();
	}while(2);
}
