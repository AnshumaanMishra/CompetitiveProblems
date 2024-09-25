#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    auto start_time = clock();
    auto end_time = clock();

    printf("%d", end_time - start_time);
    return 0;
}