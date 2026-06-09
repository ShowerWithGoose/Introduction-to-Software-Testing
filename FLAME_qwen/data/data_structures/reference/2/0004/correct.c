# include<stdio.h>
# include<ctype.h>
# include<string.h>
# include<stdlib.h>
char sym[105]={0};
int num[105]={0};
void dev(char []);
int main()
{
    char read[300]={0};
    gets(read);
    dev(read);
    int len=strlen(sym);
    for(int i=0; i<len; i++)
    {
        switch(sym[i])
        {
            case '*' :
            {
            num[i+1]=num[i+1]*num[i];
            num[i]=0;
            sym[i]='\0';
            }
            break;
            case '/' :
            {
            num[i+1]=num[i]/num[i+1];
            num[i]=0;
            sym[i]='\0';
            }
            break;
        }
    }
    int result=num[0];
    char last_sym='+';
    for(int i=0; sym[i]!='='; i++)
    {
        if(sym[i]!='\0')
        last_sym=sym[i];
        else
        sym[i]=last_sym;
        switch(sym[i])
        {
        case '+' :result+=num[i+1];
        break;
        case '-' :result-=num[i+1];
        break;
        }
    }
    printf("%d",result);
    return 0;
}
void dev(char ori[])
{
    char *p;
    p=ori;
    int j=0;
    int i=0;
    for(;ori[i]!='=';i++)
    {
        if(!isdigit(ori[i]))
        {
            if(!isspace(ori[i]))
            {
                sym[j++]=ori[i];
            }
            else;
        ori[i]='\0';
        }
        else;
    }
    ori[i]='\0';
    ori[i+1]='=';
    sym[j]='=';
    for(int i=0;*p!='=';)
    {
        if(*p!='\0')
        {
            num[i]=atoi(p);
            //printf("num[%d]=%d\nsym[%d]=%c\n",i,num[i],i,sym[i]);
            i++;
            p+=strlen(p);
        }
        else
        p++;
    }
}

