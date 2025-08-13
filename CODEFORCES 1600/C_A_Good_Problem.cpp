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
#define MAP map<ll,ll>
#define mod 1000000007
#define endl "\n"
#define ff first
#define vc vector<char>
#define vb vector<bool>
#define ss second
#define f(i,a,b) for(ll i(a); i<b; i++)
#define rep(i,n) for(ll i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<ll> >
#define vpi vector<pair<ll,ll> >
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<ll, vector<ll>, greater<ll> >
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

ll modexp(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<ll> fact, invfact;
void precomp(ll n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    invfact[n] = modexp(fact[n], mod - 2);
    for (ll i = n - 1; i >= 0; i--) invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}

void solve(){
    ll n , l , r , k;
    cin>>n>>l>>r>>k;
    if(n%2==1)
    {
        cout<<l<<endl;
        return;
    }
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    ll res = 1;             
    bool fl = 0;
    while(res <= r)
    {
        if(res > l)
        {
            fl = 1;
            if(k <= n-2) cout << l << endl;
            else cout << res << endl;
            break;
        }
        if(res > r / 2) break; 
        res *= 2;
    }
    if(!fl) cout<<-1<<endl;
}

int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
