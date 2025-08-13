#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<iomanip>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define vc vector<char>
#define vb vector<bool>
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<int, vector<int>, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

void solve(){
    int t;
    cin>>t;
    vector<int> ns(t);
    int nmax=0;
    rep(i,t){
        cin>>ns[i];
        nmax=max(nmax,ns[i]);
    }
    int K=(int)((sqrt((long double)8*nmax+1)-1)/2);
    vector<int> T;
    T.reserve(K);
    for(int k=1;k<=K;k++) T.pb(k*(k+1)/2);
    rep(i,t){
        int n=ns[i];
        if(binary_search(all(T),n)){
            cout<<1<<endl;
            continue;
        }
        int l=0,r=sz(T)-1;
        bool fnd=false;
        while(l<=r){
            int s=T[l]+T[r];
            if(s==n){fnd=true;break;}
            else if(s<n) l++;
            else r--;
        }
        if(fnd) cout<<2<<endl;
        else cout<<3<<endl;
    }
}

signed main(){
    fast;
    solve();
    return 0;
}
