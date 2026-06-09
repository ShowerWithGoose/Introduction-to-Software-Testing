#include <stdio.h>
#include <string.h>
int main() 
{
	char shu[110];
	scanf("%s",shu);
    int i,j;
    char k[200]={0};
	for(i=0;i<strlen(shu);i++)
	{
		if(shu[i]=='-'&&i!=0)
		{
			if(shu[i-1]<shu[i+1]&&shu[i-1]>47&&shu[i-1]<58&&shu[i+1]>47&&shu[i+1]<58)
			k[i]='1';
            if(shu[i-1]<shu[i+1]&&shu[i-1]>64&&shu[i-1]<91&&shu[i+1]>64&&shu[i+1]<91)
			k[i]='1';
            if(shu[i-1]<shu[i+1]&&shu[i-1]>96&&shu[i-1]<123&&shu[i+1]>96&&shu[i+1]<123)
			k[i]='1';
		
		}
		
   }
       for(i=0;i<strlen(shu);i++)
   	   {
   	   	   if(k[i]=='1')
				 {
   	   	           for(j=1;j<shu[i+1]-shu[i-1];j++)
   	   	   {
   	   	   	   printf("%c",shu[i-1]+j);
		   }
		   i++;
	   }
	   printf("%c",shu[i]);
   }
    
    return 0;
}



