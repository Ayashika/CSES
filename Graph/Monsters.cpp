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
  vector<vector<char>>v(n,vector<char>(m));
  vector<vector<int>>vis(n,vector<int>(m,0));
  vector<vector<int>>dis(n,vector<int>(m,1e9));
  queue<pair<int,int>>q;
  int a_x=-1;int a_y=-1;
  int e_x=-1; int e_y=-1;
  ref(i,0,n,1){
    ref(j,0,m,1){
      cin>>v[i][j];
      if(v[i][j]=='M'){
        q.push({i,j});
        vis[i][j]=1;
        dis[i][j]=0;
      }
      else if(v[i][j]=='A'){
        a_x=i;
        a_y=j;
      }
    }
  }

  int dr[4]={-1,0,1,0};
  int dc[4]={0,1,0,-1};
  while(!q.empty()){
    auto p=q.front();
    q.pop();
    int i=p.first;
    int j=p.second;
    for(int k=0; k<4; k++){
      int nrow=i+dr[k];
      int ncol=j+dc[k];
      if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && v[nrow][ncol]=='.' && vis[nrow][ncol]==0){
        vis[nrow][ncol]=1;
        dis[nrow][ncol]=min(dis[i][j]+1,dis[nrow][ncol]);
        q.push({nrow,ncol});
      }
    }
  }
  vector<vector<char>>par(n,vector<char>(m,'.'));
  q.push({a_x,a_y});
  int steps=0;
  vector<vector<int>>dist(n,vector<int>(m,0));
  vector<vector<int>>visi(n,vector<int>(m,0));
  vis[a_x][a_y]=1;
  while(!q.empty()){
    auto node=q.front();
    q.pop();
    int i=node.first;
    int j=node.second;
    for(int r=0; r<4; r++){
      int nrow=i+dr[r];
      int ncol=j+dc[r];
      if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && v[nrow][ncol]=='.' && ((dist[i][j]+1)<dis[nrow][ncol]) && !visi[nrow][ncol]){

        if(r==0) par[nrow][ncol]='U';
        else if(r==1) par[nrow][ncol]='R';
        else if(r==2) par[nrow][ncol]='D';
        else if(r==3) par[nrow][ncol]='L';
        dist[nrow][ncol]=dist[i][j]+1;
        visi[nrow][ncol]=1;
        if(nrow==0 || ncol==0 || nrow==(n-1) || ncol==(m-1)){
          e_x=nrow;
          e_y=ncol;
          break;
        }
        q.push({nrow,ncol});
        
      }
    }
  }
  if(a_x==0 || a_y==0 || a_x==(n-1) || a_y==(m-1)){
    cout<<"YES"<<endl;
    cout<<0<<endl;
  }
  else if(e_x==-1 && e_y==-1) cout<<"NO"<<endl;
  
  else{
    int ans=dist[e_x][e_y];
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    int i=e_x;
    int j=e_y;
    string s="";
    for(int k=0; k<ans; k++){
      if(par[i][j]=='U'){
        s.push_back('U');
        i++;
      }
      else if(par[i][j]=='D'){
        s.push_back('D');
        i--;
      }
      else if(par[i][j]=='L'){
        s.push_back('L');
        j++;
      }
      else if(par[i][j]=='R'){
        s.push_back('R');
        j--;
      }
    }
    reverse(full(s));
    cout<<s<<endl;
  }
}