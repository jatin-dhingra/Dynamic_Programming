#include <bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int m,int n)
{
  int dp[m+1][n+1];
  //condition i!=j
  for(int i{};i<m+1;i++){
    for(int j{};j<n+1;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i{1};i<m+1;i++)
  {
    for(int j{1};j<n+1;j++){
      if(x[i-1]==y[j-1] && i!=j)
      {
        dp[i][j]=1+dp[i-1][j-1];
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
  string x{},y{};
  cin>>x>>y;
  //if one input is given take the same input for other string;
  int m=x.size();
  int n=y.size();
  cout<<lcs(x,y,m,n);
}
