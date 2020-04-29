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
// #define int long long
 
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
        int A,B,cnt=0;cin>>A>>B;

        for(int a=1;a<=A;a++){
            for(int b=1;b<=B;b++){
                string s1 = to_string(a); 
                string s2 = to_string(b);
                string s = s1 + s2; 
                int conc = stoi(s);
                // cout<<"a:"<<a<<" b:"<<b<<" conc:"<<conc<<"\n";
                // cout<<"counting\n";
                if(a*b+a+b == conc){
                    cout<<"a:"<<a<<" b:"<<b<<" conc:"<<conc<<"\n";
                    cnt++;
                }
            }
        }

        cout<<"cnt: "<<cnt<<"\n";
    }
}