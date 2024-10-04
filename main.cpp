#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	// Inicializando matriz

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
			{' ', ' ', ' ', ' ', ' ', ' '}};

	// variaveis utilizadas

	int fileira = -1, acento = -1, passagem = -1;
	char poltrona, outraReserva;
	bool jaReservado, poltronaValida = false;

	// loop de validação

	while (true)
	{
		do
		{
			printf("\nDigite o tipo de passagem(1-EXECUTIVA ou 2-ECONÔMICA): ");
			scanf("%d", &passagem);

			// validação seleção de passagem

			if (passagem < 1 || passagem > 2)
			{
				cout << "\nTipo de passagem inválida! Por favor, selecione(1-EXECUTIVA ou 2-ECONÔMICA)";
				continue;
			}
		} while (passagem < 1 || passagem > 2);

		do
		{
			printf("\nDigite a fileira (1-10): ");
			scanf("%d", &fileira);

			// validação quantidade de fileiras

			if (fileira < 1 || fileira > 10)
			{
				cout << "\nFileira inválida. Por favor, digite um número entre 1 e 10.";
				continue;
			}
		} while (fileira < 1 || fileira > 10);

		do
		{
			printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
			scanf(" %c", &poltrona);

			poltrona = toupper(poltrona); // Para converter letras minúsculas para maiúscula automaticamente

			////validação tipo de passagem e poltrona selecionada

			switch (poltrona)
			{
			case 'A':
				acento = 0;
				poltronaValida = true;
				break;
			case 'B':
				acento = 1;
				poltronaValida = true;
				break;
			case 'C':
				acento = 2;
				poltronaValida = true;
				break;
			case 'D':
				acento = 3;
				poltronaValida = true;
				break;
			case 'E':
				acento = 4;
				poltronaValida = true;
				break;
			case 'F':
				acento = 5;
				poltronaValida = true;
				break;
			default:
				cout << "\nPoltrona inválida";
				poltronaValida = false;
				break;
			}

			if (passagem == 2 && (acento == 0 || acento == 5))
			{
				cout << "\nPoltronas A e F reservadas apenas para passagens Executivas!";
				poltronaValida = false;
			}
		} while (!poltronaValida);

		// verificação se poltrona selecionada já foi reservada

		jaReservado = reserva[fileira - 1][acento] == 'x';
		if (jaReservado)
		{
			cout << "\nPoltrona já reservada. Por favor, escolha outra.\n";
			continue;
		}

		// Resultado da ação de reserva

		reserva[fileira - 1][acento] = 'x';
		printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");

		for (int x = 0; x < 10; x++)
		{
			if (x != 9)
			{
				printf("\n\t0%d\t", x + 1);
			}
			else
			{
				printf("\n\t%d\t", x + 1);
			}
			for (int y = 0; y < 6; y++)
			{
				cout << "[" << reserva[x][y] << "] ";
				if (y == 2)
				{
					printf("\t");
				}
			}
		}

		// Validação caso o cliente queira continuar fazendo reservas ou não
		printf("\nFazer outra reserva ?(y/n): ");
		scanf(" %c", &outraReserva);

		outraReserva = toupper(outraReserva); // Para converter letras minúsculas para maiúscula automaticamente

		switch (outraReserva)
		{
		case 'Y':
			continue;
		case 'N':
			break;
		default:
			cout << "\nResposta inválida!";
			continue;
		}
		printf("\n");
		break;
	}
	return 0;
}