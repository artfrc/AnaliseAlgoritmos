#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
int numberItens;

int knapsack(int currentItem, vector<int>& weightsItens, vector<int>& valueItens, int capacity);

int main() { _
    int count = 0;
    while(cin >> numberItens and ++count) {
        cout << "[TESTE " << count << "]" << endl;
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

        // Comeca calcular o tempo de execucao aqui
        auto begin = chrono::high_resolution_clock::now();
        int ans;
        for(int i = 0; i < 3; i++) {
            ans = knapsack(0,weightsItens,valueItens,capacity);
        }
        // Termina de calcular o tempo de execucao aqui
        auto end = chrono::high_resolution_clock::now() - begin;
        double seconds = chrono::duration_cast<chrono::milliseconds>(end).count();
        seconds /= 3;
        cout << "Valor maximo: " << ans << endl;
        cout << fixed << setprecision(4) << "Tempo de execucao: " << seconds/1000. << " segundos" << endl << endl;
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
    // Vou pegar a opcao em que me dê o maior valor
    return max(
        // Opcao de pegar o item
        knapsack(currentItem+1,weightsItens,valueItens,capacity-weightsItens[currentItem])+valueItens[currentItem],
        //Opcao de NAO pegar o item
        knapsack(currentItem+1,weightsItens,valueItens,capacity)
    );
}