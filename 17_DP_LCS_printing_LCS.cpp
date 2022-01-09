
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string a,string b,int m,int n)
{
  for(int i{};i<=m;i++)
  {
    for(int j{};j<=n;j++)
    {
      if(i==0|| j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i{1};i<=m;i++)
  {
    for(int j{1};j<=n;j++)
    {
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

string printlcs(string a, string b,int m, int n,int dp[1001][1001])
{
  string ans;
  int i=m;
  int j=n;
  while(i>0 && j>0)
  {
    if(a[i-1]==b[j-1]){
      ans.push_back(a[i-1]);
      i--;
      j--;
    }
    else
    {
      if(dp[i][j-1]>dp[i-1][j])
      {
        j--;
      }
      else
      {
        i--;
      }
    }
  }
  return ans;
}

int main()
{
  string a,b;
  cin>>a>>b;
  int m=a.size();
  int n=b.size();
  cout<<lcs(a,b,m,n)<<endl;
  cout<<printlcs(a,b,m,n,dp)<<endl;
}
