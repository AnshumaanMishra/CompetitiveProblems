#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dfs(int u, int parent, vector<pair<int, int>> adj[], ll &ans, int N){
    int currentTreeSize = 1;
    for(auto p : adj[u]){
        int v = p.first;
        int wt = p.second;
        if(v==parent){
            continue;
        }
        int childTreeSize = dfs(v, u, adj, ans, N);
        int edgeCont = 2 * min(childTreeSize, N - childTreeSize) * wt;
        ans += edgeCont;

        //update tree size
        currentTreeSize+= childTreeSize;
    }
    return currentTreeSize;
}

int main(){
    int test;
    cin >> test;
    int n, u, v, w;

    //Graph
    vector<pair<int, int>> adj[100005];
    while(test > 0){
        cin >> n;
        // Reset adjacency list
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }

        for(int i = 1; i <= n - 1; i++){
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }


        //DFS
        ll ans = 0;
        dfs(1, -1, adj, ans, n);
        cout << ans << endl;
        test--;
    }
    
}