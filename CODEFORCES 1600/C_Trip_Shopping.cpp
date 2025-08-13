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
bool cmp(const pi &x, const pi &y){
    return x.ff < y.ff;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int s = 0;
    vpi intervals(n);
    rep(i,n){
        s += abs(a[i] - b[i]);
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        intervals[i] = mp(l, r);
    }
    if(k == 0){
        cout << s << endl;
        return;
    }
    sort(all(intervals), cmp);
    int maxr = intervals[0].ss;
    int delta = inf;
    f(j,1,n){
        int l = intervals[j].ff;
        int gap = (l > maxr ? l - maxr : 0);
        delta = min(delta, gap);
        maxr = max(maxr, intervals[j].ss);
    }

    int ans = s + 2 * delta;
    cout << ans << endl;
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
