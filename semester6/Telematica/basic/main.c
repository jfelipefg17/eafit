#include <stdio.h>

int main(void) {
    // 1. Declaración de las 5 variables básicas
    int entero = 10;          // Declara una variable entera y le asigna el valor 10
    float flotante = 3.14;     // Declara una variable flotante con el valor de PI aproximado
    char caracter = 'A';       // Declara una variable de tipo caracter con el valor 'A'
    double doble = 5.6789;     // Declara una variable de doble precisión con el valor 5.6789
    char cadena[] = "Hola, mundo"; // Declara una cadena de caracteres

    // Imprime las variables declaradas
    printf("//// Variables ////\n");
    printf("Entero: %d, Flotante: %.2f, Caracter: %c, Doble: %.4f, Cadena: %s\n", entero, flotante, caracter, doble, cadena);
    printf("///////////////////\n\n");

    // 2. Uso de if, else if y else para evaluar condiciones
    printf("//// Condicionales ////\n");
    if (entero > 10) { // Si el entero es mayor que 10k,;;
        printf("El entero es mayor que 10\n");
    } else if (entero == 10) { // Si el entero es igual a 10
        printf("El entero es igual a 10\n");
    } else { // Si el entero es menor que 10
        printf("El entero es menor que 10\n");
    }
    printf("/////////////////////\n\n");

    // 3. Declaración y uso de un array con un bucle while
    printf("//// Bucle While ////\n");
    int arreglo[5] = {1, 2, 3, 4, 5}; // Declaración de un arreglo de 5 elementos
    int i = 0; // Inicialización de contador
    while (i < 5) { // Mientras i sea menor que 5
        printf("Elemento %d: %d\n", i, arreglo[i]); // Imprime cada elemento del arreglo
        i++; // Incrementa i
    }
    printf("///////////////////\n\n");

    // 4. Bucle do-while
    printf("//// Bucle Do-While ////\n");
    i = 0;
    do {
        printf("Elemento %d: %d\n", i, arreglo[i]); // Imprime elementos del arreglo
        i++;
    } while (i < 5); // Se ejecuta al menos una vez
    printf("///////////////////////\n\n");

    // 5. Bucle for
    printf("//// Bucle For ////\n");
    for (i = 0; i < 5; i++) { // Recorre el arreglo usando un bucle for
        printf("Elemento %d: %d\n", i, arreglo[i]);
    }
    printf("///////////////////\n\n");

    // 6. Uso de switch para evaluar un caracter
    printf("//// Estructura Switch ////\n");
    switch (caracter) {
        case 'A': // Si el caracter es 'A'
            printf("El caracter es A\n");
            break;
        case 'B': // Si el caracter es 'B'
            printf("El caracter es B\n");
            break;
        default: // Cualquier otro caracter
            printf("Caracter no identificado\n");
            break;
    }
    printf("////////////////////////\n\n");

    // 7. Manejo de errores con try-catch simulado mediante condicional
    printf("//// Try-Catch Simulado ////\n");
    int divisor = 0; // Simula un divisor igual a cero
    if (divisor == 0) { // Simulación de manejo de error
        printf("Error: División por cero detectada.\n");
    } else {
        printf("Resultado: %d\n", entero / divisor);
    }
    printf("///////////////////////////\n\n");

    // 8. Ejemplo combinado de todo
    printf("//// Ejemplo Completo ////\n");
    if (entero < 20) { // Verifica si el entero es menor que 20
        for (i = 0; i < 5; i++) { // Bucle for para recorrer elementos
            printf("Iteracion %d: Entero=%d, Flotante=%.2f, Caracter=%c, Cadena=%s\n", i, entero, flotante, caracter, cadena);
        }
        i = 0;
        while (i < 5) { // Bucle while dentro del ejemplo combinado
            printf("While Iteracion %d: %d\n", i, arreglo[i]);
            i++;
        }
        divisor = 0; // Simulación de error dentro del ejemplo combinado
        if (divisor == 0) {
            printf("Error: División por cero detectada en el ejemplo combinado.\n");
        } else {
            printf("Resultado: %d\n", entero / divisor);
        }
    } else {
        printf("El valor del entero es demasiado alto\n");
    }
    printf("/////////////////////////\n");

    return 0; // Retorno exitoso
}