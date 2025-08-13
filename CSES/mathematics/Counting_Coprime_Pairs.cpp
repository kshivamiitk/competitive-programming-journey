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
    int n;
    cin >> n;
    vi x(n);
    rep(i,n) cin >> x[i];
    const int A = 1000000;
    static vector<int> freq(A+1), cnt(A+1), mu(A+1), primes;
    static vector<bool> is_comp(A+1);
    rep(i,n) freq[x[i]]++;
    mu[1]=1;
    for(int i=2;i<=A;i++){
        if(!is_comp[i]){
            primes.pb(i);
            mu[i]=-1;
        }
        for(int p:primes){
            int v=i*p;
            if(v>A) break;
            is_comp[v]=1;
            if(i%p==0){
                mu[v]=0;
                break;
            } else {
                mu[v]=-mu[i];
            }
        }
    }
    for(int d=1;d<=A;d++){
        for(int m=d;m<=A;m+=d){
            cnt[d]+=freq[m];
        }
    }
    long long ans=0;
    for(int d=1;d<=A;d++){
        if(mu[d]==0) continue;
        long long c=cnt[d];
        ans += mu[d] * (c*(c-1)/2);
    }
    cout << ans << endl;
}

signed main(){
    fast;
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}
