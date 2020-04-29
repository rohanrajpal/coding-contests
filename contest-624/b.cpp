//http://codeforces.com/contest/1311/problem/B
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
        int n,m;cin>>n>>m;
        vector<pair<int,int>> sortarr(n);
        vii arr(n),prr(m);

        for (int i = 0; i < n; i++){
            cin>>arr[i];
            sortarr[i] = mp(arr[i],i);
        }

        for (int i = 0; i < m; i++)
        {
            cin>>prr[i];
            prr[i] -= 1;
        }
        // cout<<"Received\n";
        
        sort(all(sortarr));
        sort(all(prr));
        
        int flag = 1;

        for(int i=0;i<n;i++){
            int elem = arr[i];
            //find the elem's sorted pos
            auto elem_pos = find(sortarr.begin(),sortarr.end(),mp(elem,i));
            int sorted_pos = elem_pos - sortarr.begin();
            // cout<<"Sorted pos: "<<sorted_pos<<"\n";
            int posdiff = i - sorted_pos;
            //check the continuos link
            //going forward
            
            //TODO: If find() returns nothing
            int initial_pos_find, final_pos_find;

            if(posdiff < 0)
            {
                // cout<<"Forward\n";
                initial_pos_find = i;
                final_pos_find = sorted_pos-1;
            }
            else if(posdiff > 0){
                //going backward
                // cout<<"Backward\n";
                initial_pos_find = i-1;
                final_pos_find = sorted_pos;
            }
            else{
                continue;
            }
            //find the index of initial pos
            // cout<<"Finding init: "<<initial_pos_find<<"\n";
            auto it_init_pos = find(all(prr),initial_pos_find);
            if(it_init_pos == prr.end())
            {
                flag=0;
                break;
            }
            int init_pos = it_init_pos - prr.begin();
            //find the index of the final pos-1
            // cout<<"Finding final: "<<final_pos_find<<"\n";
            auto it_fin_pos = find(all(prr),final_pos_find);
            if(it_fin_pos == prr.end())
            {
                flag=0;
                break;
            }
            int fin_pos = it_fin_pos - prr.begin();

            int prr_diff = init_pos-fin_pos;
            
            // cout<<"Comparing\n";
            if( abs(prr_diff) != abs(posdiff) -1){
                // cout<<abs(prr_diff)<<" "<<abs(posdiff)<<"\n";
                flag=0;
                break;
            }
            //find the index of initial pos -1
            //find the index of the final pos
            // for(int j=0;j<m;j++){
            //     if(prr[j] == i)
            // }
            
            //if not break and flag NO
            //at the end print YES
        }

        if(flag==1)
            cout<<"YES";
        else
            cout<<"NO";

        cout<<"\n";
    }
}