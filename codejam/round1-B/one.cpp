#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vii vector<int>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define MOD 1000000007
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
// #define int long long
 
#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , 0 , sizeof(A) );
#define tc() int t; cin >> t ; while (t--)

using namespace std;

string ans;
int bound = 4;

pair<int,string> find_path(int i, int j,int& x,int& y,int steps,string path,map<pair<int,int>,pair<int,string>>& dp){
    if(!(i>=-bound and j>=-bound and i<=bound and j<=bound)) return mp(-1,"IMPOSSIBLE");
    if(i == x and j==y) return mp(steps,path);
    if(dp[{i,j}].first != -1) {
        pair<int,string> memo = dp[{i,j}];
        // cout<<memo.first<<" "<<memo.second<<"\n";
        return dp[{i,j}];
    }

    vector<vector<string>> directions = {{"-1","0","W"},{"0","-1","S"},{"0","1","N"},{"1","0","E"}};
    pair<int,string> min_steps=mp(-1,"IMPOSSIBLE");
    for(auto d: directions){
        pair<int,string> num_steps = find_path(i+stoi(d[0])*pow(2,steps),j+stoi(d[1])*pow(2,steps),x,y,steps+1,path+d[2],dp);
        // cout<<num_steps.first<<"\n";
        if(num_steps.first!=-1 and (num_steps.first < min_steps.first or min_steps.first==-1)){
            min_steps = num_steps;
        }
    }
    
    return dp[{i,j}] = min_steps;
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int cnt=1;
    tc(){
        int x,y;cin>>x>>y;ans="";
        map<pair<int,int>,pair<int,string>> dp;
        pair<int,string> ans = find_path(0,0,x,y,0,"",dp);
        
        cout<<"Case #"<<cnt++<<": "<<ans.second<<"\n";
    }
}