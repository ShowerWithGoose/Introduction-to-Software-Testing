#include<stdio.h>
#include<string.h>
#include<ctype.h>
int sum(char *s);
 int main() 
   {char s[2000];
    gets(s);
	s[strlen(s)-1]='\0';
	printf("%d",sum(s)); 
	return 0; 
   } 
int sum(char *s)
   {int n=strlen(s);
    int z[n],x=0;
    char f='+';
    int y=0;
    for (int a=0;a<n;a++)
	   {if (isdigit(s[a]))
            y=y*10+(int)(s[a]-'0');
        if (!isdigit(s[a])&&s[a]!=' '||a==n-1)
		   {switch (f)
		       {case '+':
                   {z[x++]=y;
                    break;
				   }
                case '-':
                   {z[x++]=-y;
                    break;
				   }
                case '*':
                   {z[x-1]*=y;
                    break;
				   }
                default:
                    z[x-1]/=y;
               }
            f=s[a];
            y=0;
           }
       }
    int w=0;
    for (int b=0;b<x;b++)
        w+=z[b];
    return w;
   }



