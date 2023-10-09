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
int main(){
  init_code();
  ll n,m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>>adj(n+1);
  vector<ll>dist(n+1,LLONG_MAX);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  ref(i,0,m,1){
    ll a,b,c;
    cin>>a>>b>>c; 
    adj[a].push_back({b,c});
  }
  pq.push({0,1});
  dist[1]=0;
  while(!pq.empty()){
    auto p=pq.top();
    ll dis=p.first;
    ll node=p.second;
    pq.pop();
    if(dis>dist[node]) continue;
    for(auto it:adj[node]){
      if(dis+it.second<dist[it.first]){
        dist[it.first]=dis+it.second;
        pq.push({dis+it.second,it.first});
      }
    }
  }
  ref(i,0,n,1){
    cout<<dist[i+1]<<" ";
  }
}