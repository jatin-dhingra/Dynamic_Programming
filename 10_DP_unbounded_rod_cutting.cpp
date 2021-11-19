#include <bits/stdc++.h>
using namespace std;
int rodcutting(vector<int>lengthh,vector<int>price,int len)
{
  int n=lengthh.size();
  int dp[n+1][len+1];
  for(int i{};i<n+1;i++){
    dp[0][i]=0;
  }
  for(int i{};i<len+1;i++){
    dp[i][0]=0;
  }
  for(int i{1};i<n+1;i++)
  {
    for(int j{1};j<len+1;j++){
      if(lengthh[i-1]<=j)
      {
        dp[i][j]=max(price[i-1]+dp[i][j-lengthh[i-1]],dp[i-1][j]);
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][len];
}
int main()
{
  vector<int>lengthh{1,2,3,4};
  vector<int> price{5,6,8,8};
  int len=4;
  cout<<rodcutting(lengthh,price,len);
}
