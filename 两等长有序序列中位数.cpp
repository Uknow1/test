#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
void prepart(int &s,int &t)
{
    int m=(s+t)/2;
    t=m;
}

void postpart(int &s,int &t)
{
    int m=(s+t)/2;
    if((s+t)%2==0)
        s=m;
    else
        s=m+1;
}
int midnum(int a[],int s1,int t1,int b[],int s2,int t2)
{
    if(s1==t1&&s2==t2)//两个序列中都只剩一个元素，返回较小那个
        return a[s1]<b[s2]?a[s1]:b[s2];
    else{
            int mid1=s1+(t1-s1)/2;
            int mid2=s2+(t2-s2)/2;
        if(a[mid1]==b[mid2])
            return a[mid1];
        if(a[mid1]<b[mid2])
        {

            prepart(s2,t2);
            postpart(s1,t1);
            return midnum(a,s1,t1,b,s2,t2);
        }
        if(a[mid1]>b[mid2])
        {
            prepart(s1,t1);
            postpart(s2,t2);
            return midnum(a,s1,t1,b,s2,t2);
        }

    }
}
int main()
{
    int n;
    cin>>n;
    int a[maxn];
    int b[maxn];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    printf("%d",midnum(a,0,n-1,b,0,n-1));
}
