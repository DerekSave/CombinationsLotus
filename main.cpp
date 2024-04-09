#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir una combinación
void printCombination(const vector<int>& combination) {
    for (int i = 0; i < combination.size(); ++i) {
        cout << combination[i] << " ";
    }
    cout << endl;
}

// Función para generar todas las combinaciones de k elementos de un conjunto de n elementos
void generateCombinations(int k, int n) {
    vector<int> combination(k, 0);

    while (true) {
        // Imprimir la combinación actual
        printCombination(combination);

        // Encontrar el siguiente índice para cambiar
        int i = k - 1;
        while (i >= 0 && combination[i] == n - k + i) {
            i--;
        }

        // Si no hay más combinaciones, terminar el bucle
        if (i < 0) {
            break;
        }

        // Incrementar el índice encontrado
        combination[i]++;

        // Actualizar los índices siguientes
        for (int j = i + 1; j < k; ++j) {
            combination[j] = combination[j - 1] + 1;
        }
    }
}

int main() {
    const int n = 50; // Total de elementos en el conjunto
    const int k = 6;  // Número de elementos en cada combinación

    vector<int> combination;
    generateCombinations(k, n);

    return 0;
}
