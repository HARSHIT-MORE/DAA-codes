#include<iostream>
using namespace std;
const int N=2e5+10;
int wt[105],val[105];

int dp[105][100005];

int func(int index,int wt_left){
	if(wt_left==0) return 0;
	if(index<0) return 0;

    if(dp[index][wt_left]!=-1) return dp[index][wt_left];
    
	int ans=func(index-1,wt_left);//not choose

    if(wt_left-wt[index]>=0)
	ans=max(ans,func(index-1,wt_left-wt[index])+val[index]);//if choose
    
    return dp[index][wt_left]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n,w;//no of item , capacity of bag
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	cout<<func(n-1,w);
}