#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios;//atributos originais do teminal
/*deixa teminal em raw mode como quando usa o sudo*/

void disabeRawMode(){
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&orig_termios);

}

void enableRawMode(){

	tcgetattr(STDIN_FILENO,&orig_termios);//le atributos do terminal

	atexit(disabeRawMode); //vem da stdlib usa pra registar a funcao disablerawmode quando sai do programa

	
	struct termios raw = orig_termios;
	
	raw.c_lflag &= ~(ECHO | ICANON); //desliga o printar das teclas no termina

	
	
	tcsetattr(STDIN_FILENO,TCSAFLUSH, &raw);//seta os novos atributos
						//tca flush especifica quando aplicar a mudança


}


int main(){
	enableRawMode();

	char c;
	while (read(STDIN_FILENO,&c,1) == 1 && c != 'q'){
		if (iscntrl(c)){ //o iscntrl testa se um caractere eh um caracter de controle e nao sao printaveis
			printf("%d\n",c);
		
		} 
		else{
			printf("%d ('%c')\n",c,c); // printa oq vc escreveu e tb o codigo ascII respectivo
		}				   // pritna os byte o enter eh o byte 10
	}
	return 0;
}


