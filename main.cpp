#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	char reserva[10][6] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};
	int fileira = 0, acento = 0;
  char poltrona;
  bool isReserved;
	
	while(true){	
		printf("\nDigite a fileira (1-10): ");
		scanf("%d", &fileira);

		if(fileira < 1 || fileira > 10){
      cout << "\nFileira inválida. Por favor, digite um número entre 1 e 10.";
      continue;
    }

		printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
		scanf(" %c", &poltrona);

		isReserved = reserva[fileira - 1][acento] == 'x';
    if(isReserved){
      cout << "\nPoltrona já reservada. Por favor, escolha outra.\n";
      continue;
    }

		switch(poltrona){
			case 'A':
			case 'a':
				acento = 0;
				break;
			case 'B':
			case 'b':
				acento = 1;
				break;
			case 'C':
			case 'c':
				acento = 2;
				break;
			case 'D':
			case 'd':
				acento = 3;
				break;
			case 'E':
			case 'e':
				acento = 4;
				break;
			case 'F':
			case 'f':
				acento = 5;
				break;
			default:
				printf("\nPoltrona inválida");
				continue;
		}
	
		reserva[fileira-1][acento] = 'x';
		printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
    for(int x = 0; x < 10; x++){
      if(x != 9){
        printf("\n\t0%d\t", x + 1);
			}else{
        printf("\n\t%d\t", x + 1);
			}
    	for(int y = 0; y < 6; y++){
        cout << "[" << reserva[x][y] << "] ";
        if(y == 2){
            printf("\t");
        }
      }
    }
    printf("\n");
	}
	return 0;
}