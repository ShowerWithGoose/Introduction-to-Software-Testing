#include <stdio.h>
int main(void)
{
    int i,j,sto,res,sympre,temp;
    j=1;sto=-1;res=0;sympre=1;temp=0;
    char c[500];
    gets(c);
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
            else sto/=temp; // @@ [Error: When sympre==4 (division), the previous operator should be division, but this else branch incorrectly uses division for all other cases, including when sympre==2 (subtraction) or sympre==1 (addition), leading to wrong precedence handling. For example, "1-2*3" would incorrectly compute 1-(2/3) instead of 1-(2*3).]
            sympre=3;
            temp=0;
            break;
        case '/':
            if(sto==-1)sto=temp;
            else if (sympre==3)sto*=temp;
            else sto/=temp; // @@ [Error: Same logic error as in '*': when sympre==3 (multiplication), it should multiply, but when sympre==1 or 2, it incorrectly divides. This breaks operator precedence, e.g., "1+2/3" would compute 1+(2/3) correctly by chance, but "1-2/3" would compute 1-(2/3) instead of 1-(2/3) which is actually correct here, but the logic is inconsistent and fails for cases like "1*2/3" where sympre==3 leads to multiplication instead of division.]
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
    printf("%d\n",res);1 // @@ [Error: Extra '1' after the printf statement, which is a syntax error and will cause compilation failure.]
    return 0;
}