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
vii fact(101);
int nchooser(int n,int r){
	return (n * (n-1) ) /2 ;
}

signed main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif


    int n;
    cin>>n;
    string inp;
    vii inparr(26,0), leftroom(26,0),rightroom(26,0);
    // cout<<"check "<<n<<"\n";
    // cout<<nchooser(50,2)<<"\n";

    for (int i = 0; i < n; ++i)
    {
    	cin>>inp;

    	int cur = inp[0] - 'a';
		// cout<<cur<<" "<<inp<<"\n";

		inparr[cur]++;

    	if (leftroom[cur] <= rightroom[cur])
    	{
    		leftroom[cur]++;
    	}
    	else{
    		rightroom[cur]++;
    	}
    }

    int sum=0;
    for(int i =0;i<26;i++){
    	if (leftroom[i] > 1)
    	{
    		sum += nchooser(leftroom[i],2);	
    	}
    	if (rightroom[i] > 1)
    	{
    		sum += nchooser(rightroom[i],2);	
    	}
    }

    cout<<sum;


}