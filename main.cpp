#include <iostream>
#include <vector>

using namespace std;

class SimpleMemoryManager {
    public:
        vector<int> memory;

        SimpleMemoryManager(int tamanho){
            memory.assign(tamanho, 0);
        }

        int alloc(int n){
            int largestSequence0 = 0;
            int indice = 0;
            for(int i=0; i<memory.size(); i++){
                if(memory[i] == 0){
                    ++largestSequence0;
                    if(largestSequence0 == n)
                        break;
                }
                else{
                    largestSequence0 = 0;
                    indice = i;
                }
            }
            if(n <= largestSequence0){
                if(indice != 0)
                    indice++;
                for(int i = indice; i < n+indice; i++)
                    memory[i] = 1;
                return indice;
            }else
                return -1;
        }

        void free(int start, int n){
            cout << "Liberando " << n << " bytes iniciando do indice " << start << "..." << endl;
            for(int i = start; i < n+start; i++)
                memory[i] = 0;
        }

        void show_memory(){
            cout << "Memoria: ";
            for(int i=0; i<memory.size(); i++)
                cout << memory[i]; 
            cout << endl;
        }
};

void showMessageAlloc(int indice, int bytes){
    cout << "Tentando alocar " << bytes << " bytes..." << endl;
    if(indice != -1)
        cout << "Alocacao bem sucedida, iniciando no indice " << indice << endl;
    else
        cout << "Falha na alocacao" << endl;
}

int main(){
    SimpleMemoryManager mem(20);
    int bytes;

    mem.show_memory();

    bytes = 5;
    int indice = mem.alloc(bytes);
    showMessageAlloc(indice, bytes);
    mem.show_memory();

    bytes = 8;
    indice = mem.alloc(bytes);
    showMessageAlloc(indice, bytes);
    mem.show_memory();

    bytes = 5;
    indice = 0;
    mem.free(indice, bytes);
    mem.show_memory();

    bytes = 5;
    indice = mem.alloc(bytes);
    showMessageAlloc(indice, bytes);
    mem.show_memory();

    return 0;
}