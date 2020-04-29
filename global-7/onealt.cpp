//https://codeforces.com/contest/1326/problem/A
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
bool checkdiv7(int n){
    if(n%3 == 1) n+=2;
    // else if(n%3 == 2) n+= 1;

    int toadd = ((n/3)-3)%2 == 0? 0: 222; 
    int num = 227 + toadd - 220;
    // cout<<"num is "<<num<<"\n";
    return num % 7;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1) {
            cout<<"-1\n";
            continue;
        }
        int numtwo = (n-1)*2,num;
        string lastnum = "";

        if(numtwo%3) lastnum = "3";
        else if(numtwo%9) lastnum =  "9";
        else if(checkdiv7(n)){
            //check div of 7
            lastnum = "7";
        }
        else{
            cout<<"-1\n";
            continue;
        }

        string numstr = "";
        while(n-1>0){
            numstr += "2";
            n--;
        }
        numstr += lastnum;
        cout<<numstr<<"\n";
    }
}