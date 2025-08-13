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

int modexp(int a, int b) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> fact, invfact;
void precomp(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[n] = modexp(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}
struct seg{
    int l, r, i;
};
bool cmp1(seg a , seg b){
    return a.l < b.l;
}
bool cmp2(seg a , seg b){
    return a.r > b.r;
}
void solve(){
    int n ;
    cin >> n ;
    vector<seg>arr(n);
    rep(i , n){
        cin >> arr[i].l >> arr[i].r;
        arr[i].i = i;
    }
    vector<seg>temp1 = arr;
    sort(all(temp1), cmp1);
    // sorted based on the left of each of the segment
    int maxm = ninf;
    vi inside(n , 0);
    rep(i , n){
        // check if the 
        if(maxm == ninf){
            // this is the one with minm left , 
            
        }
        else if(temp1[i].r <= maxm){
            inside[temp1[i].i] = 1;
        }
        maxm = max(maxm, temp1[i].r);
    }
    int minm = inf;
    vi outside(n , 0);
    vector<seg>temp2 = arr;
    sort(all(temp2), cmp2);
    rep(i , n){
        if(temp2[i].l >= minm){
            inside[temp2[i].i] = 1;
        }
        minm = min(minm, temp2[i].l);
    }
    rep(i , n){
        cout << outside[i] << " ";
    }
    cout << endl;
    rep(i , n){
        cout << inside[i] << " ";
    }
    cout << endl;
    
}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}