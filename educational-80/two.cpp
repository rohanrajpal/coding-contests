//http://codeforces.com/contest/1288/problem/1
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
 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int A,B;cin>>A>>B;

        int ma = A, mb = (int)log10(B),all9=1;
        // cout<<mb<<":mb\n";
        while(B){
            // cout<<B%10<<"\n";
            if((B%10) != 9) {all9=0; break;}
            B /= 10;
        }
        // cout<<"all:"<<all9<<"\n";
        if(all9) mb += 1;
        cout<<ma*mb<<"\n";
    }
}