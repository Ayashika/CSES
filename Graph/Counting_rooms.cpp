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

void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&board){
  int n=board.size();
  int m=board[0].size();
  vis[i][j]=true;
  int dr[4]={-1,0,1,0};
  int dc[4]={0,1,0,-1};

  for(int k=0; k<4; k++){
    int newi=i+dr[k];
    int newj=j+dc[k];
    if(newi>=0 && newi<n && newj>=0 && newj<m && board[newi][newj]=='.' && vis[newi][newj]==false){
      dfs(newi,newj,vis,board);
    }
  }
}

int main(){
  init_code();
  ll n,m;
  cin>>n>>m;
  vector<vector<bool>>vis(n,vector<bool>(m));
  vector<vector<char>>board(n,vector<char>(m));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>board[i][j];
      vis[i][j]=false;
    }
  }
  ll c=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j]=='.' && vis[i][j]==false){
        c++;
        dfs(i,j,vis,board);
      }
    }
  }
  cout<<c;
}