#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

// Unique values, ascending order
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Unique values, descending order
template <typename T>
using ordered_set_desc = tree<
    T,
    null_type,
    greater<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
// A.order_of_key(x)   *A.find_by_order(x)
// less->sorted in ascending order and unique, greater->sorted in descending order and unique
/* ==================== ORDERED MULTISET ==================== */

template <typename T>
class OrderedMultiSet {
private:
    using P = pair<T, ll>;

    tree<P, null_type, less<P>,
         rb_tree_tag, tree_order_statistics_node_update> st;

    ll timer = 0;

public:
    // Insert one occurrence
    void insert(T x) {
        st.insert({x, timer++});
    }

    // Erase one occurrence of x
    bool erase_one(T x) {
        auto it = st.lower_bound({x, LLONG_MIN});

        if (it == st.end() || it->first != x)
            return false;

        st.erase(it);
        return true;
    }

    // Number of elements strictly less than x
    ll count_less(T x) const {
        return st.order_of_key({x, LLONG_MIN});
    }

    // Number of elements less than or equal to x
    ll count_less_equal(T x) const {
        return st.order_of_key({x, LLONG_MAX});
    }

    // Frequency of x
    ll frequency(T x) const {
        return count_less_equal(x) - count_less(x);
    }

    // Number of elements in [l, r]
    ll count_range(T l, T r) const {
        if (l > r) return 0;
        return count_less_equal(r) - count_less(l);
    }

    // 0-based kth smallest
    bool kth_smallest(ll k, T &ans) const {
        if (k < 0 || k >= (ll)st.size())
            return false;

        ans = st.find_by_order(k)->first;
        return true;
    }

    // 0-based kth largest
    bool kth_largest(ll k, T &ans) const {
        if (k < 0 || k >= (ll)st.size())
            return false;

        ans = st.find_by_order((ll)st.size() - 1 - k)->first;
        return true;
    }

    // Number of elements strictly less than x = insertion position
    ll lower_bound_index(T x) const {
        return count_less(x);
    }

    // Number of elements less than or equal to x
    ll upper_bound_index(T x) const {
        return count_less_equal(x);
    }

    ll size() const {
        return (ll)st.size();
    }

    bool empty() const {
        return st.empty();
    }

    void clear() {
        st.clear();
        timer = 0;
    }
};
typedef unsigned long long ull;
#define ld long double
typedef long long ll;
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define F first
#define S second
#define CY  cout<<"YES\n";
#define CN  cout<<"NO\n";
#define forr(v,n)	vll v(n);for(int i=0;i<n;i++){cin>>v[i];}
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int)((s).size()))
#define torad(x) (x) * ((2*acos(0))/180.0)
#define ite vector<int>::iterator
#define print(a)  for(auto v:a)cout<<v<<" ";cout<<"\n";
#define ASSALAMU_ALAIKOM ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
const ll inf = 1e18;
const ll minf = -1e18;
const ll mod = 1e9+7;
#define eps 1e-12
const double PI = acos(-1);
#define fit for(auto u:(x))
#define Max(x)  *max_element (all(x))
#define Min(x) *min_element (all(x))
#define PI 2*acos(0)
#define pob pop_back
#define set_bits(n) __builtin_popcountll(n)
//set_intersection(all(v1), all(v2), back_inserter(v));
//set_union(all(v1), all(v2), back_inserter(v));
//set_difference(all(v1), all(v2), back_inserter(v));
#define endl '\n'
//a%m is equivalent to ((a%m)+m)%m -->(it will work for both negative and positive value)

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
   if (a.first > b.first)
      return 1;
   else if (a.first == b.first)
      return (a.second > b.second);
   return 0;
}
ll amodb(ll a,ll b)
{
   return ((a%b)+b)%b;
}
ll log_a_to_base_b(ll a, ll b)
{
   return log2(a) / log2(b);
}
void printBinary(ll num)
{
   for (ll i = 63; i >= 0; i--)
      cout << ((num >> i) & 1);
   cout << endl;
}
bool power_of_2(ll x)
{
   return x && !(x & (x - 1));
}
ll GCD(ll x, ll y)
{
   if (y == 0)
      return x;
   else
      return GCD(y, x % y);
}
ll LCM(ll x, ll y)
{
   return (x * y / (GCD(x, y)));
}
ll modAdd(ll a, ll b, ll m)
{
   return (a % m + b % m) % m;
}
ll modSub(ll a, ll b, ll m)
{
   return ((a % m ) - (b % m) + m) % m;
}
ll modMul(ll a, ll b, ll m)
{
   return ((a % m) * (b % m)) % m;
}
ll power(ll a, ll n)
{
   ll ans = 1;
   while (n)
   {
      if (n & 1)
      {
         ans = ans * a;
         n--;
      }
      a *= a;
      n /= 2;
   }
   return ans;
}
ll modPower(ll a, ll n, ll mod)
{
   ll ans = 1;
   while (n)
   {
      if (n & 1)
      {
         ans = ((ans % mod) * (a % mod)) % mod;
         n--;
      }
      a = ((a % mod) * (a % mod)) % mod;
      n /= 2;
   }
   return ans;
}
ll modInv(ll a, ll mod)
{
   return modPower(a, mod - 2, mod);
}
ll modDiv(ll a, ll b, ll m)
{
   return modMul(a, modInv(b, m), m);
}
const ll N = 1e5+5;
pll mod1={1e9+7,1e9+9},base={53,67}; // base should be greater than total distinct characters
vpll pw(N+5), inv(N+5), PreHash(N+5),SuffHash(N+5);
vll pr = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289};
vll bs = {31, 37, 53, 61, 67, 71};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_random()
{
    return (long long)(rng());
}
 
long long get_random_in_range(long long L, long long R)
{
    long long rndm = get_random();
    return L + (rndm % (R - L + 1));
}
 
void randomModBase()
{
    ll i = get_random_in_range(0, pr.size() - 1);
    mod1.F = pr[i];
    pr.erase(pr.begin() + i);
    i = get_random_in_range(0, pr.size() - 1);
    mod1.S = pr[i]; 
    i = get_random_in_range(0, bs.size() - 1);
    base.F = bs[i];
    bs.erase(bs.begin() + i);
    i = get_random_in_range(0, bs.size() - 1);
    base.S = bs[i];
}

void preCal()
{
   pw[0].F = pw[0].S= 1;
   for (ll i = 1; i < N; i++)
   {
      pw[i].F = modMul(pw[i - 1].F, base.F, mod1.F);
      pw[i].S = modMul(pw[i - 1].S, base.S, mod1.S);
   }
   ll pw_inv1 = modInv(base.F, mod1.F);
   ll pw_inv2 = modInv(base.S, mod1.S);
   inv[0].F = inv[0].S = 1;
   for (ll i = 1; i < N; i++)
   {
      inv[i].F = modMul(inv[i - 1].F, pw_inv1, mod1.F);
      inv[i].S = modMul(inv[i - 1].S, pw_inv2, mod1.S);
   }
}
void buildPreHash(const string& s)
{
   ll n = sz(s);
   for (ll i = 0; i < n; i++)
   {
      PreHash[i].F = modAdd((i == 0) ? 0 : PreHash[i - 1].F, modMul(pw[i].F, s[i] - 'a' + 1, mod1.F),mod1.F);
      PreHash[i].S = modAdd((i == 0) ? 0 : PreHash[i - 1].S, modMul(pw[i].S, s[i] - 'a' + 1, mod1.S),mod1.S);
   }
}
void buildSuffHash(const string& s)
{
   ll n=sz(s);
   ll ln=n-1;
   for (ll i = ln; i >= 0; i--)
   {
      SuffHash[i].F = modAdd((i == ln) ? 0 : SuffHash[i + 1].F, modMul(pw[ln - i].F, s[i] - 'a' + 1, mod1.F), mod1.F);
      SuffHash[i].S = modAdd((i == ln) ? 0 : SuffHash[i + 1].S, modMul(pw[ln - i].S, s[i] - 'a' + 1, mod1.S), mod1.S);
   }
}
pll getPreHash(ll l, ll r)
{
   ll res1 = modSub(PreHash[r].F, (l == 0) ? 0 : PreHash[l - 1].F, mod1.F);
   ll res2 = modSub(PreHash[r].S, (l == 0) ? 0 : PreHash[l - 1].S, mod1.S);
   res1 = modMul(res1, inv[l].F, mod1.F);
   res2 = modMul(res2, inv[l].S, mod1.S);
   return {res1,res2};
}
pll getSuffHash(ll l, ll r,ll ln) //here ln is the last index(typically sz(s)-1) of the string.
{
   ll res1 = modSub(SuffHash[l].F, (r == ln) ? 0 : SuffHash[r + 1].F, mod1.F);
   ll res2 = modSub(SuffHash[l].S, (r == ln) ? 0 : SuffHash[r + 1].S, mod1.S);
   res1 = modMul(res1, inv[ln - r].F, mod1.F);
   res2 = modMul(res2, inv[ln - r].S, mod1.S);
   return {res1,res2};
}
ll double_cmp(double a, double b)
{
   if (fabs(a - b) <= eps)
      return 0;
   else
      return a < b ? -1 : 1;
}
vector<bool> Sieve(ll n)
{
   vector<bool> prime(n + 1, true);
   for (ll p = 2; p * p <= n; p++)
   {
      if (prime[p] == true)
      {
         for (ll i = p * p; i <= n; i += p)
            prime[i] = false;
      }
   }
   return prime;
}
vll p_list;
vector<ll> sieve(ll n)
{
   vector<bool> prime(n + 1, true);
   for (ll p = 2; p * p <= n; p++)
   {
      if (prime[p] == true)
      {
         for (ll i = p * p; i <= n; i += p)
            prime[i] = false;
      }
   }
   for (ll i = 2; i <= n; i++)
   {
      if (prime[i])
         p_list.pb(i);
   }
   return p_list;
}
vector<vll> adj;
vll vis,color;
void dfs(ll node)
{
   vis[node] = 1;
   cout << node << " ";
   for (auto child : adj[node])
   {
      if (!vis[child])
         dfs(child);
   }
}
bool Is_Bipartite(ll node, ll clr)
{
   vis[node] = 1;
   color[node] = clr;
   for (auto child : adj[node])
   {
      if (!vis[child] && Is_Bipartite(child, clr ^ 1) == false)
         return false;
      else if (color[node] == color[child])
         return false;
   }
   return true;
}
bool Cycle(ll node, ll par)
{
   vis[node] = 1;
   for (auto child : adj[node])
   {
      if (!vis[child] && Cycle(child, node))
         return true;
      else if (child != par)
         return true;
   }
   return false;
}
vll Sub_sz;
ll Sub_Tree_Sz(ll node)
{
   ll curr_sz = 1;
   vis[node] = 1;
   for (auto child : adj[node])
   {
      if (!vis[child])
         curr_sz += Sub_Tree_Sz(child);
   }
   Sub_sz[node] = curr_sz;
   return curr_sz;
}

ll timer = 0;
vll in, low;
void Bridge(ll node, ll par)
{
   vis[node] = 1;
   in[node] = low[node] = timer++;
   for (auto child : adj[node])
   {
      if (child == par)
         continue; //direct parent
      if (!vis[child])
      {
         //forward edge
         Bridge(child, node);
         low[node] = min(low[node], low[child]);
         if (low[child] > in[node])
            cout << node << " " << child <<"Is a Bridge"<< endl;
      }
      else
         low[node] = min(low[node], in[child]); //back edge
   }
}

void Cutpoint(ll node, ll par=-1) //articulation point
{
   vis[node] = 1;
   in[node] = low[node] = timer++;
   ll children = 0;
   for (auto child : adj[node])
   {
      if (child == par)
         continue; //direct parent
      if (!vis[child])
      {
         //forward edge
         Cutpoint(child, node);
         low[node] = min(low[node], low[child]);
         if (low[child] >= in[node] && par != -1)
            cout << node << "Is a Cutpoint" << endl;
         children++;
      }
      else
         low[node] = min(low[node], in[child]); //back edge
   }
   if (par == -1 && children > 1)
      cout << node << "Is a Cutpoint" << endl;
}
void bfs(ll s)
{
   queue<ll> q;
   vis[s] = 1;
   q.push(s);
   while (!q.empty())
   {
      ll x = q.front();
      cout << x << " ";
      q.pop();
      for (auto child : adj[x])
      {
         if (!vis[child])
         {
            vis[child] = 1;
            q.push(child);
         }
      }
   }
}

void Allsubset(vll &v,ll n)
{
   vll tmp;
   for(ll mask=1;mask<(1<<sz(v));mask++)
   {
      for(ll i=0;i<sz(v);i++)
      {
         if(mask&(1<<i))
         {
            cout<<v[i]<<" ";
         }
      }
      cout<<endl;
   }
   return;
}

void TopSort(ll n)  // Topological Sort
{
   vll res;
   priority_queue<ll,vector<ll>,greater<ll>>pq;
   ll i;
   for(i=1;i<=n;i++)
      if(in[i]==0)
       pq.push(i);
   while(!pq.empty())
   {
      ll x=pq.top();
      res.pb(x);
      pq.pop();
      for(auto node:adj[x])
      {
         in[node]--;
         if(in[node]==0)
           pq.push(node);
      }
   }
   print(res);
}
// Define a custom hash function for std::pair<any type> std::vector<any type>
//now we can use pair<any tpe>,vector<any type> in unordered_set and unordered_map but we have to use a extra argument as CustomHash
//unordered_set<pll,CustomHash>st; st.insert(pair<long long, long long);
//unorderd_map<pll,ll,CustomHash>mp; mp[pll]++;
struct CustomHash {
    // Hash function for std::pair
    template <typename T1, typename T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        size_t hash1 = std::hash<T1>()(p.first);
        size_t hash2 = std::hash<T2>()(p.second);
        // Combine the hashes
        return hash1 ^ (hash2 << 1);
    }

    // Hash function for std::vector
    template <typename T>
    size_t operator()(const std::vector<T>& v) const {
        size_t hash = 0;
        for (const T& elem : v) {
            hash ^= std::hash<T>()(elem) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

// ============================= DSU (Disjoint Set Union) =============================

// Standard DSU (with union by size + path compression)
struct DSU {
    vll parent, sz;

    DSU(ll n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (ll i = 0; i <= n; i++) parent[i] = i;
    }

    ll find_set(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]); // path compression
    }

    bool union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false; // already in the same set
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    ll get_size(ll v) {
        return sz[find_set(v)];
    }
};

/*  
// ============================= Rollback DSU =============================
// Only needed in advanced problems (dynamic connectivity, offline queries, etc.)

struct RollbackDSU {
    vll parent, sz;
    stack<pair<ll, pll>> history; // {node b, {parent[b], size[a]}}

    RollbackDSU(ll n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (ll i = 0; i <= n; i++) parent[i] = i;
    }

    ll find_set(ll v) {
        while (v != parent[v]) v = parent[v]; // no path compression here!
        return v;
    }

    bool union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            history.push({-1, {-1, -1}}); // marker for "nothing happened"
            return false;
        }
        if (sz[a] < sz[b]) swap(a, b);
        history.push({b, {parent[b], sz[a]}});
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    void rollback() {
        if (history.empty()) return;
        auto [b, info] = history.top();
        history.pop();
        if (b == -1) return; // nothing was merged
        auto [old_parent, old_size] = info;
        ll a = parent[b];
        parent[b] = old_parent;
        sz[a] = old_size;
    }
};
*/

// ============================= Lazy Segment Tree =============================
struct LazySegTree {
    ll n;
    vector<ll> tree,lazy;

    LazySegTree(ll _n=0) { init(_n); }
    void init(ll _n) { n=_n; tree.assign(4*n,0); lazy.assign(4*n,0); }

    void push(ll node,ll l,ll r) {
        if (lazy[node]!=0) {
            tree[node] += (r-l+1)*lazy[node]; // SUM + range add
            // tree[node] += lazy[node];      // MIN/MAX (if only add updates)
            if (l!=r) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node]=0;
        }
    }

    void build(vector<ll> &a,ll node,ll l,ll r) {
        if (l==r) { 
            tree[node] = a[l]; 
            return; 
        }
        ll mid=(l+r)/2;
        build(a,2*node,l,mid);
        build(a,2*node+1,mid+1,r);
        tree[node] = tree[2*node] + tree[2*node+1];   // SUM
        // tree[node] = min(tree[2*node], tree[2*node+1]); // MIN
        // tree[node] = max(tree[2*node], tree[2*node+1]); // MAX
        // tree[node] = gcd(tree[2*node], tree[2*node+1]); // GCD
    }

    void update(ll node,ll l,ll r,ll ql,ll qr,ll val) {
        push(node,l,r);
        if (qr<l || ql>r) return;
        if (ql<=l && r<=qr) {
            lazy[node] += val;
            push(node,l,r);
            return;
        }
        ll mid=(l+r)/2;
        update(2*node,l,mid,ql,qr,val);
        update(2*node+1,mid+1,r,ql,qr,val);
        tree[node] = tree[2*node] + tree[2*node+1];   // SUM
        // tree[node] = min(tree[2*node], tree[2*node+1]); // MIN
        // tree[node] = max(tree[2*node], tree[2*node+1]); // MAX
        // tree[node] = gcd(tree[2*node], tree[2*node+1]); // GCD
    }

    ll query(ll node,ll l,ll r,ll ql,ll qr) {
        push(node,l,r);
        if (qr<l || ql>r) return 0;    // SUM neutral
        // if (qr<l || ql>r) return INF;   // MIN neutral
        // if (qr<l || ql>r) return -INF;  // MAX neutral
        // if (qr<l || ql>r) return 0;     // GCD neutral

        if (ql<=l && r<=qr) return tree[node];
        ll mid=(l+r)/2;
        ll left = query(2*node,l,mid,ql,qr);
        ll right = query(2*node+1,mid+1,r,ql,qr);

        return left + right;           // SUM
        // return min(left, right);    // MIN
        // return max(left, right);    // MAX
        // return gcd(left, right);    // GCD
    }
};



/* ==================== FENWICK TREE ==================== */

// tree must be 1-indexed.
// Before build: tree[i] contains the original value/frequency.

// O(n): Linear build
void constructFTree(vll &tree)
{
    int n = sz(tree) - 1;

    for (int i = 1; i <= n; i++)
    {
        int p = i + (i & -i);

        if (p <= n)
            tree[p] += tree[i];
    }
}

// O(log n): Add val at index i
void updatePointFTree(int i, ll val, vll &tree)
{
    int n = sz(tree) - 1;

    while (i <= n)
    {
        tree[i] += val;
        i += (i & -i);
    }
}

// O(log n): Sum of [1, i]
ll prefSumFTree(int i, const vll &tree)
{
    ll sum = 0;

    while (i > 0)
    {
        sum += tree[i];
        i -= (i & -i);
    }

    return sum;
}

// O(log n): Sum of [l, r]
ll rangeSumFTree(int l, int r, const vll &tree)
{
    if (l > r) return 0;

    return prefSumFTree(r, tree)
         - prefSumFTree(l - 1, tree);
}

// O(log n): Find the index of the k-th element
// Works when tree represents non-negative frequencies.
// k is 1-based and must be within the total frequency.
int findKthFTree(ll k, const vll &tree)
{
    int n = sz(tree) - 1;
    int pos = 0;
    ll sum = 0;

    int jump = 1;
    while (jump <= n / 2)
        jump *= 2;

    for (; jump > 0; jump /= 2)
    {
        int next = pos + jump;

        if (next <= n && sum + tree[next] < k)
        {
            sum += tree[next];
            pos = next;
        }
    }

    return pos + 1;
}


ll tc;

void solve()
{
   
}

int main()
{
   ASSALAMU_ALAIKOM
   clock_t start= clock();
   ll t=1;
   cin>>t;
   for(tc=1;tc<=t;tc++)
   {
      solve();
   }
   cerr << "Run Time : " <<((double)(clock() - start) / CLOCKS_PER_SEC)<< " seconds"<<endl;
   return 0;
}
