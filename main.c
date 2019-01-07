#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

char grelha[16][16];
int posX=1;
int posY=1;

void preenche (char* file){ // gerar os campos do labirinto
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

void carrega (char* ficheiro){  //abrir o labirinto previamente gerado pelo bloco de notas
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
	
    
	preenche(labirinto); //atribuir o labirinto gerado no bloco de notas ao preenchimento do labirinto
	fclose(fp);
}

void imprimeMapa(int pontos){
	int i,j,dim;
	system("cls");
    printf("Pontos: %d\n",pontos);
	for (i=0;i<16;i++)
	{
		for (j=0;j<16;j++)
			printf("%c",grelha[i][j]);
			if (j==16) printf("\n");
			if(i == 0 || i == (dim-1) || j == 0 || j == (dim-1) )
                   grelha[i][j] = '#'; 
	}
}



int controla_personagem (char controlo, int pontos)    // (posX,posY) é a posição atual da personagem
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
             	}
             	 break;
    case 'd':  if(grelha[posX][posY+1] != '#') //Ao andar para a direita a personagem vai andar uma casa para a direita, subindo na coordenada y daí ser +1
	            {
	            if(grelha[posX][posY+1] == '*')
	            {
	            	pontos++;
				}
	           	 grelha[posX][posY] = ' ';
	           	 posY++;
	           	 grelha[posX][posY] = '@';
			    }       
			    break;
	}
return pontos;
}
char ler_comando()
{ 
    char a,s,d,w;
    char controlo;
	controlo = getch();
	
	return controlo;
}

main ()
{
	int pontos=0;
	carrega("Labirinto.txt");
	int i=0;
	while(1)
	    {
		imprimeMapa(pontos);
		printf("Posicao do Jogador: (%d,%d)\n",posX,posY);
	    char controlo='f'; 
	    while(controlo != 'a' && controlo != 's' && controlo!= 'd' && controlo != 'w' && controlo!='\0')
	    {
	    	controlo = ler_comando();
		}
	    pontos = controla_personagem(controlo, pontos);
	    }
}




      


