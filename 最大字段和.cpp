#include<bits/stdc++.h>
using namespace std;
int maxSubSum(int a[],int left,int right)
{

    int maxleftsum,maxrightsum;
    if(left==right)
    {
        if(a[left]>0)
            return a[left];
        else
            return 0;
    }
    int mid=left+(right-left)/2;
    maxleftsum=maxSubSum(a,left,mid);
    maxrightsum=maxSubSum(a,mid+1,right);
    int maxleftbordersum=0;
    int leftbordersum=0;
    for(int i=mid;i>=left;i--)
    {
        leftbordersum+=a[i];
        if(leftbordersum>maxleftbordersum)
            maxleftbordersum=leftbordersum;
    }
    int maxrightbordersum=0;
    int rightbordersum=0;
     for(int i=mid+1;i<=right;i++)
    {
        rightbordersum+=a[i];
        if(rightbordersum>maxrightbordersum)
            maxrightbordersum=rightbordersum;
    }
    int sum=maxleftbordersum+maxrightbordersum;
    if(maxleftsum>sum)sum=maxleftsum;
    if(sum<maxrightsum)sum=maxrightsum;
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
         cin>>a[i];

    cout<<maxSubSum(a,0,n-1);
}

