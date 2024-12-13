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
                for(int i = indice; i < n+indice; i++){
                    memory[i] = 1;
                }
                return indice;
            }else
                return -1;
        }


};

int main(){
    SimpleMemoryManager mem(10);

    for(int i=0; i<mem.memory.size(); i++)
        cout << mem.memory[i]; 

    int indice = mem.alloc(3);
    cout << endl << "Alocacao bem sucedida, iniciando no indice " << indice << endl;
    for(int i=0; i<mem.memory.size(); i++)
        cout << mem.memory[i]; 

    indice = mem.alloc(4);
    cout << endl << "Alocacao bem sucedida, iniciando no indice " << indice << endl;
    for(int i=0; i<mem.memory.size(); i++)
        cout << mem.memory[i]; 


    return 0;
}