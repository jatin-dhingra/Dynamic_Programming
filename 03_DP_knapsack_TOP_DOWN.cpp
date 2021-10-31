// t[n][w]=max(val[n-1]+t[n-1][w-wt[n-1]],t[n-1][w]);
// t[n][w]=t[n-1][w];
#include <bits/stdc++.h>
using namespace std;

int knapSack(int val[],int wt[],int w,int n)
{
  int a=101;
  int b=101;
  int dp[a+1][b+1];
  for(int i{};i<a+1;i++){
    for(int j{};j<b+1;j++){
      if(i==0|| j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i=1;i<a+1;i++)
  {
    for(int j=1;j<b+1;j++)
    {
      if(wt[i-1]<=j)
      {
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }
      else if(wt[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][w];

}

int main()
{
  int val[] = { 60, 100, 120 };
  int wt[] = { 10, 20, 30 };
  int w = 50;
  int n=3;
  cout<<knapSack(val,wt,w,n);
}
