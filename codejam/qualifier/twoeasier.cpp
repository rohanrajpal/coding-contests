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

signed main(){
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int cnt=0;
    tc(){
        string inp,ans="";cin>>inp;
        inp += "0";
        inp.insert(0,"0");
        // cout<<inp<<"\n";
        for(int i=0;i<inp.size()-1;i++){
            ans += inp[i];
            // ans.insert(i,1,inp[i]);
            // cout<<ans<<"\n";
            int cur = inp[i]- '0',next = inp[i+1] - '0';
            // cout<<cur<<" "<<next<<"\n";
            if(cur<next){
                ans.insert(ans.size(),next-cur,'(');
                // for(int i=0;i<abs(next-cur);i++){
                //     ans += "(";
                // }
            }
            else if(cur > next){
                ans.insert(ans.size(),cur-next,')');
                // for(int i=0;i<abs(next-cur);i++){
                //     ans+= ")";
                // }
            }
            
        }
        ans = ans.substr(1,ans.size()-1);
        cout<<"Case #"<<++cnt<<": "<<ans<<"\n";
    }
}