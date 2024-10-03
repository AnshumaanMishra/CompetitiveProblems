#include <iostream>
#include <queue>


// Writing our own Comparison metric for the priority Queue
class Compare{
    private:
        
    public:
        bool operator()(int a, int b){
            return a > b * b;
        }
};


int main(){
    int arr[6] = {10, 8, 19, 5, 92, 34};
    int size = sizeof(arr)/sizeof(int);

    std::priority_queue<int> maxHeap; // MaxHeap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // MinHeap
    std::priority_queue<int, std::vector<int>, Compare> customHeap; // MinHeap

    for(int x : arr){
        maxHeap.push(x);
        minHeap.push(x);
        customHeap.push(x*x);
    }

    while(!maxHeap.empty()){
        std::cout << maxHeap.top() << ", ";
        maxHeap.pop();
    }
    std::cout << std::endl;
    
    while(!minHeap.empty()){
        std::cout << minHeap.top() << ", ";
        minHeap.pop();
    }
    std::cout << std::endl;

    while(!customHeap.empty()){
        std::cout << customHeap.top() << ", ";
        customHeap.pop();
    }
}