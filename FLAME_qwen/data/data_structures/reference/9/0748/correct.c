#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[150][2],b[150][2];
    int i=0,j=0,k=0,len=1,lenmax=0,num=0,temp1=0,temp2=0,temp3,temp4;
    int x,y;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&a[i][0],&a[i][1],&b[i][0],&b[i][1]);
    }
    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(a[i][0]>a[j][0]){
                temp1=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=temp1;
                temp2=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=temp2;
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
    lenmax=0;
    for(i=0;i<num;i++){
        k=i;
        len=1;
        for(j=i+1;j<num;j++){
            if(b[k][0]==a[j][0]&&b[k][1]==a[j][1]){
                len++;
                k=j;
            }
        }
        if(len>lenmax){
            lenmax=len;
            x=a[i][0];
            y=a[i][1];
        }
    }
    printf("%d %d %d",lenmax,x,y);
    return 0;
}



