#include <stdio.h>
#include <chrono>
using namespace std::chrono;

int cantidad = 0;

// Función para imprimir una combinación
void printCombination(int combination[], int k) {
    for (int i = 0; i < k; ++i) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

// Función para generar todas las combinaciones de 6 elementos de un conjunto de números del 0 al 49
void generateCombinations() {
    const int n = 40; // Total de elementos en el conjunto
    const int k = 6;  // Número de elementos en cada combinación

    // Inicializar la primera combinación (0, 1, 2, 3, 4, 5)
    int combination[k];
    for (int i = 0; i < k; ++i) {
        combination[i] = i + 1;
    }

    // Imprimir la primera combinación
    printCombination(combination, k);
    cantidad++;

    // Generar las combinaciones restantes
    while (true) {
        int i = k - 1;
        while (i >= 0 && combination[i] == n - k + i) {
            i--;
        }
        if (i < 0) {
            break;
        }
        combination[i]++;
        for (int j = i + 1; j < k; ++j) {
            combination[j] = combination[j - 1] + 1;
        }
        printCombination(combination, k);
        cantidad++;
    }
}

int main() {
    auto start = high_resolution_clock::now();
    
    generateCombinations();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    printf("Duracion: %ld segundos\nCantidad de permutaciones: %d\n", duration.count(), cantidad);

    return 0;
}
