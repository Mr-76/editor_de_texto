#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	
	FILE *myfile_open;
	
	char d[] = "";
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
		h[num] = c;
		if(c == '\n'){
			lines++; //conta numero de linha do arquivo
			
			strcpy(b[num2],h);//copiar conteudo de h uma string para b uma array 2d [[string1],[string2],etc]
			num = -1;
			num2++;	
			memset(h,0,sizeof(h)); //limpar h 
		}
	
		num++;
	}
	fclose(myfile_open);
	
	for(int i = 0;i<lines;i++){
		
		printf("|%d| %s \n",i+1,b[i]);	// pritando para o usuario o arquivo
	}
	


	for(int i = 0;i<lines;i++){ //junta d string com cada uma das strings em b
		strcat(d,b[i]);
	}
	
	
//	printf("printando salvad%s",salvad); // problema :> 
	
	printf("digite o texto que quer substituir \n\n");	
	
	fgets(edita_linha,1024,stdin); 
	
	
	printf("selecione a linha que deseja substituir, caso nao queria editar digite 0 ");
	
	scanf("%d",&seleciona_linha);
	
	
	if(seleciona_linha != 0){
		printf("entrou\n");
		if(seleciona_linha != 0){
			seleciona_linha--; //indice de linha correto 

			strcpy(b[seleciona_linha],edita_linha);
			memset(d,0,sizeof(d));
			for(int i = 0;i<lines;i++){
				strcat(d,b[i]);
			}
		}
		myfile_open = fopen("texto2.txt","w");

		if(myfile_open == NULL){
		printf("not workin");
		exit(1);
		
		}

		for(int i =0;d[i];i++){
			putc(d[i],myfile_open);
		}
		
		return 0;
	}

	else{
		return 0;

	

	}
}
