#include<bits/stdc++.h>
using namespace std;
//���ֲ���(�ظ����֣���������)
int solve(int *a ,int n,int x){

int left=0;
int right=n;//����n-1
while(left<right)
{
    int mid=left+(right-left)/2;
    if(a[mid]>=x)right=mid;
    else left=mid+1;

}
return left;
}


