#include <bits/stdc++.h>
using namespace std;
int knapSack(int val[],int wt[],int W,int n)
{
	if (n == 0 || W == 0)
		return 0;

  if(wt[n-1]<=W)
		return max(val[n-1]+knapSack(val,wt,W-wt[n-1],n-1),knapSack(val,wt,W,n-1));


	else if (wt[n - 1] > W)
		return knapSack(val,wt,W,n-1);
}

int main()
{
	
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n=3;
	cout << knapSack(val,wt,W,n);

}
