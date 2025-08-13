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
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {};
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) f[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    // find smallest idx such that query(idx) >= target
    int findKth(int target) {
        int idx = 0, bitMask = 1 << (31 - __builtin_clz(n));
        for (; bitMask; bitMask >>= 1) {
            int t = idx + bitMask;
            if (t <= n && f[t] < target) {
                idx = t;
                target -= f[t];
            }
        }
        return idx + 1;
    }
};

vector<int> josephus(int n, int k) {
    Fenwick bit(n);
    for (int i = 1; i <= n; ++i)
        bit.update(i, 1);

    vector<int> order;
    int r = 0;          
    int remaining = n;

    while (remaining--) {
        r = (r + k) % (remaining + 1);
        int pos = bit.findKth(r + 1);
        order.push_back(pos);
        bit.update(pos, -1);
    }
    return order;
}



void solve(){
    int n,k;
    cin >> n >> k;
    vi ans = josephus(n , k);
    rep(i , ans.size()){
        cout << ans[i] << " " ;
    }
    cout << endl;
    return ;
    queue<int>q;
    for(int i = 1 ; i < n+1 ; i++) q.push(i);
    while(!q.empty()){
        int temp = k % q.size();
        while(temp--){
            int top = q.front();
            q.pop();
            q.push(top);
        }
        cout << q.front() << " ";
        q.pop();
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