#include <bits/stdc++.h>
using namespace std;
int countdiff(vector<int>v,int n,int sum)
{
  int dp[n+1][sum+1];
  for(int i{};i<n+1;i++)
  {
    for(int j{};j<sum+1;j++)
    {
      if(i==0 && j!=0){
        dp[i][j]=0;
      }
      if(j==0)
      {
        dp[i][j]=1;
      }
    }
  }
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++)
    {
      if(v[i-1]<=j){
        dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}
int main()
{
  vector<int>v{1,1,2,3};
  int n=v.size();
  int diff=1;
  int fsum=accumulate(v.begin(),v.end(),0);

  int sum=(diff+fsum)/2;
  cout<<countdiff(v,n,sum);
}
