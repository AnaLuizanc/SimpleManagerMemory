#include <iostream>
#include <vector>

using namespace std;

class SimpleMemoryManager {
    public:
        vector<int> memory;

        SimpleMemoryManager(int tamanho){
            memory.assign(tamanho, 0);
        }

        


};

int main(){
    SimpleMemoryManager mem(10);

    


    return 0;
}