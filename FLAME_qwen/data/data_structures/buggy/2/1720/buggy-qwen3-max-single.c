#include <stdio.h>
int main(void)
{
    int i,j,sto,res,sympre,temp;
    j=1;sto=-1;res=0;sympre=1;temp=0;
    char c[500];
    gets(c); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    for (i=0;c[i]-'=';i++){ // @@ [Incorrect loop condition: should be `c[i] != '='`; current condition evaluates to non-zero as long as c[i] != '=', but when c[i] == '=', it becomes 0 and stops. However, this actually works logically but is unconventional and confusing. Not the main error.]
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
            else sto/=temp; // @@ [Logic error: if previous operator was '/', and now we see '*', this incorrectly applies division instead of handling operator precedence correctly in all cases]
            sympre=3;
            temp=0;
            break;
        case '/':
            if(sto==-1)sto=temp;
            else if (sympre==3)sto*=temp;
            else sto/=temp; // @@ [Same logic error as above: mishandles sequence of mixed * and / operators]
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
    printf("%d\n",res);1 // @@ [Syntax error: stray `1` after printf statement causes compilation failure]
    return 0;
}