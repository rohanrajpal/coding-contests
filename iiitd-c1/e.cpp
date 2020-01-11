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

int primecheck(int num){
    for(int i=2;i<=num/2;i++){
        if(num % i == 0) return -1;
    }
    return 1;
}

signed main(){
    // make primes from 1 to 10e5 :sieve
    // prime check in O-1 :done
    // good prime prefix for whole 1 to 10e5 :done
    // do queries in O-1 : done
    int q,maxnum=0;
    cin>>q;
    vector<pair<int,int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int li,ri;cin>>li>>ri;
        queries[i] = mp(li,ri);
        if(ri>maxnum) maxnum = ri;
    }
    
    // cout<<"maxnum: "<<maxnum<<"\n";
    
    int n=maxnum+1,cntprime=0;
    vector<int> prime(n,0);
    vector<int> prefix(n,0);
    
    prime[1] = -1;
    // cout<<"start primecheck \n";

    // 1 is prime
    // 0 not initialized
    // -1 not prime
    for(int i=2;i<100;i++){
        prime[i] = primecheck(i);
        // cout<<i<<" ";
        if(prime[i] == 1){
            int curmult = 2,curprod = curmult*i;
            while(curprod <= n){
                prime[curprod] = -1;
                curmult++;
                curprod = curmult*i;
            }
        }
    }
    // cout<<"end sieve\n";
    for(int i=2;i<n;i++){
        // cout<<i<<" "<<prime[i]<<"\n";
        if(prime[i]) continue;
        prime[i] = primecheck(i);
        // cout<<prime[i]<<" ";
    }
    // cout<<"end primecheck\n";
    //make prefix
    for(int i=1;i<n;i++){
        // prime[i] = primecheck(i);
        if(prime[i] == 1 and prime[(i+1)/2] == 1){
            cntprime++;
            // if(i <= 53)
            //     cout<<"gp: "<<i<<"\n";
        }
        prefix[i] = cntprime;
    }
    
    for(int i = 0; i < q; i++)
    {
        int li,ri;
        
        li = queries[i].first,ri = queries[i].second;
        // cout<<li<<" "<<ri<<"\n";
        // cout<<"li-1:"<<prefix[li-1]<<" ri:"<<prefix[ri]<<" ";
        cout<<prefix[ri] - prefix[li-1]<<"\n";
    }
    
}