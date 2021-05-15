/*
    author:ujwalll
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define nx cout << "\n";
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
#define pp pair<ll, ll>
#define ppi pair<int, int>
typedef long long int ll;
#define pri(x) printf("%d ", x);
#define prl(x) printf("%lld ", x);
#define fi first;
#define se second;
#define pb push_back;
#define all(v) v.begin(), v.end()
#define minimum 1
#define maximum 1e5 
#define random minimum + (rand() % static_cast<int>(maximum - minimum + 1))

bool isPowerOfTwo(ll x){
    return x && (!(x & (x - 1)));
}
void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
long long binpow(long long a, long long b){
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};
////////////////////////////////////////////////////////////////////
struct coprime{
    vector<ll> s,values={0};
    void push(ll x){
        s.push_back(x);
        values.push_back(__gcd(values.back(),x));
    }
    ll pop(){
        ll res = s.back();
        s.pop_back();
        values.pop_back();
        return res;
    }
    ll gcd(){
        return values.back();
    }
    bool empty(){
        return s.empty();
    }
};
coprime s1,s2;
void add(ll x){
    s2.push(x);
}
void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good(){
    ll g1 = s1.gcd();
    ll g2 = s2.gcd();
    return __gcd(g1,g2)==1;
}
int main(){
    fastio();
    int tc = 1;
    // cin>>tc;
    while(tc--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i,n){
            cin >> a[i];
        }
        ll l = 0, res = INT_MAX;
        rep(r,n){
            add(a[r]);
            while (good()){
                remove();
                res = min(res,r - l + 1);
                l++;
            }
        }
        if(res == INT_MAX) cout << -1;
        else cout << res << "\n";
        done:;
    }
    return 0;
}
