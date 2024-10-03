#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;

int find(vector<ll>& arr, ll value){
    for(int i = 0; i < arr.size() - 1; i++){
        if(value >= arr[i] && value <= arr[i+1]){
            return i;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, q;
        cin >> n;
        cin >> q;
        vector<ll> points(n, 0);
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            points[i] = input;
            
        }
        int width = points[n-1] - points[0];
        vector<ll> map(width, 0);

        ll key = points[0];
        for(ll j = 0; j < width; j++){
            ll left = find(points, j + key) + 1;
            ll right = n - left;// - !((points[left - 1] == j + key) || (points[left] == j + key));
            // cout << left << " " << right << " " << j + key << endl;
            map[j] = left * right;
        }

        for(int j = 0; j < q; j++){
            int qu;
            cin >> qu;
            int count = 0;
            for(int k = 0; k < width; k++){
                if(map[k] == qu){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}