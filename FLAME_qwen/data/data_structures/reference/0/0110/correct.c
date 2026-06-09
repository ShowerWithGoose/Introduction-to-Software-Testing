#include<stdio.h>
#include<ctype.h> 
#include<string.h>
#define SCALE 1001

int judge(char a,char b)
{
    if (a >= b) return 0;
    if (isdigit(a) && isdigit(b)) return 1;
    if (isupper(a) && isupper(b)) return 1;
    if (islower(a) && islower(b)) return 1;
    return 0;
}

int main(){
    char origin[SCALE];
    int len;
    
    fgets(origin,SCALE,stdin);
    len = strlen(origin);
    //origin[len] = '\0';

    for (int i=0;i<len;i++)
      if (origin[i] == '-')
      {
        if(judge(origin[i-1],origin[i+1])){
            for (char j=origin[i-1]+1;j<=origin[i+1];j++)
              printf("%c",j);
            i++;
        }
        else printf("-");  
      }
      else printf("%c",origin[i]);

    return 0;
} /*?*/

