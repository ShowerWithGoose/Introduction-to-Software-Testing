#include<stdio.h>
int count1(int i1,char j1,int i2)
{
    if(j1=='*')
        i1*=i2;
    else
        i1/=i2;
    return i1;
}
int count2(int i1,char j1,int i2)
{
    if(j1=='+')
        i1+=i2;
    else
        i1-=i2;
    return i1;
}
int main()
{int i1,i2,i3;
char j1,j2,j3;
scanf("%d %c %d %c",&i1,&j1,&i2,&j2);
while(~scanf("%d %c",&i3,&j3))
{if(j1=='*'||j1=='/')
{i1=count1(i1,j1,i2);
j1=j2;
i2=i3;
j2=j3;
}
else if(j2=='+'||j2=='-')
{i1=count2(i1,j1,i2);
j1=j2;
i2=i3;
j2=j3;
}
else
{
i2=count1(i2,j2,i3);
j2=j3;
}
}
if(j1=='*'||j1=='/')
{
    if(j1=='*')
        i1*=i2;
    else
        i1/=i2;
}
else{
    if(j1=='+')
        i1+=i2;
    else
        i1-=i2;
}
printf("%d",i1);
return 0;
}


