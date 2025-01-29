package org.example;

public class Main {

    public void main1(int num1, int num2) {
        if (num1 == num2) {
            System.out.println("result is: " + num1 + num2);
        } else {
            System.out.println("you cant add that number");
        }
    }

    public static void main(String[] args) {

        Main main = new Main();
        main.main1(1, 2);


        // 1. Declaración de las 5 variables básicas
        int entero = 10; // Declara una variable entera y le asigna el valor 10
        float flotante = 3.14f; // Declara una variable flotante con el valor de PI aproximado
        char caracter = 'A'; // Declara una variable de tipo caracter con el valor 'A'
        double doble = 5.6789; // Declara una variable de doble precisión con el valor 5.6789
        String cadena = "Hola, mundo"; // Declara una cadena de caracteres

        // Imprime las variables declaradas
        System.out.println("//// Variables ////");
        System.out.println(entero + "/" + flotante + "/" + caracter + "/" + doble + "/" + cadena);
        System.out.println("///////////////////");

        // 2. Uso de if, else if y else para evaluar condiciones
        System.out.println("//// Condicionales ////");
        if (entero > 10) { // Si el entero es mayor que 10
            System.out.println("El entero es mayor que 10");
        } else if (entero == 10) { // Si el entero es igual a 10
            System.out.println("El entero es igual a 10");
        } else { // Si el entero es menor que 10
            System.out.println("El entero es menor que 10");
        }
        System.out.println("/////////////////////");

        // 3. Declaración y uso de un array con un bucle while
        System.out.println("//// Bucle While ////");
        int[] arreglo = {1, 2, 3, 4, 5}; // Declaración de un arreglo de 5 elementos
        int i = 0; // Inicialización de contador
        while (i < 5) { // Mientras i sea menor que 5
            System.out.println("Elemento " + i + ": " + arreglo[i]); // Imprime cada elemento del arreglo
            i++; // Incrementa i
        }
        System.out.println("///////////////////");

        // 4. Bucle do-while
        System.out.println("//// Bucle Do-While ////");
        i = 0;
        do {
            System.out.println("Elemento " + i + ": " + arreglo[i]); // Imprime elementos del arreglo
            i++;
        } while (i < 5); // Se ejecuta al menos una vez
        System.out.println("///////////////////////");

        // 5. Bucle for
        System.out.println("//// Bucle For ////");
        for (i = 0; i < 5; i++) { // Recorre el arreglo usando un bucle for
            System.out.println("Elemento " + i + ": " + arreglo[i]);
        }
        System.out.println("///////////////////");

        // 6. Uso de switch para evaluar un caracter
        System.out.println("//// Estructura Switch ////");
        switch (caracter) {
            case 'A': // Si el caracter es 'A'
                System.out.println("El caracter es A");
                break;
            case 'B': // Si el caracter es 'B'
                System.out.println("El caracter es B");
                break;
            default: // Cualquier otro caracter
                System.out.println("Caracter no identificado");
                break;
        }
        System.out.println("////////////////////////");

        // 7. Manejo de errores con try-catch
        System.out.println("//// Try-Catch ////");
        int divisor = 0; // Simula un divisor igual a cero
        try {
            System.out.println("Resultado: " + (entero / divisor));
        } catch (ArithmeticException e) {
            System.out.println("Error: División por cero detectada.");
        }
        System.out.println("///////////////////////////");

        // 8. Ejemplo combinado de todo
        System.out.println("//// Ejemplo Completo ////");
        if (entero < 20) { // Verifica si el entero es menor que 20
            for (i = 0; i < 5; i++) { // Bucle for para recorrer elementos
                System.out.println("Iteracion " + i + ": Entero=" + entero + ", Flotante=" + flotante + ", Caracter=" + caracter + ", Cadena=" + cadena);
            }
            i = 0;
            while (i < 5) { // Bucle while dentro del ejemplo combinado
                System.out.println("While Iteracion " + i + ": " + arreglo[i]);
                i++;
            }
            divisor = 0; // Simulación de error dentro del ejemplo combinado
            try {
                System.out.println("Resultado: " + (entero / divisor));
            } catch (ArithmeticException e) {
                System.out.println("Error: División por cero detectada en el ejemplo combinado.");
            }
        } else {
            System.out.println("El valor del entero es demasiado alto");
        }
        System.out.println("/////////////////////////");
    }
}
