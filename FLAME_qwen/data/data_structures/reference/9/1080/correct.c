//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
int book[100];
int main(int argc, char *argv[])
{int n,flag,a[100][4],x1,y1,x2,y2,ans=0,p=0,x3,y3;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for(int i=0;i<n;i++){
        flag=1;x1=a[i][0];y1=a[i][1];x2=a[i][2];y2=a[i][3];
        book[i]=1;p=1;
        while(flag==1){
            for(int j=0;j<n;j++){
                if(x2==a[j][0]&&y2==a[j][1]&&book[j]==0){
                    x2=a[j][2];p++;book[j]=1;y2=a[j][3];
                    flag=1;break;
                }
                flag=0;
            }
            }
        for(int l=0;l<n;l++)
            book[l]=0;
        if(p>ans){ans=p;
            x3=x1;y3=y1;}    }
    printf("%d %d %d",ans,x3,y3);
  return 0;
}

