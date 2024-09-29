#include <iostream>
#include <deque>

int main(){
    std::deque<int> d1(10);
    for(int i = 0; i < 10; i++){
        d1[i] = i*i;
    }

    for(auto i : d1){
        std::cout << i << " "; 
    }

}