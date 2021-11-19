//TOTAL  NUMBERS OF WAYS TO GET THE DESIRED OUTPUT
//repeatation is allowed 
#include <bits/stdc++.h>
using namespace std;
int coinchange(vector<int>coin,int sum)
{
  int n=coin.size();
  int dp[n+1][sum+1];
  for(int i{1};i<sum+1;i++)
  {
    dp[0][i]=0;
  }
  for(int i{};i<n+1;i++){
    dp[i][0]=1;
  }
  for(int i{1};i<n+1;i++)
  {
    for(int j{1};j<sum+1;j++)
    {
      if(coin[i-1]<=j){
        dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j]; 
        //main condition to use dp[i][] instead of dp[i-1][]
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
  vector<int>coin{1,2,3};
  int sum=5;
  cout<<coinchange(coin,sum)<<endl;
}
