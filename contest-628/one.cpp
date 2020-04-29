//https://codeforces.com/contest/1325/problem/A
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
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

signed main(){
    int t;cin>>t;
    while(t--){
        int x,a,b;cin>>x;

        if(x%2 == 0){
            a = x/2;b=x/2;
        }
        else{
            a = 1; b = x-1;
            // int found = 0;
            // for1(i,x+1){
            //     for1(j,x+1){
            //         int g = gcd(i,j),l = (i*j) / g;
            //         if(g + l == x){
            //             a = i; b = j;
            //             found=1;
            //             break;
            //         }
            //     }
            //     if(found) break;
            // }
        }

        cout<<a<<" "<<b<<"\n";
    }
}