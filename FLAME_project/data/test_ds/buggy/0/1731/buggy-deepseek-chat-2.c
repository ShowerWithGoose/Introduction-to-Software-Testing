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
        i++; // @@ [Incrementing i twice skips the character after the expansion, but the logic is flawed; it should only increment i once to skip the '-' and the next character, but the while loop already handles the expansion, and the extra i++ causes the loop to skip the character after the expansion symbol incorrectly, leading to missing output or extra characters.]
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++;
        j++; // @@ [Missing an extra i++ here; the code should increment i twice (once for the '-' and once for the next character) to skip the processed expansion, but it only increments i once, causing the loop to reprocess the character after the expansion symbol, leading to duplicate output.]
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++;
        j++; // @@ [Same issue as above: missing an extra i++ to skip the character after the expansion, causing it to be output again later.]
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