#include <stdio.h>
#include <chrono>
using namespace std::chrono;

// Función para imprimir una combinación
void printCombination(int num1, int num2, int num3, int num4, int num5, int num6) {
    printf("%d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6);
}

// Función para generar todas las combinaciones de 6 elementos de un conjunto de 50 elementos ss
void generateCombinations() {
    for (int num1 = 1; num1 <= 44; ++num1) {
        for (int num2 = num1 + 1; num2 <= 45; ++num2) {
            for (int num3 = num2 + 1; num3 <= 46; ++num3) {
                for (int num4 = num3 + 1; num4 <= 47; ++num4) {
                    for (int num5 = num4 + 1; num5 <= 48; ++num5) {
                        for (int num6 = num5 + 1; num6 <= 49; ++num6) {
                            printCombination(num1, num2, num3, num4, num5, num6);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    auto start = high_resolution_clock::now();
    
    generateCombinations();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    printf("Tiempo de ejecución: %ld segundos\n", duration.count());

    return 0;
}
