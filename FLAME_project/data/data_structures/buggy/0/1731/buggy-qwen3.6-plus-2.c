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
        i++; // @@ The loop increment `i++` in the `for` statement will execute after this block. Since `i` is currently at the index of '-', adding 2 here moves `i` to `index_of('-') + 2`. The subsequent `for` loop increment adds 1, resulting in `i` becoming `index_of('-') + 3`. This skips the character immediately following the expanded range (e.g., 'B' in "a-uB-F"). It should be `i+=2` combined with logic to handle the loop increment correctly, or simply `i++` here and let the loop handle the next step, but typically we want to skip the end char of the range too. Actually, standard logic: if we process `start-end`, we consume `start`, `-`, `end`. Current `i` is at `-`. We need to skip `end`. So `i` should become `index_of_end`. The loop will then increment to `index_of_end + 1`. Here `i` is index of `-`. `s[i+1]` is end. We want next iteration to start after end. So `i` should be `i+1` (pointing to end) so that loop increment makes it `end+1`. Or `i+=2` (pointing to after end) and use `continue` or adjust loop. The current code does `i++; i++;` making `i` point to `after_end`. Then loop `i++` makes it `after_end+1`. This skips one valid character.
        j++;
       }
      if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++;
         x[j]=x[j-1]+1;
          }    
        i++; // @@ Similar logic error. If this `if` executes, it increments `i` once. The loop increment adds another. Total +2 from original `-` position. This lands on `after_end`. Next loop iteration starts at `after_end+1`. Skips one character.
        j++;
        }
      if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
       { x[j]=s[i-1]+1;
       while(x[j]!=s[i+1])
         { j++; 
         x[j]=x[j-1]+1;
          }
        i++; // @@ Similar logic error. Increments `i` once. Loop increment adds another. Total +2 from original `-` position. Lands on `after_end`. Next loop iteration starts at `after_end+1`. Skips one character.
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