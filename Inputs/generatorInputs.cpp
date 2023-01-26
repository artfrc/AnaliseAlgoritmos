#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define MAX_VALUE 600
#define MAX_WEIGHT 70

using namespace std;

int numberItens, weight, value, capacity;

int main() {
    cout << "Numero de itens para gerar: ";
    cin >> numberItens;
    cout << "Capacidade da mochila: ";
    cin >> capacity;
    fstream file;
    file.open("efficiencyInputTest.in", ios::out);
    if(file.is_open()) {
        unsigned seed = time(0);
        srand(seed);
        file << numberItens << endl;
        for(int i = 0; i < numberItens; ++i) {
            file << 1+rand()%MAX_WEIGHT << " " << 1+rand()%MAX_VALUE << endl;
        }
        file << capacity;
        file.close();
    } else {
        cout << "Falha" << endl;
        exit(1);
    }
}