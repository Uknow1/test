
#include<bits/stdc++.h>
using namespace std;
#define MAX 1025
int k;
int x,y;
int board[MAX][MAX];
int tile=1;
void chessboard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)return;
    int t=tile++;
    int s=size/2;
    if(dr<tr+s&&dc<tc+s)//×óÉÏ½Ç
    {
        chessboard(tr,tc,dr,dc,s);
    }
    else{
        board[tr+s-1][tc+s-1]=t;
        chessboard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)//ÓÒÉÏ½Ç
    {
        chessboard(tr,tc+s,dr,dc,s);
    }
    else{
        board[tr+s-1][tc+s]=t;
        chessboard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc>=tc+s)//ÓÒÏÂ½Ç
    {
        chessboard(tr+s,tc+s,dr,dc,s);
    }
    else{
        board[tr+s][tc+s]=t;
        chessboard(tr+s,tc+s,tr+s,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)//×óÏÂ½Ç
    {
        chessboard(tr+s,tc,dr,dc,s);
    }
    else{
        board[tr+s][tc+s-1]=t;
        chessboard(tr+s,tc,tr+s,tc+s-1,s);
    }
}

int main(){

    cin>>x>>y>>k;
    chessboard(0,0,x-1,y-1,k);
for(int i=0;i<k;i++)
{
    for(int j=0;j<k;j++)
    {
        printf("%4d",board[i][j]);
    }
               printf("\n");
}
               return 0;
}
