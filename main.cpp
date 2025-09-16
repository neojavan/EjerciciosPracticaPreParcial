#include <iostream> // Para entrada/salida estándar (cin, cout)
#include <vector>   // Para std::vector en algunos ejercicios (ej. secuencia de números)
#include <string>   // Para std::string en ejercicios de texto
#include <limits>   // Para std::numeric_limits y limpiar el buffer de entrada

// --- Prototipos de funciones para cada ejercicio ---
// Declaración de las funciones para que main() pueda llamarlas antes de su definición.
void ejecutarEjercicio1(); // Análisis de Calificaciones
void ejecutarEjercicio2(); // Encuesta de Satisfacción del Cine
void ejecutarEjercicio3(); // Validador de Secuencia Numérica
void ejecutarEjercicio4(); // Calculadora de Descuentos por Volumen
void ejecutarEjercicio5(); // Buscador del Primer Carácter Único
void ejecutarEjercicio6(); // Generador de Serie Fibonacci
void fibonacci(); // Función auxiliar para generar Fibonacci

// --- Función para limpiar el buffer de entrada ---
// Es útil para evitar problemas cuando se mezclan lecturas de números y líneas de texto.
void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// --- Función Principal (main) ---
int main() {
    int opcion; // Variable para almacenar la opción seleccionada por el usuario

    // Bucle principal del menú: se ejecuta hasta que el usuario elija salir (opción 0)
    do {
        // Mostrar el menú de opciones al usuario
        std::cout << "\n--- MENU DE EJERCICIOS DE PROGRAMACION ---\n";
        std::cout << "1. Analisis de Calificaciones de un Curso\n";
        std::cout << "2. Encuesta de Satisfaccion del Cine\n";
        std::cout << "3. Validador de Secuencia Numerica Ascendente\n";
        std::cout << "4. Calculadora de Descuentos por Volumen\n";
        std::cout << "5. Buscador del Primer Caracter Unico en una Palabra\n";
        std::cout << "6. Generador de Serie Fibonacci\n";
        std::cout << "0. Salir\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion; // Leer la opción del usuario

        // Limpiar el buffer después de leer un entero, antes de posibles lecturas de string
        limpiarBuffer();

        // Estructura switch para ejecutar la función correspondiente a la opción
        switch (opcion) {
            case 1:
                ejecutarEjercicio1();
                break;
            case 2:
                ejecutarEjercicio2();
                break;
            case 3:
                ejecutarEjercicio3();
                break;
            case 4:
                ejecutarEjercicio4();
                break;
            case 5:
                ejecutarEjercicio5();
                break;
            case 6:
                fibonacci();
                break;
            case 0:
                std::cout << "Saliendo del programa. ¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opcion no valida. Por favor, intente de nuevo.\n";
                break;
        }
        std::cout << "\nPresione Enter para continuar...";
        std::cin.ignore(); // Esperar que el usuario presione Enter
    } while (opcion != 0); // La condición del bucle: continuar mientras la opción no sea 0

    return 0; // El programa termina con éxito
}

// --- Implementación de Ejercicio 1: Análisis de Calificaciones ---
void ejecutarEjercicio1() {
    std::cout << "\n--- EJERCICIO 1: Analisis de Calificaciones de un Curso ---\n";
    std::cout << "Enunciado: Solicita calificaciones de 8 estudiantes y reporta aprobados, reprobados, excelentes y promedio.\n";

    // --- VARIABLES ---
    // Contadores para clasificar a los estudiantes
    int contadorAprobados = 0;
    int contadorReprobados = 0;
    int contadorExcelentes = 0;

    // Acumulador para sumar todas las notas y calcular el promedio
    double sumaTotalCalificaciones = 0.0;

    // Variable para almacenar la nota de cada estudiante dentro del bucle
    double notaActual = 0.0;

    const int NUM_ESTUDIANTES = 8; // Constante para la cantidad fija de estudiantes

    std::cout << "Por favor, ingrese las calificaciones de los " << NUM_ESTUDIANTES << " estudiantes.\n";

    // Se utiliza un bucle 'for' que se repetirá exactamente NUM_ESTUDIANTES veces.
    for (int i = 1; i <= NUM_ESTUDIANTES; ++i) {
        // Se solicita la calificación del estudiante actual.
        std::cout << "Ingrese la calificacion del estudiante #" << i << ": ";
        std::cin >> notaActual;

        // Se acumula la nota ingresada para el cálculo del promedio final.
        sumaTotalCalificaciones += notaActual;

        // Se usan condicionales para clasificar la nota e incrementar los contadores.
        if (notaActual >= 3.0) {
            contadorAprobados++; // Incrementa el contador de aprobados

            // Un condicional anidado para verificar si, además de aprobar, la nota es excelente.
            if (notaActual >= 4.5) {
                contadorExcelentes++; // Incrementa el contador de excelentes
            }
        } else {
            contadorReprobados++; // Incrementa el contador de reprobados
        }
    }

    // Una vez terminado el bucle, se calcula el promedio final.
    double promedioFinal = sumaTotalCalificaciones / NUM_ESTUDIANTES;

    // --- SALIDA ---
    std::cout << "\n--- Reporte Final de Calificaciones ---\n";
    std::cout << "Cantidad de estudiantes APROBADOS (>= 3.0): " << contadorAprobados << std::endl;
    std::cout << "Cantidad de estudiantes REPROBADOS (< 3.0): " << contadorReprobados << std::endl;
    std::cout << "Cantidad de estudiantes con calificacion EXCELENTE (>= 4.5): " << contadorExcelentes << std::endl;
    std::cout << "El promedio de todas las calificaciones del curso es: " << promedioFinal << std::endl;
}

// --- Implementación de Ejercicio 2: Encuesta de Satisfacción del Cine ---
void ejecutarEjercicio2() {
    std::cout << "\n--- EJERCICIO 2: Encuesta de Satisfaccion del Cine ---\n";
    std::cout << "Enunciado: Solicita edad y calificacion. Finaliza con edad 0. Reporta totales, promedio, jovenes y calificaciones perfectas.\n";

    // --- VARIABLES ---
    // Contadores para las métricas solicitadas
    int totalEncuestados = 0;
    int contadorJovenes = 0;
    int contadorCalificacionPerfecta = 0;

    // Acumulador para sumar todas las calificaciones y calcular el promedio
    int sumaCalificaciones = 0;

    // Variables para las entradas del usuario en cada iteración
    int edadActual = -1; // Se inicializa en un valor no-cero para entrar al bucle
    int calificacionActual = 0;

    double promedioCalificaciones = 0.0;

    std::cout << "--- Ingrese Datos de la Encuesta ---\n";
    std::cout << "Ingrese la edad del cliente (o ingrese 0 para finalizar): ";
    std::cin >> edadActual;

    // Se utiliza un bucle 'while' que se ejecutará mientras la edad ingresada no sea 0.
    while (edadActual != 0) {
        // Se solicita la calificación del servicio.
        std::cout << "Ingrese la calificacion del servicio (1-10): ";
        std::cin >> calificacionActual;

        // Se incrementa el contador de personas encuestadas.
        totalEncuestados++;

        // Se acumula la calificación para el cálculo del promedio.
        sumaCalificaciones += calificacionActual;

        // Se verifica si la edad corresponde al rango de "joven".
        if (edadActual >= 18 && edadActual <= 25) {
            contadorJovenes++;
        }

        // Se verifica si la calificación fue perfecta.
        if (calificacionActual == 10) {
            contadorCalificacionPerfecta++;
        }

        // Se vuelve a pedir la edad para la siguiente iteración o para finalizar el bucle.
        std::cout << "\nIngrese la edad del siguiente cliente (o 0 para finalizar): ";
        std::cin >> edadActual;
    }

    // --- SALIDA ---
    std::cout << "\n--- Reporte Final de la Encuesta ---\n";

    // Se verifica si se encuestó al menos a una persona para evitar la división por cero.
    if (totalEncuestados > 0) {
        // Se calcula el promedio. Se usa static_cast para asegurar división de punto flotante.
        promedioCalificaciones = static_cast<double>(sumaCalificaciones) / totalEncuestados;

        std::cout << "Cantidad total de personas encuestadas: " << totalEncuestados << std::endl;
        std::cout << "Promedio de calificacion del servicio: " << promedioCalificaciones << std::endl;
        std::cout << "Cantidad de personas jovenes (18-25 anios): " << contadorJovenes << std::endl;
        std::cout << "Cantidad de personas que dieron una calificacion perfecta (10): " << contadorCalificacionPerfecta << std::endl;
    } else {
        std::cout << "No se ingresaron datos para generar un reporte.\n";
    }
}

// --- Implementación de Ejercicio 3: Validador de Secuencia Numérica ---
void ejecutarEjercicio3() {
    std::cout << "\n--- EJERCICIO 3: Validador de Secuencia Numerica Ascendente ---\n";
    std::cout << "Enunciado: Determina si una secuencia de N numeros es estrictamente ascendente.\n";

    // --- VARIABLES ---
    int cantidadNumeros = 0;
    int numeroActual = 0;
    int numeroAnterior = 0;
    bool esSecuenciaAscendente = true; // Bandera para indicar si la secuencia es ascendente

    // --- ENTRADA Y PROCESO ---
    std::cout << "Ingrese la cantidad de numeros a verificar: ";
    std::cin >> cantidadNumeros;

    // Se manejan los casos base: una secuencia de 0 o 1 número se considera ascendente.
    if (cantidadNumeros <= 1) {
        esSecuenciaAscendente = true;
    } else {
        // Se lee el primer número ANTES del bucle para tener con qué comparar.
        std::cout << "Ingrese el numero 1: ";
        std::cin >> numeroAnterior;

        // El bucle comienza en 2 porque ya leímos el primer número.
        for (int i = 2; i <= cantidadNumeros; ++i) {
            std::cout << "Ingrese el numero " << i << ": ";
            std::cin >> numeroActual;

            // Condición de validación: si el número actual es menor o igual al anterior,
            // la secuencia ya no es ascendente.
            if (numeroActual <= numeroAnterior) {
                esSecuenciaAscendente = false; // Se cambia la bandera
                // No es necesario seguir leyendo si ya encontramos una falla
                // break; // Descomentar para optimizar: salir del bucle si ya no es ascendente
            }

            // Se actualiza el número anterior para la siguiente iteración.
            numeroAnterior = numeroActual;
        }
    }

    // --- SALIDA ---
    std::cout << "\n--- Resultado del Analisis de Secuencia ---\n";
    if (esSecuenciaAscendente) {
        std::cout << "La secuencia de numeros ingresada ES estrictamente ascendente.\n";
    } else {
        std::cout << "La secuencia de numeros ingresada NO es estrictamente ascendente.\n";
    }
}

// --- Implementación de Ejercicio 4: Calculadora de Descuentos por Volumen ---
void ejecutarEjercicio4() {
    std::cout << "\n--- EJERCICIO 4: Calculadora de Descuentos por Volumen ---\n";
    std::cout << "Enunciado: Calcula el total a pagar aplicando descuentos por cantidad de unidades.\n";

    // --- VARIABLES ---
    double precioUnitario = 0.0;
    int cantidadUnidades = 0;
    double subtotal = 0.0;
    double porcentajeDescuento = 0.0;
    double montoDescuento = 0.0;
    double totalAPagar = 0.0;

    // --- ENTRADA ---
    std::cout << "Ingrese el precio unitario del producto: ";
    std::cin >> precioUnitario;

    std::cout << "Ingrese la cantidad de unidades a comprar: ";
    std::cin >> cantidadUnidades;

    // --- PROCESO ---
    // 1. Calcular el subtotal sin descuentos.
    subtotal = precioUnitario * cantidadUnidades;

    // 2. Determinar el porcentaje de descuento usando una estructura if-else if-else.
    // Se evalúan las condiciones de mayor a menor para que sean excluyentes y correctas.
    if (cantidadUnidades > 50) {
        porcentajeDescuento = 0.15; // 15%
    } else if (cantidadUnidades >= 21) {
        porcentajeDescuento = 0.10; // 10%
    } else if (cantidadUnidades >= 11) {
        porcentajeDescuento = 0.05; // 5%
    } else { // 1 a 10 unidades
        porcentajeDescuento = 0.0; // 0%
    }

    // 3. Calcular el monto final del descuento y el total a pagar.
    montoDescuento = subtotal * porcentajeDescuento;
    totalAPagar = subtotal - montoDescuento;

    // --- SALIDA ---
    std::cout << "\n--- Factura de Compra ---\n";
    std::cout.precision(2); // Establecer precisión a 2 decimales para la salida de dinero
    std::cout << std::fixed; // Usar notación de punto fijo

    std::cout << "Subtotal (" << cantidadUnidades << " unidades x $" << precioUnitario << "): $" << subtotal << std::endl;
    std::cout << "Descuento aplicado (" << porcentajeDescuento * 100 << "%): -$" << montoDescuento << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "TOTAL A PAGAR: $" << totalAPagar << std::endl;
}

// --- Implementación de Ejercicio 5: Buscador del Primer Carácter Único ---
void ejecutarEjercicio5() {
    std::cout << "\n--- EJERCICIO 5: Buscador del Primer Caracter Unico ---\n";
    std::cout << "Enunciado: Encuentra el primer caracter que no se repite en una palabra (minusculas).\n";

    // --- VARIABLES ---
    std::string palabra;
    bool encontradoPrimerUnico = false;
    char primerCaracterUnico = ' '; // Inicializado con un valor dummy

    // --- ENTRADA ---
    std::cout << "Ingrese una palabra (en minusculas): ";
    // Usamos getline para leer la línea completa, en caso de que quieran ingresar espacios (aunque el enunciado dice "palabra")
    std::getline(std::cin, palabra);

    // --- PROCESO ---
    int longitud = palabra.length();

    // Si la palabra está vacía o tiene un solo carácter, ese es el único.
    if (longitud == 0) {
        std::cout << "La palabra esta vacia. No hay caracteres que analizar.\n";
        return;
    }
    if (longitud == 1) {
        primerCaracterUnico = palabra[0];
        encontradoPrimerUnico = true;
    } else {
        // Bucle externo: recorre la palabra para seleccionar un "carácter candidato".
        for (int i = 0; i < longitud; ++i) {
            char caracterCandidato = palabra[i];
            int contadorOcurrencias = 0;

            // Bucle interno: recorre toda la palabra de nuevo para contar cuántas
            // veces aparece el 'carácter candidato'.
            for (int j = 0; j < longitud; ++j) {
                if (caracterCandidato == palabra[j]) {
                    contadorOcurrencias++;
                }
            }

            // Si después de contar, el contador es 1, significa que el carácter es único.
            if (contadorOcurrencias == 1) {
                primerCaracterUnico = caracterCandidato;
                encontradoPrimerUnico = true; // Activamos la bandera
                break; // Se encontró el primer único, no es necesario seguir buscando
            }
        }
    }

    // --- SALIDA ---
    std::cout << "\n--- Resultado del Analisis de Caracteres ---\n";
    if (encontradoPrimerUnico) {
        std::cout << "El primer caracter unico en '" << palabra << "' es: '" << primerCaracterUnico << "'\n";
    } else {
        std::cout << "En la palabra '" << palabra << "', todos los caracteres se repiten o no hay caracteres.\n";
    }
}

// --- Implementación de Ejercicio 6: Generador de Serie Fibonacci ---
void ejecutarEjercicio6() {
    std::cout << "\n--- EJERCICIO 6: Generador de Serie Fibonacci ---\n";
    std::cout << "Enunciado: Genera los primeros N numeros de la secuencia de Fibonacci.\n";

    // --- VARIABLES ---
    int n = 0;

    // Variables para almacenar los términos de Fibonacci: 'a' y 'b' son los dos anteriores, 'c' es el actual.
    int numAnterior = 0;
    int numSiguiente = 1;
    int nuevoValor = 0;

    // --- ENTRADA ---
    std::cout << "Ingrese la cantidad de numeros de la serie de Fibonacci a generar: ";
    std::cin >> n;

    // --- PROCESO Y SALIDA ---
    std::cout << "\n--- Los primeros " << n << " numeros de Fibonacci son: ---\n";

    // Se manejan los casos base (cuando n es 0, 1 o 2).
    if (n <= 0) {
        std::cout << "La cantidad debe ser un numero positivo.\n";
    } else if (n == 1) {
        std::cout << numAnterior << std::endl; // Solo el primer termino (0)
    } else { // n >= 2
        std::cout << numAnterior << " " << numSiguiente; // Imprime los dos primeros términos (0 y 1)

        // El bucle comienza en 3 porque ya hemos impreso los 2 primeros términos.
        for (int i = 3; i <= n; ++i) {
            nuevoValor = numAnterior + numSiguiente; // El siguiente término es la suma de los dos anteriores.
            std::cout << " " << nuevoValor; // Se imprime el nuevo término.

            // Se actualizan las variables para la siguiente iteración.
            // El que era 'b' ahora es 'a', y el nuevo término 'c' ahora es 'b'.
            numAnterior = numSiguiente;
            numSiguiente = nuevoValor;
        }
        std::cout << std::endl; // Salto de línea al final para un formato limpio.
    }
}

void fibonacci() {
    int numeroFibonacci = 0;
    int primerNumeroFibonacci = 0;
    int segundoNumeroFibonacci = 1;
    int acumuladorVueltas = 0;
    std::cout << "Ingrese un numero entero positivo: " << std::endl;
    std::cin >> numeroFibonacci;
    if (numeroFibonacci <= 0) {
        std::cerr << "Ingrese un número válido.";
        std::cin >> numeroFibonacci;
    }
    std::cout << "0\n";
    std::cout << "1\n";
    while (acumuladorVueltas < (numeroFibonacci - 2)) {
        int siguienteNumeroFibonacci = primerNumeroFibonacci + segundoNumeroFibonacci;
        std::cout << siguienteNumeroFibonacci << std::endl;
        primerNumeroFibonacci = segundoNumeroFibonacci;
        segundoNumeroFibonacci = siguienteNumeroFibonacci;
        acumuladorVueltas++;
    }
}
