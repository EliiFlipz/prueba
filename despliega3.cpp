/* programa para imprimir el contenido en la linea de comando */

#include<stdio.h>
#include<stdlib.h>

int main(int argc , char **argv)
{

	int i;
	FILE *ptold,*ptnew;
	char c[255];
	
	if(argc < 3)
	{
		printf("Uso del Comando: %s <patname> <pathaname> \n", argv[0]);
	    exit(0);
	}
	else
	   {
	   	if( ( ptold = fopen(argv[1], "rt")) == NULL)
	   	{
	   		printf("No se pudo abrir el archivo: %s\n",argv[0]);
	   		exit(0);
		}
		if( ( ptnew = fopen(argv[2], "wt")) == NULL)
	   	{
	   		printf("No se pudo abrir el archivo: %s\n", argv[2]);
	   		exit(0);
		}
		
	   }
	
	while (!feof(ptold))
	{
		fgets(c,255,ptold);
		puts(c);
		fputs(c,ptnew);
		
    }
	
	printf("\n Se ha realizado la copia de %s a %s\n", argv[1],argv[2]);
		
 /* close the file */
 
        if( fclose(ptnew) != 0)
		{
			perror("fclose");
			exit( EXIT_FAILURE);
		}
    
 if( fclose(ptold) != 0)
		{
			perror("fclose");
			exit( EXIT_FAILURE);
		}
 return(EXIT_SUCCESS);
}
