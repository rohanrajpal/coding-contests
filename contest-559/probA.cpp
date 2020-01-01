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
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int n,minuscnt=0,pluscnt=0;
    cin>>n;
	
	string inps;
	cin>>inps;
	char cur;
	
	int curval,minval=n,flag=1;

	for (int i = 0; i <= n; ++i)
	{
		curval = i;
		flag=1;
		for (int j = 0; j < n; ++j)
		{
			if (curval == 0 && inps[j] == '-')
			{
				flag =0;
				break;
			}
			else if(inps[j] == '-'){
				curval -= 1;
			}
			else{
				curval +=1;
			}
		}
		// cout<<"curval is: "<<curval<<"\n";
		// cout<<"minval is: "<<minval<<"\n";
		if (flag == 1)
		{
			if (curval<minval)
			{
				minval=curval;
			}
		}
	}

	cout<<minval<<"\n";

}