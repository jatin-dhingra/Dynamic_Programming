#include <bits/stdc++.h>
using namespace std;
int minimumsubset(vector<int>v,int sum,int n)
{
  int dp[n+1][sum+1];
  for(int i{};i<n+1;i++)
  {
    for(int j{};j<sum+1;j++)
    {
      if(i==0 && j!=0)
      {
        dp[i][j]=0;
      }
      if(j==0)
      {
        dp[i][j]=1;
      }
    }
  }

  vector<int>candidates;
  for(int i{1};i<n+1;i++)
  {
    for(int j{1};j<sum+1;j++)
    {
      if(v[i-1]<=j)
      {
        dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  for(int i{};i<sum/2;i++)
  {
    if(dp[3][i]==1)
    {
      candidates.push_back(i);
    }
  }

  int minimum=INT_MAX;
  for(int i{};i<candidates.size();i++){
    minimum=min(minimum,sum-(2*candidates[i]));
  }
  return minimum;
}

int main()
{
  vector<int>v{1,2,7};
  int sum=accumulate(v.begin(),v.end(),0);
  int n=v.size();
  cout<<minimumsubset(v,sum,n);
}
