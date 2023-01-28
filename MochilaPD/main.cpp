#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
int numberItens;
vector<vector<int>> matrix; 

int knapsack(vector<int>& weightsItens, vector<int>& valueItens, int capacity);

int main() { _
    while(cin >> numberItens) {
        matrix.clear();
        //cout << "Digite o numero de itens que vamos ter: ";
        vector<int> weightsItens;
        vector<int> valueItens;
        for(int i = 0; i < numberItens; ++i) {
            int weight, value;
            //cout << "Digite o peso e o valor do item " << i+1 << ": ";
            cin >> weight >> value;
            weightsItens.push_back(weight);
            valueItens.push_back(value);
        }
        int capacity;
        //cout << "Digite a capacidade da mochila: ";
        cin >> capacity;

        vector<int> v(capacity+1,0);
        
        // Criando a matriz de memorização
        for(int i = 0; i < numberItens; ++i) {
            matrix.push_back(v);
        }

        // Comeca calcular o tempo de execucao aqui
        int ans;
        auto begin = chrono::high_resolution_clock::now();
        for(int i = 0; i < 3; i++) {
            ans = knapsack(weightsItens,valueItens,capacity);
        }
        // Termina de calcular o tempo de execucao aqui
        auto end = chrono::high_resolution_clock::now() - begin;
        double seconds = chrono::duration_cast<chrono::milliseconds>(end).count();
        seconds /= 3;
        cout << "Valor maximo: " << ans << endl;
        cout << fixed << setprecision(4) << "Tempo de execucao: " << seconds/1000. << " segundos" << endl;
    }
}

int knapsack(vector<int>& weightsItens, vector<int>& valueItens, int capacity) {
    int ans = 0;

    // Primeira linha da matriz
    for(int j = 0; j < capacity+1; j++) {
        if(weightsItens[0] <= j) {
            matrix[0][j] = valueItens[0];
        }
    }

    // Segunda linha da matriz pra frente
    for(int i = 1; i < weightsItens.size(); i++) {
        for(int j = 0; j < capacity+1; j++) {
            int rest = j;
            int value = 0;
            if(weightsItens[i] <= j) {
                rest -= weightsItens[i];
                value += valueItens[i];

                if(rest > 0) value += matrix[i-1][rest];

                if(matrix[i-1][j] > value) matrix[i][j] = matrix[i-1][j];
                else matrix[i][j] = value;

                if(value > ans) ans = value;
            } else {
                if(matrix[i-1][j] > matrix[i][j]) matrix[i][j] = matrix[i-1][j];
                else matrix[i][j] = value;
            }
        }
    }
    return ans;
}