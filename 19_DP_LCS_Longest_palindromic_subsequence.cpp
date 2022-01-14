#include <bits/stdc++.h>
using namespace std;
int LPS(string s,string k,int m,int n)
{
  int dp[m+1][n+1];
  for(int i{};i<=m;i++)
  {
    for(int j{};j<=n;j++)
    {
      if(i==0||j==0)
      {
        dp[i][j]=0;
      }
    }
  }
  for(int i{1};i<=m;i++)
  {
    for(int j{1};j<=n;j++)
    {
      if(s[i-1]==k[j-1])
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
int main()
{
  string s;
  cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  int n=s.size();
  int m=t.size();
  cout<<"LPS"<<LPS(s,t,n,m)<<endl;
  cout<<"min number of deletion: "<<n-LPS(s,t,n,m)<<endl;
}
