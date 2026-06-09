#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n;
int s[10]={0};
char jilu[11];
void putsingle(int place,int rest)
{
if(rest==0)
{
    jilu[place]='\0';
    for(int u=0;u<n;u++)
    {
            if(u!=n-1){
            printf("%c ",jilu[u]);
            }
            else printf("%c\n",jilu[u]);

}
            return 0;
}
for(int i=1;i<=n;i++)
{
    if(s[i]==0)
    {
        s[i]=1;
        jilu[place]=i+'0';
        putsingle(place+1,rest-1);
        s[i]=0;
    }
}
}


int main()
{

  scanf("%d",&n);
  putsingle(0,n);
  return 0;
}

