#include <bits/stdc++.h>
using namespace std;
bool isplaindrome(string s,int i,int j)
{
  while(i<j)
  {
    if(s[i]!=s[j])
    {
      return false;
    }
    i++;
    j--;
  }
  return true;

}
 int dp[1001][1001];
int solve(string s,int i,int j)
{

  if(i>=j){
    return 0;
  }
  if(isplaindrome(s,i,j))
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }
  int ans=INT_MAX;
  for(int k=i;k<=j-1;k++)
  {
    int left{},right{};
    if(dp[i][k]!=-1)
    {
      left=dp[i][k];
    }else
    {
      left=solve(s,i,k);
      dp[i][k]=left;
    }
    if(dp[k+1][j]!=-1)
    {
      right=dp[k+1][j];
    }
    else
    {
      right=solve(s,k+1,j);
      dp[k+1][j]=right;
    }
    int temp=left+right+1;
    ans=min(ans,temp);
  }
  return dp[i][j]=ans;

}


int main()
{
  string s;
  cin>>s;
  int i=0;
  int j=s.size()-1;
  memset(dp,-1,sizeof(dp));
  cout<<solve(s,i,j);

}
