#include <iostream>

using namespace std;

// Función para imprimir una combinación
void printCombination(int combination[], int k) {
    for (int i = 0; i < k; ++i) {
        cout << combination[i] << " ";
    }
    cout << endl;
}

// Función para generar todas las combinaciones de k elementos de un conjunto de n elementos
void generateCombinations(int n, int k) {
    // Inicializar la primera combinación (0, 1, 2, ..., k - 1)
    int combination[k];
    for (int i = 0; i < k; ++i) {
        combination[i] = i;
    }

    // Imprimir la primera combinación
    printCombination(combination, k);

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
    }
}

int main() {
    const int n = 50; // Total de elementos en el conjunto
    const int k = 6;  // Número de elementos en cada combinación

    generateCombinations(n, k);

    return 0;
}
