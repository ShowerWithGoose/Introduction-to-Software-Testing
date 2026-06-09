#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define Max 100

int main()
{int z[100];
int p,n,top;
top=-1;
scanf("%d",&p);
while(p!=-1){


if(p==1){
    scanf("%d",&n);
    if(top!=Max-1)
      z[++top]=n;
    else if(top==Max-1)
    printf("error ");
}
if(p==0){
   if(top!=-1)
     printf("%d ",z[top--]);
   else if(top==-1)
     printf("error ");
}
scanf("%d",&p);
}

return 0;
}


