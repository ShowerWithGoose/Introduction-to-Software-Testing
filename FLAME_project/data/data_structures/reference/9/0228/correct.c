#include <stdio.h>
#include <stdlib.h>

struct line{
    int a,b,c,d;
}line[200],temp;
int main()
{   int i,j,n,max=0,m,length=1,x,y,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].a,&line[i].b,&line[i].c,&line[i].d);
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=i+1;j<n;j++){
            if(line[j].a<line[i].a){
                temp=line[i];
                line[i]=line[j];
                line[j]=temp;
                flag=1;
            }
        }
        if(flag=0)
            break;
    }
    for(i=0;i<n;i++){
        m=i;
        length=1;
        for(j=i+1;j<n;j++){
            if(line[j].a==line[m].c&&line[j].b==line[m].d){
                length++;
                m=j;
            }
        }
        if(length>max){
            max=length;
            x=line[i].a;
            y=line[i].b;
        }
    }
    printf("%d %d %d",max,x,y);
    return 0;
}

