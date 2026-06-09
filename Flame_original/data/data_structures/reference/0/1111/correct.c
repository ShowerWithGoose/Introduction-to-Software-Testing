#include<stdio.h>
#include<math.h>
int main()
{
   char a,b,c;
    int i,flag;
   a=b=0;flag=0;
   while((c=getchar())!=EOF)
   {
    if(flag)
    {
       flag--;
       if((a<c)&&((a>='A'&&'Z'>=c)||(a>='a'&&'z'>=c)||(a>='0'&&'9'>=c)))
      { for(i=1;a+i<c;i++)
           printf("%c",a+i);
        }
        else printf("-");
    }
      if(c!='-')
           printf("%c",c);
           else  flag++ ;

    a=b;b=c;
    }
    
    return 0;
}

