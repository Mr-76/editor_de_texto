#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;//atributos originais do teminal
/*deixa teminal em raw mode como quando usa o sudo*/

void disabeRawMode(){
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&orig_termios);

}

void enableRawMode(){

	tcgetattr(STDIN_FILENO,&orig_termios);//le atributos do terminal

	atexit(disabeRawMode); //vem da stdlib usa pra registar a funcao disablerawmode quando sai do programa

	
	struct termios raw = orig_termios;
	
	raw.c_iflag &= ~(ICRNL | IXON); //ctrl-s para a transferencia de dados para o termnial e ctrl-q volta a receber
				// I - input flag XON - ctrl-s e ctrl-q XOFF
	raw.c_oflag &= ~(OPOST);//oflag - output flag, post = post processing of output -- os terminal faz \r\n
				//terminal transforma o \n em \r\n
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN |ISIG); //desliga o printar das teclas no termina
						// isig nao deixa os isnais sigint do crtl-c -- terminate e sigstop suspender o processo
	
	
	tcsetattr(STDIN_FILENO,TCSAFLUSH, &raw);//seta os novos atributos
						//tca flush especifica quando aplicar a mudança


}


int main(){
	enableRawMode();

	char c;
	while (read(STDIN_FILENO,&c,1) == 1 && c != 'q'){
		if (iscntrl(c)){ //o iscntrl testa se um caractere eh um caracter de controle e nao sao printaveis
			printf("%d\r\n",c);
		
		} 
		else{
			printf("%d ('%c')\r\n",c,c); // printa oq vc escreveu e tb o codigo ascII respectivo
		}				   // pritna os byte o enter eh o byte 10
	}
	return 0;
}


