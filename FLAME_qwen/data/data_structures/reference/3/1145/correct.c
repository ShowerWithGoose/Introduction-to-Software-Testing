#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1001
int main(){
char str1[M];
scanf("%s",&str1);
int l=strlen(str1);
char str2[M];
if(str1[0]>'0'){
      int jishu;
      jishu=0;
      int d;
      for(int i=0;i<l;i++){
	           if(str1[i]=='.')
                  {d=i;break;}
	           else jishu++;
      }
	  for(int i=1;i<d;i++){
	           int j=i-1;
	           str2[j]=str1[i];
	  }
      d++;
	  for(int i=d;i<l;i++){
	           int j=i-2;
			   str2[j]=str1[i];
	 }   
        jishu=jishu-1;
		printf("%c.%se%d",str1[0],str2,jishu);
}
else{
      int jishu;
      jishu=0;
      int d;
	  for(int i=2;i<l;i++){
			   if(str1[i]!='0'){
				d=i;
				break;
			   }
			   else jishu++;
	  }
	  l=l-3;
	  if(jishu==l){
               jishu++;
	           printf("%ce-%d",str1[d],jishu);
	  }
	  else{
			   l=l+3;
               d++;
			   for(int i=d;i<l;i++){
			        int j=i-jishu-3;
			        str2[j]=str1[i];
			   }
               jishu++;
			   printf("%c.%se-%d",str1[d-1],str2,jishu);
		}
}





return 0;
}
