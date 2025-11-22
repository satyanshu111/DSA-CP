#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
const ll INF = 1e18 + 7;

void solve()
{
     ll m, x;
     cin>>m>>x;

     vector<pair<ll,ll>>a(m+1);
     ll MAX_H=0;
     for(int i=1;i<=m;i++){
          cin>>a[i].first>>a[i].second;
          MAX_H+=a[i].second;
     }

     //dp[i][j]=min money required to buy j happiness until i month
     vector<vector<ll>>dp(m+1, vector<ll>(MAX_H+1,INF));
     vector<ll>cur(MAX_H+1,INF);
     vector<ll>prev(MAX_H+1,INF);
     prev[0]=0;

     for(int i=1;i<=m;i++){
          for(int j=0;j<=MAX_H;j++){
               //not take
               cur[j]=prev[j];

               //take
               ll cur_cost = a[i].first;
               ll total_money = (i-1)*x;
               if(j-a[i].second>=0 && prev[j-a[i].second]<INF/2 && prev[j-a[i].second]+cur_cost<=total_money&&prev[j-a[i].second] <= max(0ll,(i-2)*x)){
                    cur[j]=min(cur[j],prev[j-a[i].second]+cur_cost);
               }
          }
          prev=cur;
     }

     ll ans = 0;
     for(int i=1;i<=m;i++){
          for(ll j=0;j<=MAX_H;j++){
               if(prev[j] < INF/2){
                    ans = max(ans, j);
               }
          }
     }

     cout<<ans<<endl;
     return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}