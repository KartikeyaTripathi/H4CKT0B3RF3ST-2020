#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
int maxi=INT_MIN;
int knapsack(int N,int C,int *weight,int *prices)
{
    if(N==0 || C==0)
    {
        return 0;
    }
    int with,without;
    with=without=INT_MIN;
    if(weight[N-1]<=C)
     with=prices[N-1] + knapsack(N-1,C-weight[N-1],weight,prices);
     without=knapsack(N-1,C,weight,prices);
    maxi=max(with,without);
    return maxi;

}
int main()
{
    int weight[]={1,2,3,5};
    int prices[]={40,20,30,100};
    int N=4;
    int C=7;
    int ans=knapsack(N,C,weight,prices);
     cout<<ans<<endl;
    return 0;
}
