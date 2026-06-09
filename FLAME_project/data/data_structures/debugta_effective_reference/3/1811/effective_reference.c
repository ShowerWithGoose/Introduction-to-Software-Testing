#include<stdio.h>
#include<string.h>
char shu[2000],num[2000];
int main ()
{
     
     int len=0,i=0,j=0,pos=0,e_num=0,m=0;
     gets(shu);
     len=strlen(shu);
     if(shu[1]=='.'&&shu[0]=='0'){
     	   for(i=2;i<len;i++)
            {
                if(shu[i]!='0')
                {
                    j=i;
                    break;
                }
            }
            num[0]=shu[j];
            if(j!=(len-1))
            {
                num[1]='.';
                for(i=j+1,m=2;i<len;i++,m++)
                    num[m]=shu[i];
            }
            else
                m=1;
            for(i=0;i<m;i++)
                printf("%c",num[i]);
            printf("e-%d",j-1);
        }
	
	 
	 else if (num[1]=='.'&&num[0]!='0'){
	  printf("%s" ,num);
	  printf("e0");			
	}
	
	 else {
	 	for(i=0;i<len;i++){
	 		if(shu[i]=='.'){
	 			pos=i;
	 			break;
			 }
		 }
	 	num[0]=shu[0];
	 	num[1]='.';
	 	for(i=1,j=2;i<len;i++){
	 		if(shu[i]!='.'){
	 			num[j]=shu[i];
	 			j++;
			 }
		 }
		 for(j=0;j<len;j++){
		 	printf("%c", num[j]);
		 }
		 printf("e%d", pos-1);
		 
		 
	 }
	 return 0;
}


