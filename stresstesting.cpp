#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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


ll correctSolution()
{

    return ;
}


ll mySolution()
{
    ll n;
    cin>>n;
    return ;
}


int main()
{
   // if multiple output required then we can simply use struct
//    OJ();
   ASSALAMU_ALAIKOM
   srand(time(NULL));
   clock_t start= clock();
   ll t=rand()%10+1;
   while(t--)
   {
     ll n = rand() % 100 + 1;
     vll v(n);
     for(ll i=0;i<n;i++)
        v[i] = rand() % 10 + 1;
    ll myAns=mySolution();
    ll corrAns=correctSolution();
    if(myAns!=corrAns)
    {
        cout<<n;
        print(v);
        cout<<"myAnswer = "<<myAns<<endl;
        cout<<"corrAnswer = "<<corrAns<<endl;
    }
   }
   cerr << "Run Time : " <<((double)(clock() - start) / CLOCKS_PER_SEC)<< " seconds"<<endl;
   return 0;
}
