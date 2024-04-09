#include <stdio.h>
#include <chrono>
using namespace std::chrono;

// Función para imprimir una combinación
void printCombination(short num1, short num2, short num3, short num4, short num5, short num6) {
    printf("%d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6);
}

// Función para generar todas las combinaciones de 6 elementos de un conjunto de 50 elementos ss
void generateCombinations() {
    for (short num1 = 1; num1 <= 44; ++num1) {
        for (short num2 = num1 + 1; num2 <= 45; ++num2) {
            for (short num3 = num2 + 1; num3 <= 46; ++num3) {
                for (short num4 = num3 + 1; num4 <= 47; ++num4) {
                    for (short num5 = num4 + 1; num5 <= 48; ++num5) {
                        for (short num6 = num5 + 1; num6 <= 49; ++num6) {
                            printCombination(num1, num2, num3, num4, num5, num6);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int k = 49;
    int n = 6;

    auto start = high_resolution_clock::now();
    generateCombinations();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    printf("Tiempo de ejecución: %ld segundos\n", duration.count());

    return 0;
}