#include <bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int m,int n)
{
  int dp[m+1][n+1];
  for(int i{};i<m+1;i++){
    for(int j{};j<n+1;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
    }
  }
 
  //the main condition here is that we have to break the continuation of the substring when it either of the substring part doesnot matches with the rest
  // of the continuation of the substring
  
  for(int i{1};i<m+1;i++)
  {
    for(int j{1};j<n+1;j++){
      if(x[i-1]==y[j-1])
      {
        dp[i][j]=1+dp[i-1][j-1];
      }
      else
      {
        dp[i][j]=0;
      }
    }
  }
  return dp[m][n];
}
int main()
{
  string x{},y{};
  cin>>x>>y;
  int m=x.size();
  int n=y.size();
  cout<<lcs(x,y,m,n);
}
