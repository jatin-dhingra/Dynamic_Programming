#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int>arr,int sum)
{
  int n=arr.size();
  int dp[n+1][sum+1];
  int totalsum=accumulate(arr.begin(),arr.end(),0);
  if(totalsum%2!=0)
  {
    return false;
  }
  else
  {

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

    //final code of equal sum partition by jatin dhingra!

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=sum;j++)
      {
        if(arr[i-1]<=j)
        {
          dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
        }
        else
        {
          dp[i][j]=dp[i-1][j];
        }
      }
    }

    
    return dp[n][sum];
  }



}
int main()
{
  vector<int>arr{1, 3, 3, 2, 3, 2};
  int sum=7;
  cout<<solve(arr,sum);
}
