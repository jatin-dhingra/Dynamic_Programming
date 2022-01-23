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
int solve(string s,int i,int j)
{
  if(i>=j){
    return 0;
  }
  if(isplaindrome(s,i,j))
  {
    return 0;
  }
  int ans=INT_MAX;
  for(int k=i;k<=j-1;k++)
  {
    int temp=solve(s,i,k)+solve(s,k+1,j)+1;
    ans=min(ans,temp);
  }
  return ans;

}


int main()
{
  string s;
  cin>>s;
  int i=0;
  int j=s.size()-1;
  cout<<solve(s,i,j);

}
