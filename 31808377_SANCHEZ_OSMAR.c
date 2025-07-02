/*NOMBRE: OSMAR SANCHEZ
CI: 31.808.377
SECCION: 10


*/


#include <stdio.h>
#include <string.h>

#define MAX 100
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

int main() {

    char titulo_libro[MAX][50];
    char autor_libro[MAX][50];
    char genero_libro[MAX][50];
    char isbn_libro[MAX][11];
    int stock[MAX];
    float precio_libro[MAX];
    float ganancia_libro[MAX];

    int n;
    int i;

     printf("IMPORTANTE: ESCRIBA TODO EN MAYUSCULAS\n\n");

    printf(" Cuantos libros quiere registrar? ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {

        //se piden los datos de los libro (EN MAYUSCULAS)
        printf("\nLIBRO #%d\n", i + 1);

        printf("TITULO (MAYUSCULAS): ");
        fgets(titulo_libro[i], 50, stdin);
        titulo_libro[i][strcspn(titulo_libro[i], "\n")] = '\0';

        printf("AUTOR (MAYUSCULAS): ");
        fgets(autor_libro[i], 50, stdin);
        autor_libro[i][strcspn(autor_libro[i], "\n")] = '\0';

        printf("GENERO (MAYUSCULAS): ");
        fgets(genero_libro[i], 50, stdin);
        genero_libro[i][strcspn(genero_libro[i], "\n")] = '\0';

        do {
            printf("ISBN (10 digitos): ");
            fgets(isbn_libro[i], 11, stdin);
            isbn_libro[i][strcspn(isbn_libro[i], "\n")] = '\0';
            if (strlen(isbn_libro[i]) < 10) {
                printf("ERROR: ISBN DEBE TENER 10 DIGITOS.\n");
            }
        } while (strlen(isbn_libro[i]) < 10);
        getchar();

        do {
            printf("Precio unitario: ");
            scanf("%f", &precio_libro[i]);
            if (precio_libro[i] < 0) {
                printf("ERROR: PRECIO NO PUEDE SER NEGATIVO.\n");
            }
        } while (precio_libro[i] < 0);

        printf("Cantidad en inventario: ");
        scanf("%d", &stock[i]);
        getchar();

        ganancia_libro[i] = precio_libro[i] * stock[i];
    }

    printf("\n%-20s %-20s %-20s %-12s %-10s %-10s %-10s\n",//sacado de internet para espaciar unos textos de otros

           "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK", "GANANCIA");

    for (i = 0; i < n; i++) {
        printf("%-20s %-20s %-20s %-12s $%-9.2f %-10d ",
               titulo_libro[i], autor_libro[i], genero_libro[i], isbn_libro[i], precio_libro[i], stock[i]);

        if (ganancia_libro[i] >= 0) {
            printf(GREEN "%.2f" RESET "\n", ganancia_libro[i]);
        } else {
            printf(RED "%.2f" RESET "\n", ganancia_libro[i]);
        }
    }

    //aqui hago la parte  qu sirve para buscar el libro

    char campo[20];
    char dato[50];

        printf("\nEscoja una opcion para buscar TITULO/AUTOR/GENERO/ISBN (MAYUSCULAS): ");
    fgets(campo, 20, stdin);
    campo[strcspn(campo, "\n")] = '\0';

     printf("Dato para buscar (MAYUSCULAS): ");
    fgets(dato, 50, stdin);
    dato[strcspn(dato, "\n")] = '\0';

                printf("\nRESULTADOS:\n");

    int encontrado = 0;

    for (i = 0; i < n; i++) {
        int coincide = 0;

        if (strcmp(campo, "TITULO") == 0 && strstr(titulo_libro[i], dato)) {
            coincide = 1;
        } else if (strcmp(campo, "AUTOR") == 0 && strstr(autor_libro[i], dato)) {
            coincide = 1;
        } else if (strcmp(campo, "GENERO") == 0 && strstr(genero_libro[i], dato)) {
            coincide = 1;
        } else if (strcmp(campo, "ISBN") == 0 && strstr(isbn_libro[i], dato)) {
            coincide = 1;
        }

        if (coincide == 1) {
            encontrado = 1;
            printf("%s | %s | %s | %s | $%.2f | STOCK: %d | GANANCIA: ",

                titulo_libro[i], autor_libro[i], genero_libro[i], isbn_libro[i], precio_libro[i], stock[i]);

                //aqui me ayudé de internet pq no sabia como poner colores
            if (ganancia_libro[i] >= 0) {
                printf(GREEN "%.2f" RESET "\n", ganancia_libro[i]);
            } else {
                printf(RED "%.2f" RESET "\n", ganancia_libro[i]);
            }
        }
    }

    if (encontrado == 0) {
        printf("No se encontraron coincidencias.\n");
    }

    return 0;
}

