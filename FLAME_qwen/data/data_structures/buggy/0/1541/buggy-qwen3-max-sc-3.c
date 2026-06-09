#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; also, the program does not handle cases where '-' appears at the start or end of string, leading to out-of-bounds access]
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ [Accessing ch[i-1] when i=0 (i.e., '-' at start) causes undefined behavior due to negative index; similarly, accessing ch[i+1] when '-' is at the last character reads beyond string end]
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++) // @@ [Loop variable j is of type char; if ch[i+1] is much larger than ch[i-1], this loop may overflow or behave unexpectedly, though less likely the main issue here]
    printf("%c",j);
    }
      } 
 else // @@ [This 'else' is incorrectly aligned—it belongs to the 'if(ch[i]=='-')' but is placed inside its block, causing logic error: non-'-' characters are only printed when inside a '-' block that fails conditions]
 printf("%c", ch[i]);
}
    return 0;
}