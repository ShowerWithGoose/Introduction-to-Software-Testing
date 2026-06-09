#include<stdio.h>
#include<string.h>
char s[1000],x[2000];
int main()
{ int l,i=0,j=0;
  gets(s); // @@ gets() is removed in C11 standard, causing compilation errors; use fgets() or scanf().
  l=strlen(s);
  for(i=0;i<l;i++)
  {
      if(s[i]!='-')
      { x[j]=s[i];
        j++;}
      else
    { if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }
        i++;
        i++; // @@ Incorrectly increments i twice, skipping the character after '-'; should only increment once.
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Should be 'else if' to prevent falling through to the final else block.
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++;
        j++;
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Should be 'else if' for the same reason as above.
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++;
        j++; 
        }
      else
      { x[j]=s[i];
          j++;    
      }    
      }
  }
  puts(x); // @@ Array x is not null-terminated before printing, which may cause undefined behavior or garbage output.
  return 0;
}