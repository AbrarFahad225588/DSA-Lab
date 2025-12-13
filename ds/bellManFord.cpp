#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 
// using pbms = tree<
//     pair<int,int>,
//     null_type,
//     less<pair<int,int>>,
//     rb_tree_tag,
//     tree_order_statistics_node_update;

 
template <typename T>
using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef double dl;
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (ll)x.size()
#define mid(l,r) ((r+l)/2)
#define left(node) (node*2)
#define right(node) (node*2+1)
#define mx_int_prime 999999937
 
const double PI = acos(-1);
const double eps = 1e-9;
const int infi = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a, b) (((a) * (b)) / gcd((a), (b)))
#define sqr(a) ((a) * (a))
 
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;
 
 
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
 
 
 
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}
 
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}
 
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}
 
template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () {
            cerr << endl;
}
 
template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}
 
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
if (a.first == b.first)
{
return a.second < b.second;
}
return a.first < b.first;
}



const ll mx=1e3+123;
struct edges{
    ll u,v,w;
};

vl dist(mx,0);
vector<edges>e;

bool bellman(ll s,ll n,ll m){
    for(int i=1;i<=n;i++)dist[i]=infLL;

    dist[0]=0;
    bool isCycle = false;

    for(int i=1;i<=n;i++){
        isCycle=false;

        for(int j=0;j<m;j++){
            ll u=e[j].u;
            ll v=e[j].v;
            ll w=e[j].w;

            if(dist[u]<infLL){
                if(dist[u]+w<dist[v]){
                    dist[v]=max(dist[u]+w,-infLL);
                    isCycle=true;
                }
            }
        }
    }
    return isCycle;
}

void solve(){
    e.clear();

    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        e.PB({u,v,w});
    }

    bool chk=bellman(0,n,m);
    if(chk){
        cout<<"possible\n";
    }
    else{
        cout<<"not possible\n";
    }
}

int main()
{
    fastread();
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}