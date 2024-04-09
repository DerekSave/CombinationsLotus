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
void generateCombinations(vector<int>& combination, int start, int k, int n) {
    if (k == 0) {
        printCombination(combination);
        return;
    }

    for (int i = start; i <= n - k; ++i) {
        combination.push_back(i);
        generateCombinations(combination, i + 1, k - 1, n);
        combination.pop_back();
    }
}

int main() {
    const int n = 50; // Total de elementos en el conjunto
    const int k = 6;  // Número de elementos en cada combinación

    vector<int> combination;
    generateCombinations(combination, 0, k, n);

    return 0;
}
