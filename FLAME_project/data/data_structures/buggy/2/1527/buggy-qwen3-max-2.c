#include <stdio.h>
#include <string.h>
char array[6000]={0};
int zhengshu(int *a)
{
    int x=0,y=*a;
    for(;array[y]>='0'&&array[y]<='9';y++)
        x=10*x+array[y]-'0';
    *a=y;
    return x;
}
int chengchu(int *a)
{
    int x1=1,y1=*a;
    if(array[y1]=='-')    x1=-1; // @@ [This handles unary minus incorrectly. The function assumes the first token is always positive or has a leading '-', but in expressions like "24 / 4...", there's no leading '-', so this causes incorrect sign handling when called from main(). Also, after consuming '-', it doesn't check if next char is digit, leading to potential misparse.]
    *a=*a+1;
    x1*=zhengshu(a);
    while(array[*a]=='*'||array[*a]=='/')
    {
        switch(array[*a])
        {
            case'*':*a=*a+1;x1*=zhengshu(a);break;
            case'/':*a=*a+1;x1/=zhengshu(a);break;
        }
    }
    return x1;
}
int main()
{
    gets(array);
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b); // @@ [Initial term is parsed correctly only if it's positive. However, the logic in chengchu() assumes that every term starts with optional '-', which breaks the parsing of subsequent terms that are positive. Moreover, the main loop adds results of chengchu(), but chengchu() already includes sign handling, causing double interpretation of operators.]
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ [The '+' here assumes all following terms are added, but subtraction should subtract. The program fails to account for '-' as a binary operator between terms. Instead, it tries to handle sign inside chengchu(), which leads to incorrect parsing of expressions like "... - 50 ...", because the '-' is consumed as part of the next term's sign rather than as an operator. This causes the entire expression evaluation to be wrong.]
        }
    printf("%d",sum);
    return 0;
}