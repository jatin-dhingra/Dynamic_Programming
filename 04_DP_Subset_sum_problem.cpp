#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>arr,int sum)
{
  int n=arr.size();
  //intitilization of the array
  int dp[n+1][sum+1];
  for(int i{};i<=n;i++)
  {
    for(int j{};j<=sum;j++)
    {
      if(i==0 && j!=0)
      {
        dp[i][j]=false;

      }
      else if(j==0)
      {
        dp[i][j]=true;
      }
    }
  }
  //final code for the subset problem

  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++)
    {
      if(arr[i-1]<=j)
      {
        dp[i][j]=((dp[i-1][j-arr[i-1]]) || (dp[i-1][j]));
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
  vector<int>arr {2,3,7,8,10};
  int sum=11;
  cout<<solve(arr,sum);
}
