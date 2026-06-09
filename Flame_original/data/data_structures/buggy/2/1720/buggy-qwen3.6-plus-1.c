#include <stdio.h>
int main(void)
{
    int i,j,sto,res,sympre,temp;
    j=1;sto=-1;res=0;sympre=1;temp=0;
    char c[500];
    gets(c); // @@ `gets` is removed in the C11 standard and deprecated in earlier versions, causing a compilation error in modern strict environments. Use `fgets(c, 500, stdin);` instead.
    for (i=0;c[i]-'=';i++){
        switch(c[i])
        {
        case '+':
            if (sympre==3)sto*=temp;
            else if (sympre==4)sto/=temp;
            else sto=temp;
            res+=j*sto;
            j=1;
            sto=-1;
            sympre=1;
            temp=0;
            break;
        case '-':
            if (sympre==3)sto*=temp;
            else if (sympre==4)sto/=temp;
            else sto=temp;
            res+=j*sto;
            j=-1;
            sto=-1;
            sympre=2;
            temp=0;
            break;
        case '*':
            if(sto==-1)sto=temp;
            else if (sympre==3)sto*=temp;
            else sto/=temp;
            sympre=3;
            temp=0;
            break;
        case '/':
            if(sto==-1)sto=temp;
            else if (sympre==3)sto*=temp;
            else sto/=temp;
            sympre=4;
            temp=0;
            break;
        case ' ':
            break;
        default:
            temp=temp*10+c[i]-'0';
            break;
        }
    }
    if (sympre==3)sto*=temp;
    else if (sympre==4)sto/=temp;
    else sto=temp;
    res+=j*sto;
    printf("%d\n",res);1 // @@ Stray `1` after the semicolon is a typo. It should be removed to avoid unintended expression statements and potential compilation warnings/errors in strict modes.
    return 0;
}