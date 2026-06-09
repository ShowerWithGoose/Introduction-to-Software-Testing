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
            else sto/=temp; // @@ Error: When sympre==4, division should be performed, but the condition is missing; also, the logic for handling consecutive * and / is incorrect, leading to wrong operator precedence.
            sympre=3;
            temp=0;
            break;
        case '/':
            if(sto==-1)sto=temp;
            else if (sympre==3)sto*=temp;
            else sto/=temp; // @@ Error: Same issue as above; when sympre==4, division should be performed, but the condition is missing; also, the logic for handling consecutive * and / is incorrect.
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
    printf("%d\n",res);1 // @@ Error: Extra '1' after the printf statement, which is a syntax error and will cause compilation failure.
    return 0;
}