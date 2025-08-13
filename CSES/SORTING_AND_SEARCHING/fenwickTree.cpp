#include<iostream>
#include<vector>
#include<math.h>
#include<cmath>
using namespace std;
// structure of fenwick tree
class fenwickTree{
    public:
    int n;
    vector<int>bit;// size = n + 1 
    vector<int>builder;
    void initialise(){
        bit.assign(n + 1 , 0);
        for(int i = 1 ; i <= n ; i++) bit[i] = builder[i];
        for(int i = 1 ; i <= n ; i++){
            int j = i + (i & -i);
            if(j <= n){
                bit[j] += bit[i];
            }
        }
    }
    void update(int index , int val){
        for(; index <= n ; index += (index & -index)) bit[index] += val;
    }
    int query(int left , int right){
        int ans = 0;
        int index = right;
        for(; index > 0 ; index -= (index & -index)){
            ans += bit[index];
        }
        index = left - 1;
        for(; index > 0 ; index -= (index & -index)){
            ans -= bit[index];
        }
        return ans;
    }
};
int main(){
    // this is made for fenwick tree
    int n ;
    cin >> n;
    vector<int>arr(n + 1);
    // cout << arr[0] << endl;
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];
    fenwickTree tree;
    tree.n = n;
    tree.builder = arr;
    tree.initialise();
    int q ;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            // we need to insert;
            int index, val;
            cin >> index >> val;
            tree.update(index, val);
        }else{
            // query
            int left , right;
            cin >> left >> right;
            cout << tree.query(left , right) << endl;
        }
    }
}