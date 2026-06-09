#include<stdio.h>
int n[100];
int main()
{
    int i=0,ans=0,a=0,b=0,flag=0;
    char c;
    scanf("%d",&a);
    while((c=getchar())!='='){
        if(c==' ')continue;
        if(c=='+'||c=='-'){
            ans+=a;
            scanf("%d",&a);
            if(c=='-')
                a=-a;
        }
        else{
            scanf("%d",&b);
            if(c=='*')
                a*=b;
            else
                a/=b;
        }
    }
    ans+=a;
    printf("%d",ans);
    return 0;
}

