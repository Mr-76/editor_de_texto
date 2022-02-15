#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	
	FILE *myfile_open;
	long places_d = 0;
	char d[1048576];
	char salvad[1024];
	char c;
	char edita_linha[1024];
	int seleciona_linha;
	char b[1024][1024];
	char h[1024];
	char concatena[1024];
	int num = 0;
	int num2 = 0;
	int lines = 0;
	myfile_open = fopen("texto.txt","r");

	if(myfile_open == NULL){
	printf("not workin");
	exit(1);
	
	}
	
	while((c = getc(myfile_open)) != EOF){
		b[num2][num] = c; 
		printf("%c",c);
		if(c == '\n'){
			lines++; //conta numero de linha do arquivo
			num = -1;
			num2++;	
		}
	
		num++;
	}
return 0;
}
