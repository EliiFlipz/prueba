/* programa para imprimir el contenido en la linea de comando */

#include<stdio.h>
#include<stdlib.h>

int main(int argc , char **argv)
{

	int i;
	FILE *ptnew;
	char c[255];
	
	if(argc != 2)
	{
		printf("Uso del Comando: %s <pathaname> \n", argv[0]);
	    exit(0);
	}
	else
		if( ( ptnew = fopen(argv[1], "w")) == NULL)
	   	{
	   		printf("No se pudo abrir el archivo: %s\n", argv[1]);
	   		exit(0);
		}
		
	   	
	    fprintf(ptnew," Hello file by fprintf... \n");
	    if( fclose(ptnew) != 0)
		{
			perror("fclose");
			exit( EXIT_FAILURE);
		}
		
		if( ( ptnew = fopen(argv[1], "r")) == NULL)
	   	{
	   		printf("No se pudo abrir el archivo: %s\n", argv[1]);
	   		exit(0);
		}
		
	    while(fscanf(ptnew,"%s",c) != EOF)
		{
		printf("%s ",c);	
		};
		
		 /* close the file */
 
        if( fclose(ptnew) != 0)
		{
			perror("fclose");
			exit( EXIT_FAILURE);
		}
    
 return(EXIT_SUCCESS);
}
