#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int num[150][2],b[150][2];
    int i=0,j=0,k=0,len=1,key=0,n=0,temp1=0,temp2=0,temp3,temp4;
    int x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&num[i][0],&num[i][1],&b[i][0],&b[i][1]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(num[i][0]>num[j][0]){
                temp1=num[i][0];
                num[i][0]=num[j][0];
                num[j][0]=temp1;
                temp2=num[i][1];
                num[i][1]=num[j][1];
                num[j][1]=temp2;
                temp3=b[i][0];
                b[i][0]=b[j][0];
                b[j][0]=temp3;
                temp4=b[i][1];
                b[i][1]=b[j][1];
                b[j][1]=temp4;
            }
            else
                continue;
        }
    }
    key=0;
    for(i=0;i<n;i++){
        k=i;
        len=1;
        for(j=i+1;j<n;j++){
            if(b[k][0]==num[j][0]&&b[k][1]==num[j][1]){
                len++;
                k=j;
            }
        }
        if(len>key){
            key=len;
            x=num[i][0];
            y=num[i][1];
        }
    }
    printf("%d %d %d",key,x,y);
    return 0;
}



