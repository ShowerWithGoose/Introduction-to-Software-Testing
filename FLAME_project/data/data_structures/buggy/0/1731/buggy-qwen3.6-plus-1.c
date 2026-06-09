#include<stdio.h>
#include<string.h>
char s[1000],x[2000];
int main()
{ int l,i=0,j=0;
  gets(s);
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
        i++; // @@ The loop increment `i++` in the `for` statement will execute after this block. Since we want to skip the character after '-' (s[i+1]), we should only increment `i` once here to account for the current iteration's increment, or adjust logic. However, the bigger issue is below.
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++;
        j++;
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++;
        j++; 
        }
      else // @@ This `else` is only associated with the last `if` (lowercase check). If the input is uppercase (e.g., B-F), the first two `if`s might execute (or not), but if the lowercase `if` fails, this `else` executes, appending the '-' again or handling it incorrectly. It should be an `else if` chain or a flag-based approach to ensure only one case is handled. Specifically, if an expansion happened in the digit or uppercase block, this `else` still runs if the lowercase condition is false, leading to duplicate or incorrect output.
      { x[j]=s[i];
          j++;    
      }    
      }
  }
  puts(x);
  return 0;
}