#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string a,string b, int m,int n)
{
  for(int i{};i<=m;i++){
    for(int j{};j<=n;j++){
      if(i==0|| j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i{1};i<=m;i++){
    for(int j{1};j<=n;j++){
      if(a[i-1]==b[j-1])
      {
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}

int superseq(string a,string b,int n,int m,int dp[1001][1001])
{
  return (m+n-lcs(a,b,m,n));
}

int main()
{
  string a,b;
  cin>>a>>b;
  int m=a.size();
  int n=b.size();

  cout<<superseq(a,b,n,m,dp);
}
