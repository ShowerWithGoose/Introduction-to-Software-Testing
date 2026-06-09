#include <stdio.h>
#include <string.h>
int ex(char x,char y); 
int main()
   {char s[500];
    char *a=NULL,*b=NULL;
    scanf("%s",s);
    a=strchr(s,'-');
    if (a==NULL)
        printf("%s",s);
    else
       {for (a=s;(b=strchr(a,'-'))!=NULL&&(b+1)!=NULL; )
           {if (ex(*(b-1),*(b+1))==1)
               {for (int c=0;c<b-a;c++)
                    printf("%c",*(a+c));
			    for (int d=1;d<=*(b+1)-*(b-1);d++)
			        printf("%c",*(b-1)+d);
			   }
			else
			   {for (int e=0;e<b-a+2;e++)
			        printf("%c",*(a+e));
			   }
			a=b+2;
		   }
		for (int f=0;f<strlen(s)-(a-s);f++)
		    printf("%c",*(a+f));
	   }
	return 0;
   }

int ex(char x,char y)
   {if (x>='a'&&x<='z'&&y>='a'&&y<='z'&&y-x>0)
        return 1;
    else if (x>='A'&&x<='Z'&&y>='A'&&y<='Z'&&y-x>0)
        return 1;
    else if (x>='0'&&x<='9'&&y>='0'&&y<='9'&&y-x>0)
        return 1;
    else
        return 0;
   }



