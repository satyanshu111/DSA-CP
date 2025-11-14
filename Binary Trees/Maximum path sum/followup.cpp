//given a tree you have to find max path value

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
const ll INF = 1e18 + 7;
int ans;

int dfs(int u, int p, vector<int>adj[], vector<int>&val){
    int best1 = 0, best2 = 0;
    for(int v: adj[u]){
        if(v != p){
            int temp = dfs(v, u, adj, val);
            if(temp > best1){
                best2 = best1;
                best1 = temp;
            }
            else if(temp > best2){
                best2 = temp;
            }
        }
    }

    ans = max(ans, best1 + best2 + val[u]);
    return val[u] + max(best1, best2);
}

void solve()
{
    int n;
    cin>>n;
    
    ans = INT_MIN;

    vector<int>val(n);
    for(int i=0;i<n;i++)cin>>val[i];

    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x = dfs(0, -1, adj, val);
    cout<<ans<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}