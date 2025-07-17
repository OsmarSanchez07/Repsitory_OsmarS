#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu(){
    printf("Bienvenido a la calculadora\n");
    printf("Seleccione una operacion:\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Potenciar\n");
    printf("6. Raiz cuadrada\n");
    printf("7. Valor absoluto\n");
    printf("8. Salir\n");
    printf("Ingrese su opcion: ");
}

int sumar (int a, int b){
    return a + b;
}

int restar (int a, int b){
    return a - b;
}

int multiplicar (int a, int b){
    return a * b;
}

float dividir (float a, float b){
    if (b==0) {
        printf("Error: Division por cero no permitida.\n");
        return 0;
    }
    return a / b;
}

int potenciar(int a, int b){
    return (int)pow(a,b);
}

int raiz (int a){
    return (int)sqrt(a);
}

int valor_abs (int a){
    return abs (a);
}

int salir(){
    printf("Gracias por usar la calculadora\n");
    return 0;
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpiar_consola() {
    system("cls");
}

int main(){
    int num1, num2, respuesta, continuar;

    do {
        limpiar_consola();
        menu();
        scanf("%d", &respuesta);

        switch(respuesta){
            case 1:
                printf("Ingrese el primer numero: ");
                scanf("%d",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%d",&num2);
                printf("El resultado de la suma es: %d\n\n",sumar(num1,num2));
                break;
            case 2:
                printf("Ingrese el primer numero: ");
                scanf("%d",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%d",&num2);
                printf("El resultado de la resta es:%d\n", restar(num1,num2));
                break;
            case 3:
                printf("Ingrese el primer numero: ");
                scanf("%d",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%d",&num2);
                printf("El resultado de la multiplicacion es: %d\n", multiplicar(num1,num2));
                break;
            case 4:
                printf("Ingrese el primer numero: ");
                scanf("%d",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%d",&num2);
                printf("El resultado de la division es: %0.2f\n", dividir(num1,num2));
                break;
            case 5:
                printf("Ingrese el primer numero: ");
                scanf("%d",&num1);
                printf("Ingrese el segundo numero: ");
                scanf("%d",&num2);
                printf("El resultado de la potenciacion es: %d\n", potenciar(num1,num2));
                break;
            case 6:
                printf("Ingrese el numero: ");
                scanf("%d",&num1);
                printf("El resultado de la raiz es: %d\n", raiz(num1));
                break;
            case 7:
                printf("Ingrese el numero: ");
                scanf("%d",&num1);
                printf("El resultado del valor absoluto es: %d\n", valor_abs(num1));
                break;
            case 8:
                salir();
                return 0;
            default:
                printf("Opcion no valida, por favor intente de nuevo.\n");
                break;
        }

        printf("Desea realizar otra operacion? (1: Si, 0: No): ");
        limpiar_buffer();
        fflush(stdin);
        scanf("%d", &continuar);

    } while (continuar == 1);

    printf("Gracias por usar la calculadora\n");
    return 0;
}