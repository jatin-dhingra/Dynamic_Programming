#include <bits/stdc++.h>
using namespace std;

int lcs(string s,string t,int n,int m)
{
  int dp[n+1][m+1];
  for(int i{};i<=n;i++){
    for(int j{};j<=m;j++){
      if(i==0||j==0)
      {
        dp[i][j]=0;
      }

    }
  }
  for(int i{1};i<=n;i++){
    for(int j{1};j<=m;j++)
    {
      if(s[i-1]==t[j-1] && i!=j)
      {
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[n][n];
}

int main()
{
  string s;
  cin>>s;
  string t=s;
  int n=s.size();
  int m=n;
  cout<<lcs(s,t,n,m);
}
