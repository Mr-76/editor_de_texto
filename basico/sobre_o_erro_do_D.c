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
			lines++;
		//	printf("array eh\n");
		//	printf("%s\n",h);
			
			strcpy(b[num2],h);
			num = -1;
			num2++;	
			memset(h,0,sizeof(h));
		}
	
		num++;
	}
	fclose(myfile_open);
	
	for(int i = 0;i<lines;i++){
		
		printf("|%d| %s \n",i+1,b[i]);	
	}
	


	for(int i = 0;i<lines;i++){
		strcat(d,b[i]);
	}
	
//	strcpy(salvad,d);
	
//	printf("printando salvad%s",salvad); /// !!! por algum motivo ao chamar salvad o conteudo de d agora tb eh de salvad
						/// caso nao faça isso o conteudo de d vira o input do fgets na linha abaixo
						/// pode ser algo sobre o endereço de memoria :()
//	printf("digite o texto que quer substituir \n\n");
		
	printf("printando d%s",d);
	
	
	fgets(edita_linha,1024,stdin);
	
	
	printf("printando d%s",d);
	
//	printf("printando salvad%s",salvad);
	

	printf("selecione a linha que deseja substituir, caso nao queria editar digite 0 ");
	
	scanf("%d",&seleciona_linha);

	
	printf("linha %d",seleciona_linha);
	
	if(seleciona_linha != 0){
		printf("entrou");
		seleciona_linha--;
		strcpy(b[seleciona_linha],edita_linha);
		char d[] = "";
		for(int i = 0;i<lines;i++){
			strcat(d,b[i]);
		}	
	
	}

	else{	

		printf("result %s %c",d);

		myfile_open = fopen("texto2.txt","w");

		if(myfile_open == NULL){
	//	printf("not workin");
		exit(1);
		
		}

		for(int i =0;d[i];i++){
			putc(d[i],myfile_open);
		}

	}
	return 0;
}
