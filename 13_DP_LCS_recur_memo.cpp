//table size should be n+1 and m+1;
#include <bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int n,int m)
{
  vector<vector<int>>dp;
  for(int i{};i<n+1;i++)
  {
    for(int j{};j<m+1;j++)
    {
      dp[i][j]=-1;
    }
  }
  if(n==0 || m==0)
  {
    return 0;
  }
  if(dp[n][m]!=-1)
  {
    return dp[n][m];
  }
  if(x[n-1]==y[m-1])
  {
    return dp[n][m]=1+lcs(x,y,n-1,m-1);
  }
  else{
    return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
  }
  return dp[n][m];
}
int main(){
  string x="abcde";
  string y="adcdf";
  int n{},m{};
  n=x.size();
  m=y.size();
  cout<<lcs(x,y,n,m);
}
