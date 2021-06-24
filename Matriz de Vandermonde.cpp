#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	int x,y,z,i,j,q,det,u,w=1,c,g,h,k;
	float soma,o[y],p;
	printf("                                             INTERPOLACAO DE VANDERMONDE                                             \n\nEscolha o valor de linhas e colunas:\nLinhas = ");
	scanf("%d",&x);
	printf("Colunas = ");
	scanf("%d",&y);
	int disp[100][100],inter[100][100],dispt[100][100];
	printf ("\n\nVoce deseja uma matriz de linha, ou de coluna?\nPara linha, digite 1, para coluna, digite 2: ");
	scanf ("%d",&q);
	printf("\n");
	
	if (q==1){ //matriz de vandermonde baseada nas linhas
		for(i=0;i<1;i++){ //1 na primeira linha
			for (j=0;j<y;j++){
				disp[i][j]=1;
			}
   		}
   		for (i=1;i<2;i++){ //adição dos elementos principais
   			for(j=0;j<y;j++){
   				printf("\nPosicione o elemento a[%d][%d]: ",i+1,j+1);
   				scanf("%d",&disp[i][j]);
			}
		}
		for (i=2;i<x;i++){	//calculo das potencias que seguem nas proximas linhas
			for(j=0;j<y;j++){
				disp[i][j] = pow(disp[1][j],i);
			}
		}
	
   		printf("\n\nMatriz de Vandermonde:\n\n"); 
   		for(i=0; i<x; i++) { //impressão da matriz no console
    		for(j=0;j<y;j++) {
         		printf("  %d ", disp[i][j]);
      		}
			printf("\n\n");
   		}
   		printf ("Calculo do Determinante: ");
   		for (j=0,i=1;j<y;j++){ //calculo do determinante
   			for (u=j;u>=0;u--){
   				if(disp[i][j]>disp[i][u]){
   					det=(disp[i][j]-disp[i][u])*w;
   					w=det;
   					printf("(%d - %d)",disp[i][j],disp[i][u]);
				}
			}
		}
		printf(" = %d\n\nDeterminante da Matriz = %d",det,det);
		z=x;
		printf ("\n\nInterpolacao:\n");
		for(i=0;i<x;i++){ 
			for (j=0;j<y;j++){
				inter[i][j]=disp[i][j];
			}
		}
		for (j=0;j<y;j++){//coleta dos valores da interpolação
			printf("\nInsira o valor de y[%d]: ",j+1);
			scanf("%d",&inter[z][j]);
			}
		printf ("\n");
    	for (i = 0; i < x; i++){//transposição da matriz
    		for (j = 0; j <= y; j++){
    			dispt[i+1][j+1] = inter[j][i];
				printf("  %d ",dispt[i+1][j+1]);
			}
			printf ("\n\n");
		}
	
		for(j=1; j<=z; j++) //triangulação superior da matriz pelo metodo de gauss
	    {
	        for(i=1; i<=z; i++)
	        {
	            if(i>j)
	            {
	                p=dispt[i][j]/dispt[j][j];
	                for(k=1; k<=z+1; k++)
	                {
	                    dispt[i][k]=dispt[i][k]-(p*dispt[j][k]);
	                }
	            }
	        }
	    }
	    o[z]=dispt[z][z+1]/dispt[z][z];
	    for(i=z; i>=1; i--)
	    {
	        soma=0;
	        for(j=i+1; j<=z; j++)
	        {
	            soma=soma+dispt[i][j]*o[j];
	        }
	        o[i]=(dispt[i][z+1]-soma)/dispt[i][i];
	    }
	    printf("\nCoeficientes do polinomio da interpolacao: \n");
	    for(i=1; i<=z; i++)
	    {
	        printf("\nx[%d]=%.3f",i,o[i]);
	    }
	    return 0;
   	}
   	if (q==2){ //matriz de vandermonde baseada nas colunas
		for(i=0;i<1;i++){ //1 na primeira coluna
			for (j=0;j<y;j++){
				disp[i][j]=1;
			}
   		}
   		for (i=1;i<2;i++){ //adição dos elementos principais
   			for(j=0;j<y;j++){
   				printf("\nPosicione o elemento a[%d][%d]: ",i+1,j+1);
   				scanf("%d",&disp[i][j]);
			}
		}
		for (i=2;i<x;i++){	//calculo das potencias que seguem nas proximas colunas
			for(j=0;j<y;j++){
				disp[i][j] = pow(disp[1][j],i);
			}
		}
	
   		printf("\n\nMatriz de Vandermonde:\n\n"); 
   		for(i=0; i<x; i++) { //impressão da matriz no console
    		for(j=0;j<y;j++) {
         		printf("  %d ", disp[j][i]);
      		}
			printf("\n\n");
   		}
   		printf ("Calculo do Determinante: ");
   		for (j=0,i=1;j<y;j++){ //calculo do determinante
   			for (u=j;u>=0;u--){
   				if(disp[i][j]>disp[i][u]){
   					det=(disp[i][j]-disp[i][u])*w;
   					w=det;
   					printf("(%d - %d)",disp[i][j],disp[i][u]);
				}
			}
		}
		printf(" = %d\n\nDeterminante da Matriz = %d",det,det);
		z=x;
		printf ("\n\nInterpolacao:\n");
		for(i=0;i<x;i++){ 
			for (j=0;j<y;j++){
				inter[i][j]=disp[i][j];
			}
		}
		for (j=0;j<y;j++){//coleta dos valores da interpolação
			printf("\nInsira o valor de y[%d]: ",j+1);
			scanf("%d",&inter[z][j]);
			}
		printf ("\n");
    	for (i = 0; i < x; i++){//transposição da matriz
    		for (j = 0; j <= y; j++){
    			dispt[i+1][j+1] = inter[j][i];
				printf("  %d ",dispt[i+1][j+1]);
			}
			printf ("\n\n");
		}
	
		for(j=1; j<=z; j++) //triangulação superior da matriz pelo metodo de gauss
	    {
	        for(i=1; i<=z; i++)
	        {
	            if(i>j)
	            {
	                p=dispt[i][j]/dispt[j][j];
	                for(k=1; k<=z+1; k++)
	                {
	                    dispt[i][k]=dispt[i][k]-(p*dispt[j][k]);
	                }
	            }
	        }
	    }
	    o[z]=dispt[z][z+1]/dispt[z][z];
	    for(i=z; i>=1; i--)
	    {
	        soma=0;
	        for(j=i+1; j<=z; j++)
	        {
	            soma=soma+dispt[i][j]*o[j];
	        }
	        o[i]=(dispt[i][z+1]-soma)/dispt[i][i];
	    }
	    printf("\Coeficientes do polinomio da interpolacao: \n");
	    for(i=1; i<=z; i++)
	    {
	        printf("\nx[%d]=%.3f",i,o[i]);
	    }
	    return 0;
   	}
   	else {
		printf ("Houve um erro!");
		return 0;
	}
	
}



