#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

int main()
{
    int num[100],i=0,d,cnt=0;
    char op[100],opp;

    scanf("%d %c",&num[i],&op[i]);
    while(op[i]!='=')
    {
        scanf("%d %c",&d,&opp);
        if(op[i]=='*'){
            num[i]*=d;
            op[i]=opp;
        }
        else if(op[i]=='/'){
            num[i]/=d;
            op[i]=opp;
        }
        else{
            i=i+1;
            num[i]=d;
            op[i]=opp;
        }
    }
    cnt=num[0];
    for(i=0;op[i]!='=';i++)
    {
        if(op[i]=='+')
            cnt+=num[i+1];
        if(op[i]=='-')
            cnt-=num[i+1];

    }
    printf("%d\n",cnt);

    return 0;
}



