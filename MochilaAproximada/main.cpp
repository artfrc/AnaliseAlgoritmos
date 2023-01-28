#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <map>
#include <algorithm>

#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int numberItens;
multimap<double,int> mm;

int knapsack(vector<int>& weightsItens, vector<int>& valueItens, int capacity);

int main() { _
    int count = 0;
    while(cin >> numberItens and ++count) {
        cout << "[TESTE " << count << "]" << endl;
        mm.clear();
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

        // Multimap é um map ordenado pela chave
        for(int i = 0; i < numberItens; i++) {
            mm.insert(make_pair((double)valueItens[i]/(double)weightsItens[i],i));
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
        cout << fixed << setprecision(4) << "Tempo de execucao: " << seconds/1000. << " segundos" << endl << endl;
    }
}

int knapsack(vector<int>& weightsItens, vector<int>& valueItens, int capacity) {
    int ans = 0;
    int rest = capacity;
    for(auto it = mm.rbegin(); it != mm.rend() and rest > 0; it++) {
        if(rest >= weightsItens[it->second]) {
            ans += valueItens[it->second];
            rest -= weightsItens[it->second];
        }
    }
    return ans;
}