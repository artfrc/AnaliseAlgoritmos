#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
int numberItens;
vector<vector<int>> memo; 

int knapsack(int currentItem, vector<int>& weightsItens, vector<int>& valueItens, int capacity);

int main() { _
    while(cin >> numberItens) {
        memo.clear();
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

        vector<int> v(capacity,-1);
        
        // Criando a matriz de memorização
        for(int i = 0; i < numberItens; ++i) {
            memo.push_back(v);
        }

        // Comeca calcular o tempo de execucao aqui
        auto begin = chrono::high_resolution_clock::now();
        int ans = knapsack(0,weightsItens,valueItens,capacity);
        // Termina de calcular o tempo de execucao aqui
        auto end = chrono::high_resolution_clock::now() - begin;
        double seconds = chrono::duration_cast<chrono::milliseconds>(end).count();
        cout << "Valor maximo: " << ans << endl;
        cout << fixed << setprecision(4) << "Tempo de execucao: " << seconds/1000. << " segundos" << endl;
    }
}

int knapsack(int currentItem, vector<int>& weightsItens, vector<int>& valueItens, int capacity) {
    // Estourou o limite da mochila
    if(capacity < 0) {
        return -INF; // Esse valor será tao pequeno que não retornará ele
    }
    // Passei por todos os items da mochila
    if(currentItem >= numberItens or capacity == 0) {
        return 0;
    }
    // Verifico se já calculei, se sim, então não preciso calcular novamente
    int& pdm = memo[currentItem][capacity-1];
    if(pdm != -1) return pdm;

    // Vou pegar a opcao em que me dê o maior valor
    return pdm = max(
        // Opcao de pegar o item
        knapsack(currentItem+1,weightsItens,valueItens,capacity-weightsItens[currentItem])+valueItens[currentItem],
        //Opcao de NAO pegar o item
        knapsack(currentItem+1,weightsItens,valueItens,capacity)
    );
}