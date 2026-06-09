#include<stdio.h>
#include<string.h>
char s[1000],x[2000];
int main()
{ int l,i=0,j=0;
  gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
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
        i++; // @@ [Double increment of 'i' skips two characters after '-', but only one (the next char) should be skipped; also causes out-of-bounds risk]
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [This 'if' should be 'else if'; otherwise, multiple expansions may be attempted on same '-']
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++; // @@ [Incrementing 'i' here without checking bounds; also inconsistent handling vs digit case]
        j++;
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [This 'if' should be 'else if'; leads to incorrect behavior when multiple conditions could match]
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++; // @@ [Incrementing 'i' here but not consistently across cases; also may skip needed characters or cause index errors]
        j++; 
        }
      else
      { x[j]=s[i];
          j++;    
      }    
      }
  }
  puts(x);
  return 0;
}