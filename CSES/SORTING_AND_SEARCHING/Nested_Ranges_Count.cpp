#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree (BIT) supporting point updates and prefix sums.
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n): n(_n), bit(n+1, 0) {}

    // add v at index i (1-based)
    void update(int i, ll v=1) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    // sum of [1..i]
    ll query(int i) const {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // sum of [l..r]
    ll query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<ll,3>> a(n);
    vector<ll> ys(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;        // remember original index
        ys[i] = a[i][1];
    }

    // 1) coordinate-compress y's
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto getY = [&](ll y){
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    };
    int M = ys.size();

    vector<ll> contains(n), contained_by(n);

    // 2) Count how many intervals contain this one
    //    sort by x asc, then y desc
    {
        vector<array<ll,3>> ord = a;
        sort(ord.begin(), ord.end(), [&](auto &A, auto &B){
            if (A[0] != B[0]) return A[0] < B[0];
            return A[1] > B[1];
        });

        Fenwick fw(M);
        for(auto &t: ord){
            int idx = getY(t[1]);
            // count prior intervals J with y_J >= y_i
            contained_by[t[2]] = fw.query(idx, M);
            fw.update(idx, 1);
        }
    }

    // 3) Count how many intervals this one contains
    //    sort by x desc, then y asc
    {
        vector<array<ll,3>> ord = a;
        sort(ord.begin(), ord.end(), [&](auto &A, auto &B){
            if (A[0] != B[0]) return A[0] > B[0];
            return A[1] < B[1];
        });

        Fenwick fw(M);
        for(auto &t: ord){
            int idx = getY(t[1]);
            // count prior intervals J with y_J <= y_i
            contains[t[2]] = fw.query(1, idx);
            fw.update(idx, 1);
        }
    }

    // 4) Output
    for(int i = 0; i < n; i++){
        cout << contains[i] << (i+1<n ? ' ' : '\n');
    }
    for(int i = 0; i < n; i++){
        cout << contained_by[i] << (i+1<n ? ' ' : '\n');
    }

    return 0;
}
