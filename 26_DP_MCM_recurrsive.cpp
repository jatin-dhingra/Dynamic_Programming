#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int>arr,int i,int j)
{
  if(i>=j){
    return 0;

  }
  int ans=INT_MAX;
  for(int k=i;k<=j-1;k++)
  {
    int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
    if(temp<ans)
    {
      ans=temp;
    }
  }
  return ans;

}

int main()
{
   vector<int>arr{40,10,30,10,30};
  int i=1;
  int j=arr.size()-1;
  cout<<mcm(arr,i,j);
}
