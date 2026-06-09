//
//  第二题.c
//  bk,j
//
//  Created by  on 2022/3/17.
//
#include<stdio.h>
#define MAX 11
int N;
int Mark[MAX] = {0};
char Stack[MAX];
void rank(int m, int n);
int main()
{
    scanf("%d",&N);
    rank(0,N);
    return 0;
}
void rank(int m, int n)
{
    int i;
    if( n == 0){
        Stack[m] = '\0';
        for(int j=0;j<N;j++)
        {
            printf("%c ",Stack[j]);
        }
        printf("\n");
        return;
    }
    for(i=1; i<=N; i++)
        if(Mark[i] == 0 ){
            Mark[i] = 1;
            Stack[m] = '0'+i;
            rank(m+1,n-1);
            Mark[i] = 0;
        }

}



