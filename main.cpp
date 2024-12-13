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
                if(memory[i] == 0)
                    ++largestSequence0;
                else{
                    largestSequence0 = 0;
                    indice = i;
                }
            }
            if(n < largestSequence0){
                if(indice != 0)
                    indice++;
                for(int i = indice; i < n+indice; i++)
                    memory[i] = 1;
                return indice;
            }else
                return -1;
        }

        void free(int start, int n){
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

void showMessage(int indice){
    if(indice != -1)
        cout << "Alocacao bem sucedida, iniciando no indice " << indice << endl;
    else
        cout << "Falha na alocacao" << endl;
}

int main(){
    SimpleMemoryManager mem(10);

    mem.show_memory();

    int indice = mem.alloc(3);
    showMessage(indice);
    mem.show_memory();

    indice = mem.alloc(4);
    showMessage(indice);
    mem.show_memory();

    mem.free(3,3);
    cout << endl << "Liberando 3 bytes iniciando do indice 3" << endl;
    mem.show_memory();

    return 0;
}