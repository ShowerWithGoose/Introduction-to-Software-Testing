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
    { if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ [Potential out-of-bounds access if '-' is at start or end. Also, separate if without else if causes multiple condition checks and incorrect fall-through to else.]
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }
        i++; // @@ [Double increment is incorrect; should increment only once. With the for-loop increment, it will skip an extra character.]
        i++; // @@ [Same as above.]
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [Potential out-of-bounds access. Also, separate if causes all three conditions to be checked, and the else attached to the last if will execute incorrectly for digits and uppercase.]
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++;
        j++;
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [Potential out-of-bounds access. Same separate-if issue.]
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++;
        j++; 
        }
      else // @@ [This else is only attached to the last if (lowercase). When the first two conditions are true, the else still runs, incorrectly adding '-' to output.]
      { x[j]=s[i];
          j++;    
      }    
      }
  }
  puts(x); // @@ [Missing null terminator for x array. This may cause puts to print garbage or crash.]
  return 0;
}