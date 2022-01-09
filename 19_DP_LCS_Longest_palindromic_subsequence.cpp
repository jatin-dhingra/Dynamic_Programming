#include <bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
int lcs(string x,string y,int m,int n)
{

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
      if(x[i-1]==y[j-1])
      {
        dp[i][j]=1+dp[i-1][j-1];
      }
      else
      {
        dp[i][j]=0;
      }
    }
  }
  return dp[m][n];
}
int main()
{
  string x{};
  cin>>x;
  string y;
  int m=x.size();
  for(int i=m;i>=0;i--)
  {
      y.push_back(s[i]);
  }

  int n=y.size();

  cout<<lcs(x,y,m,n);
}
