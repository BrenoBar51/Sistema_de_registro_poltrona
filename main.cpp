#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");

	//Inicializando matriz

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

	//variaveis utilizadas

	int fileira = 0, acento = 0, passagem = 0;
	char poltrona, outraReserva;
	bool jaReservado;

	//validações e loops

	while(true){
		printf("\nDigite o tipo de passagem(1-EXECUTIVA ou 2-ECONÔMICA): ");
		scanf("%d", &passagem);
		
		if(passagem < 1 || passagem > 2){
			cout << "\nTipo de passagem inválida! Por favor, selecione(1-EXECUTIVA ou 2-ECONÔMICA)";
			continue;
		}

		printf("\nDigite a fileira (1-10): ");
		scanf("%d", &fileira);

		if(fileira < 1 || fileira > 10){
			cout << "\nFileira inválida. Por favor, digite um número entre 1 e 10.";
			continue;
		}

		printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
		scanf(" %c", &poltrona);

		if(passagem == 2){
			switch (poltrona){
				case 'A':
				case 'a':
					acento = 0;
					cout << "Poltronas A e F reservadas apenas para classe Executiva!";
					continue;
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
					cout << "Poltronas A e F reservadas apenas para classe Executiva!";
					continue;
				default:
					printf("\nPoltrona inválida");
					continue;
			}
		}

		jaReservado = reserva[fileira - 1][acento] == 'x';
		if(jaReservado){
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

		reserva[fileira - 1][acento] = 'x';
		printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");

		printf("\nFazer outra reserva ?(y/n): ");
		scanf(" %c", &outraReserva);

		switch(outraReserva){
			case "y":
			case "Y":
				continue;
			case "n":
			case "N":
				break;
			default:
				cout << "Digite uma opção válida!";
				continue;
		}

		for(int x = 0; x < 10; x++){
			if(x != 9){
				printf("\n\t0%d\t", x + 1);
			}else{
				printf("\n\t%d\t", x + 1);
			}
			for(int y = 0; y < 6; y++){
				cout << "[" << reserva[x][y] << "] ";
				if (y == 2){
					printf("\t");
				}
			}
		}
		printf("\n");
	}
	return 0;
}