#include <bits/stdc++.h>
using namespace std;

int countofsubsetsum(vector<int>v ,int sum,int n)
{
  int dp[n+1][sum+1];
  for(int i{};i<n+1;i++){
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
  // for(int i{};i<n+1;i++){
  //   for(int j{};j<sum+1;j++){
  //     cout<<arr[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++)
    {
      if(v[i-1]<=j)
      {
        dp[i][j]=((dp[i-1][j-v[i-1]])+ (dp[i-1][j]));
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
  vector<int>v{2,3,5,6,8,10};
  int sum=10;
  int n=v.size();
  cout<<countofsubsetsum(v,sum,n);
}
