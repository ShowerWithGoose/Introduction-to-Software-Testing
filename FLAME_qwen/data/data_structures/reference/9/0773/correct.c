#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a,b)   do{a^=b;b^=a;a^=b;}while(0)
struct In
{
    int x1,y1;//start
    int x2,y2;//end
    int len;
};
int main()
{
    struct In Coordinate[2000],arr[2000];
    int n,maxn=-1,res=0,flag=0,k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&Coordinate[i].x1,&Coordinate[i].y1,&Coordinate[i].x2,&Coordinate[i].y2);
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(Coordinate[i].x1==Coordinate[j].x2&&Coordinate[i].y1==Coordinate[j].y2)
            {
                flag=1;
                break;
            }
        }
        if(flag==0){
            arr[k].x1=Coordinate[i].x1;
            arr[k].x2=Coordinate[i].x2;
            arr[k].y1=Coordinate[i].y1;
            arr[k++].y2=Coordinate[i].y2;
        }
    }
    for(int i=0;i<k;i++){
        arr[i].len=1;
        for(int j=0;j<n;j++){
            if(Coordinate[j].x1==arr[i].x2&&Coordinate[j].y1==arr[i].y2)
            {
                arr[i].x2=Coordinate[j].x2;
                arr[i].y2=Coordinate[j].y2;
                arr[i].len++;
                j=-1;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        if(maxn<arr[i].len){
            maxn=arr[i].len;
            res=i;
        }
    }
    printf("%d %d %d\n",maxn, arr[res].x1, arr[res].y1);
}
