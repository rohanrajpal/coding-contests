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
#define int long long
 
#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , 0 , sizeof(A) );
#define tc() int t; cin >> t ; while (t--)

using namespace std;

bool canreachbefore(pll curpos, int undertime){
    int timetaken = abs(curpos.first)+abs(curpos.second);
    if(timetaken > undertime) return false;
    else return true;
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int cnt=1;
    tc(){
        int x,y;cin>>x>>y;
        string m;cin>>m;
        // vector<pll> timenpos(m.size());
        pair<int,int> curpos = mp(x,y);

        int timetaken=-1,time=1;
        for(auto d:m){
            if(d=='S'){
                curpos.second -= 1;
            }
            else if(d=='N'){
                curpos.second += 1;
            }
            else if(d=='W'){
                curpos.first -= 1;
            }
            else{
                curpos.first += 1;
            }
            // timenpos[time++] = curpos;
            if(canreachbefore(curpos,time++)){
                timetaken = time-1;
                break;
            }
        }
        string ans = timetaken == -1 ? "IMPOSSIBLE" : to_string(timetaken);
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
}