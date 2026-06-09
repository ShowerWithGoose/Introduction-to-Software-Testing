#include<stdio.h>
#include<math.h>
#include<string.h>
int suan(int,char,int);

int main()
{int shuzi[2];
char zifu[1];
char ddd;
int mo;
scanf(" %d",&shuzi[0]);
scanf(" %c",&zifu[0]);

if(zifu[0]!='=')
    scanf(" %d",&shuzi[1]);
while(zifu[0]!='='){
    if(zifu[0]=='*'||zifu[0]=='/'){
        shuzi[0]=suan(shuzi[0],zifu[0],shuzi[1]);
        scanf(" %c",&zifu[0]);
        if(zifu[0]!='=')
            scanf(" %d",&shuzi[1]);
    }
    else{
        scanf(" %c",&ddd);
        if(ddd=='+'||ddd=='-'||ddd=='=')
        {
            shuzi[0]=suan(shuzi[0],zifu[0],shuzi[1]);
            if(ddd=='='){
            printf("%d\n",shuzi[0]);
            return 0;
            }
            if(ddd!='=')
                {scanf(" %d",&shuzi[1]);zifu[0]=ddd;}
        }
        else if(ddd=='*'||ddd=='/')
        {scanf(" %d",&mo);
         shuzi[1]=suan(shuzi[1],ddd,mo);
        }
        else
            zifu[0]=ddd;

    }
}

printf("%d\n",shuzi[0]);
return 0;
}
int suan(int a,char hao,int b){
int jieguo;

switch(hao){
case'+':jieguo=a+b;
break;
case'-':jieguo=a-b;
break;
case'*':jieguo=a*b;
break;
case'/':jieguo=a/b;
default:
break;
}
return jieguo;

}

