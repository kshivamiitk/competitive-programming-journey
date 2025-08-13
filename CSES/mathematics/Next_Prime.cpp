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
bool isprime(int n){
    if(n == 1) return false;
    if (n == 2 ) return true;
    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0) return false;
    }
    return true;
}
ll modmul(ll a, ll b, ll m) {
    __int128 r = ( __int128 ) a * b;
    return (ll)(r % m);
}

ll modpow(ll a, ll d, ll m) {
    ll r = 1;
    while (d) {
        if (d & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        d >>= 1;
    }
    return r;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})
        if (n % p == 0) return n == p;
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (ll a : {2ULL, 7ULL, 61ULL}) {
        if (a >= n) continue;
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (ll r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}
void solve(){
    int n; cin >> n;
    if(n == 1 ){
        cout << 2 << endl;
        return;
    }
    if(n == 2){
        cout << 3 << endl;
        return;
    }
    int p = n & 1 ? n + 2 : n + 1;
    while(!isPrime(p)){
        p += 2;
    }
    cout << p << endl;
}
signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}