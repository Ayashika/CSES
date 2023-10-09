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
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>v(m);
  ref(i,0,m,1){
    int u,w;
    cin>>u>>w;
    v.push_back({u,w});
  }
  vector<int>grp(n+1,-1);
  vector<int>adj[n+1];
  for(auto it:v){
    adj[it.first].push_back(it.second);
    adj[it.second].push_back(it.first);
  }
  bool flag=false;
  for(int i=1; i<=n; i++){
    if(grp[i]==-1){
      queue<int>q;
      q.push(i);
      grp[i]=1;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
          if(grp[it]==-1){
            grp[it]=1-grp[node];
            q.push(it);
          }
          else{
            if(grp[it]==grp[node]){
              flag=true;
              break;
            }
          }
        }
      }
    }
  }
  if(flag) cout<<"IMPOSSIBLE"<<endl;
  else{
    for(int i=1; i<=n; i++){
      if(grp[i]==0) grp[i]=2;
      cout<<grp[i]<<" ";
    }
  }
}