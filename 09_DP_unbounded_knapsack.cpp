#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n=5;
  int sum=6;
  int val[5]{1,2,4,5,7};
  int dp[n+1][sum+1];
  for(int i{};i<sum+1;i++){
    dp[0][i]=0;
  }
  for(int i{};i<n+1;i++)
  {
    dp[i][0]=0;
  }
  //unbounded kanpsack code by jatin dhingra

  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++){
      if(val[i-1]<=j){
        dp[i][j]=max(val[i-1]+dp[i][j-val[i-1]],dp[i-1][j]);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }

    }
  }
  cout<<dp[n][sum];
}
