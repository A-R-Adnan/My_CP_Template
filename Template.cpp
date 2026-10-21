#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define pbds tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
// A.order_of_key(x)   *A.find_by_order(x)
// less->sorted in ascending order and unique, greater->sorted in descending order and unique
// less_equal-> it will work as multiset and in ascending order, greater_equal->same as multiset in descending order 
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
#define eps 1e-9
const double PI = acos(-1);
#define fit for(auto u:(x))
#define Max(x)  *max_element (all(x))
#define Min(x) *min_element (all(x))
#define PI 2*acos(0)
#define pob pop_back
#define set_bits(n) __builtin_popcountll(n)

#ifndef DeBuG
	#define dbg(...)	
#endif


ll tc;
// (i & -i) eita i er LSB dei right most 1;
void constructFTree(vll &tree)
{
    int n=sz(tree)-1;
    for(int i=1;i<=n;i++)
    {
        int p=i+ (i & -i);
        if(p<=n)
         tree[p]+=tree[i];
    }
}

void updatePointFTree(ll i, ll val,vll &tree)
{
    while(i<=sz(tree)-1)
    {
        tree[i]+=val;
        i+=i&-i;
    }
}

ll prefSumFTree(int i,vll &tree)
{
    ll sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=i&-i;
    }
    return sum;
}

ll rangeSumFTree(int l,int r, vll &tree)
{
    return prefSumFTree(r,tree)-prefSumFTree(l-1,tree);
}

ll findKthFTree(ll k, vll &tree) //binary lifting(usually pbds diye kora jai)
{
    ll n=sz(tree)-1;
    ll pos=0,sum=0,jump=1;
    while(jump*2<=n)
     jump*=2;
    for(;jump>0;jump/=2)
    {
        ll next=pos+jump;
        if(next<=n && tree[next]+sum<k)
        {
            sum+=tree[next];
            pos=next;
        }
    }
    return pos+1;
}

// void solve()
// {
//    ll n,q,i;
//    cin>>n>>q;
//    vll v,tree(1),salary(n+1);
//    vector<pair<char,pair<ll,ll>>>qry;
//    for(i=1;i<=n;i++)
//    {
//         cin>>salary[i];
//         v.pb(salary[i]);
//    }
//    for(i=0;i<q;i++)
//    {
//      char ch;
//      ll a,b;
//      cin>>ch>>a>>b;
//      if(ch=='!')
//         v.pb(b);
//      qry.pb({ch,{a,b}});
//    }

//    sort(all(v));
//    v.erase(unique(all(v)),v.end());

//    for(auto u:v)
//      tree.pb(0);
//     for(i=1;i<=n;i++)
//     {
//         int ind=lower_bound(all(v),salary[i])-v.begin()+1;
//         tree[ind]++;
//     }
//    constructFTree(tree);
//    for(i=0;i<q;i++)
//    {
//      if(qry[i].F=='!')
//      {
//         ll ind=lower_bound(all(v),salary[qry[i].S.F])-v.begin()+1;
//         updatePointFTree(ind,-1,tree);
//         ind=lower_bound(all(v),qry[i].S.S)-v.begin()+1;
//         updatePointFTree(ind,1,tree);
//         salary[qry[i].S.F]=qry[i].S.S;
//      }
//      else
//      {
//         int l=lower_bound(all(v),qry[i].S.F)-v.begin();
//         int r=upper_bound(all(v),qry[i].S.S)-v.begin();
//         // dbg(l,r,qry[i].S.F,qry[i].S.S);
//         cout<<rangeSumFTree(l+1,r,tree)<<endl;
//      }
//    }
// }

void solve()
{
    ll n,q,i;
    cin>>n>>q;
    vll salary(n+1);
    pbds st;
    for(i=1;i<=n;i++)
    {
        cin>>salary[i];
        st.insert({salary[i],i});
    }
    while(q--)
    {
        char ch;
        ll a,b;
        cin>>ch>>a>>b;
        if(ch=='!')
        {
            st.erase({salary[a],a});
            st.insert({b,a});
            salary[a]=b;
        }
        else
        {
            ll right=st.order_of_key({b+1,0});
            ll left=st.order_of_key({a,0});
            cout<<right-left<<endl;
        }
    }
    
}

int main()
{
   ASSALAMU_ALAIKOM
   ll t=1;
//    cin>>t;
   for(tc=1;tc<=t;tc++)
   {
      solve();
   }
   return 0;
}
