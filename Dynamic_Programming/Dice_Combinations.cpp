#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define Ayashika ll t; cin>>t; while(t--)
#define INT_SIZE 32
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define pb push_back
#define arrin for(int i=0; i<n; i++){cin>>arr[i];}
#define brrin for(int i=0; i<n; i++){cin>>brr[i];}
#define pob pop_back
#define ld long double
#define M 32
#define ref(i,a,b,x) for(int i=a; i<b; i+=x)
#define reb(i,a,b,x) for(int i=a; i>=b; i-=x)
#define full(x) (x).begin(), (x).end()
#define mll map<ll,ll>
#define cmione cout<<"-1"<<endl
#define cone cout<<"1"<<endl
#define mod 1000000007
 
using namespace std;
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif                                   
}

ll f(ll target, vector<ll>&dp){
  if(target==0) return 1;
  if(target<0) return 0;
 
  if(dp[target]!=-1) return dp[target];
 
  ll ways=0;
 
  for(int i=1; i<=6; i++){
    ways+=f(target-i,dp);
    ways%=mod;
  }
  return dp[target]=ways;
}

int main(){
  init_code();
  ll sum;
  cin>>sum;
  vector<ll>dp(sum+1,-1);
  ll ans=f(sum,dp);
  cout<<ans<<endl;
}