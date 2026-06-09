#include <stdio.h>
int suan(int x,char p,int y)
{
	if(p=='+')
	{
	
        return x+y;
    }
   else if(p=='-')
	{
	
        return x-y;
    }
	else if(p=='*')
	{
	
        return x*y;
    }
	else if(p=='/')
	{
	
        return x/y;
    }
    
}
int dushu()
{
    int a;
    scanf("%d",&a);
    return a;
}
char dufu()
{
    char b;
    do
    {
        scanf("%c",&b);
    }while(b==' ');
    return b;
}
int check(char b1,char b2)
{

    if(b1=='*'||b1=='/')
            return 0;
    else if(b1=='+'||b1=='-')
    {
	
        if(b2=='*'||b2=='/')
            return 1;
        else
            return 0;
    }
}

int main()
{
    int j,k,l;
    char qian,hou;
    j=dushu();
    qian=dufu();
    if(qian=='=')
        printf("%d",j);
    else
    {
        k=dushu();
        hou=dufu();
        if(hou=='=')
            printf("%d",suan(j , qian,k));
        else
        {
            while(hou!='=')
            {
                l=dushu();
                if(check(qian,hou)==0)
                {
                    j=suan(j,qian,k);
                    k=l;
                    qian=hou;
                }
                else
                {
                    k=suan(k,hou,l);
 
                }
                hou=dufu();
            }
            printf("%d",suan(j,qian,k));
        }
 
    }
    return 0;
}



