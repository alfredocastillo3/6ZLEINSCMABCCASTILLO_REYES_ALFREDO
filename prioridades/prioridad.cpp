#include <stdio.h>
int amount = 1000;
float deposit, withdraw;
int choice, pin, k;
char transaction ='s';

void main(void){
	while (pin != 1520){
		printf("Por favor, ingrese su n�mero PIN secreto:\n");
		scanf("%d", &pin);
		if (pin != 1520)
		printf("Por favor, ingrese su contrase�a.\n");
	}
	do{
		printf("***Bienvenido al servicio del cajero autom�tico***\n");
		printf("1. Verificar saldo.\n");
		printf("2. Retirar dinero.\n");
		printf("3. Depositar dinero.\n");
		printf("4. Salir.\n");
		printf("**************************************************\n\n");
		printf("Ingrese su elecci�n:\n");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			printf("\n Tu balance en S/%d ", amount); break;
		case 2:
			printf("\n Ingrese el monto a retirar:\n");
			scanf("%f", &withdraw);
			if (withdraw >(amount - 500)){
				printf("\n Saldo insuficiente.");
			}
			else{
				amount = amount - withdraw;
				printf("\n\n Por favor, cobrar dinero en efectivo.");
				printf("\n Tu saldo actual es %f", amount);
			} break;
		case 3:
			printf("\n Ingrese la cantidad para depositar:\n");
			scanf("%f", &deposit);
            amount = amount + deposit;
			printf("Tu saldo es %f", amount); break;
		case 4:
			printf("\n Gracias por usar el cajero autom�tico!"); break;
		default:
			printf("\n Elecci�n inv�lida");
		}
		printf("\n\n\n �Desea tener otra transacci�n?(s/n): \n");
		fflush(stdin);
		scanf("%c", &transaction);
		if (transaction == 'n'|| transaction == 'N')
                    k = 1;
	} while (!k);
	printf("\n\n Gracias por utilizar el servicio del cajero autom�tico!");
} 
reutn 0
}

