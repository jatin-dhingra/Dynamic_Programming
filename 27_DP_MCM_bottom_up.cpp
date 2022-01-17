#include <bits/stdc++.h>
using namespace std;
static int dp[1001][1001];
int mcm(vector<int>arr,int i,int j)
{
  if(i>=j)
  {
    return 0;

  }
  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }
  int ans=INT_MAX;
  for(int k=i;k<j;k++)
  {
    int temp{};
    temp=mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[j]*arr[k]);
    ans=min(temp,ans);

  }
  return dp[i][j]=ans;

}

int main()
{
  memset(dp,-1,sizeof(dp));
  vector<int>arr{10,30,40,50};
  int i=1;
  int j=arr.size()-1;
  cout<<mcm(arr,i,j);
}
