#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	
	FILE *myfile_open;
	long places_d = 0;
	char string_arquivo[1048576];
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
		if(c == '\n'){
			lines++; //coluna numero de linha do arquivo
			num = -1;
			num2++;	
		}
	
		num++;
	}
	fclose(myfile_open);
	
	for(int i = 0; i < lines; i ++){
		
		printf("|%d| %s \n",i+1,b[i]);	// pritando para o usuario o arquivo
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
			memset(b[seleciona_linha],0,sizeof(b[0]));
			strcpy(b[seleciona_linha],edita_linha);
			memset(string_arquivo,0,sizeof(string_arquivo));
			for(int linha = 0;linha < lines;linha++){
				//palaces_d = chars de d para arquivo
				for(int coluna = 0;coluna<sizeof(b[0]);coluna++){
					if((b[linha][coluna]) == '\000'){
						//string_arquivo[places_d] = b[i][coluna];
						//string_arquivo[places_d] = '-';
						places_d++;
						break;
					}
					else{
						string_arquivo[places_d] = b[linha][coluna];
						places_d++;	
					}
				}
			}
		}
		myfile_open = fopen("texto2.txt","w");

		if(myfile_open == NULL){
		printf("not workin");
		exit(1);
		}

		for(int caractere = 0; caractere <sizeof(string_arquivo);caractere++){
			putc(string_arquivo[caractere],myfile_open);
		}
			
		return 0;
	}

	else{
		return 0;
	}
}
