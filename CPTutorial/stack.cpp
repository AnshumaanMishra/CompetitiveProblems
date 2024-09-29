#include <iostream>
#include <stack>

int main(){
    std::stack<int> st;
    for(int i = 0; i < 10; i++){
        st.push(i*i*i);
    }
    
    for(int i = 0; i < 10; i++){
        std::cout << st.top() << ", ";
        st.pop();
    }
}