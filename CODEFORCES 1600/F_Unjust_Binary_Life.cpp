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
#include<array>

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

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi prefa(n+1, 0), prefb(n+1, 0);
    f(i,1,n+1) prefa[i] = prefa[i-1] + (s[i-1] == '1');
    f(i,1,n+1) prefb[i] = prefb[i-1] + (t[i-1] == '1');
    vi prea(n), preb(n);
    f(i,1,n+1) prea[i-1] = (i - 2*prefa[i]);
    f(i,1,n+1) preb[i-1] = (2*prefb[i] - i);
    sort(all(preb));
    vi prb(n+1, 0);
    f(i,1,n+1) prb[i] = prb[i-1] + preb[i-1];
    int sum = 0;
    f(i,0,n) {
        int v = prea[i];
        int k = ub(all(preb), v) - preb.begin();

        int ls = v * k - prb[k];
        int rs = (prb[n] - prb[k]) - v * (n - k);

        sum += ls + rs;
    }

    int tts  = n*n*(n+1)/2;
    int answer = tts - sum/2;

    cout << answer << endl;
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
