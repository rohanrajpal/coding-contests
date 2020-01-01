//http://codeforces.com/contest/1278/problem/A
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
// test cases
/*
abacaba
zyxaabcaabkjh
*/
signed main(){
	// #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
	// #endif
    

    int t;cin>>t;

    while(t--){
    	string str,hash;
    	cin>>str>>hash;
    	// cout<<str<<"\n";
    	int wsize = str.size(),sum=0;
    	vii mainarr(26,0);
    	for(int i=0;i<wsize;i++){
    		mainarr[str[i] - 'a']++;
    		// cout<<mainarr[str[i] - 'a'];
    	}

    	int flag=0;
    	/*
    	a b a c a b a
    	0 1 2 3 4 5 6
    	*/
    	// sum = accumulate(mainarr.begin(), mainarr.end(), sum);

		// cout<<"mainsum: "<<sum<<"\n";
    	for(int i=0;i+wsize-1<hash.size();i++){
    		vii arr;
    		arr = mainarr;
    		flag = 0;
    		for(int j=i;j<i+wsize;j++){
    			if (arr[hash[j] - 'a'])
    			{
    				arr[hash[j] - 'a']--;
    				// cout<<arr[hash[j] - 'a']<<" ";
    			}
    			else{
    				flag = -1;
    				break;
    			}
    		}
    		
    		sum = accumulate(arr.begin(), arr.end(), 0);
    		// cout<<""<<sum<<"\n";
    		if (sum == 0 && flag != -1)
    		{
    			flag=1;
    			cout<<"YES\n";
    			break;
    		}
    	}

    	if (flag <= 0)
    	{
    		cout<<"NO\n";
    	}
	
    }
    return 0;
}