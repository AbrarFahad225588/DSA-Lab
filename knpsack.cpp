///   ***   ---   ||         In the name of ALLAH        |||   ---   ***   ///



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

int knapsack(vector<int>&v,vector<int>&wt,int w,int n,vector<vector<int>>&dp)
{
    if(n<=0 || w<=0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w) return dp[n][w]=max(v[n-1]+knapsack(v,wt,w-wt[n-1],n-1,dp),knapsack(v,wt,w,n-1,dp));
    else return dp[n][w]=knapsack(v,wt,w,n-1,dp);

}
int main()
{
     int n=8,w=30;
    //  cin>>n>>w;
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    vector<int>wt={2,4,6,8,9,12,15,17};
     vi v={5,7,9,12,6,8,10,14};
     cout<<knapsack(v,wt,w,n,dp)<<endl;
    
    return 0;
}
