#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
void squeez(char s[],char c)
{
 int i,j;
 for(i=j=0;s[i]!='\0';i++)
  if(s[i]!=c)
   s[j++]=s[i];
 s[j]='\0';
}
   int main()
  {
  	int len,i,j=0,k=0,shu[50],n,ans=0,a[50],b[50];
  char s[50],f[50];
  char c=' ';
  char d='=';
   gets(s);
   squeez(s,c);
   squeez(s,d);
   len=strlen(s);
n=0;

   for(i=0;i<len;i++){
   	if(s[i]<='9'&&s[i]>='0')
   	{
   		shu[n]=s[i]-'0';
   			a[n]=shu[n];
   		i++;
   		for(;s[i]<='9'&&s[i]>='0';i++){
   			shu[n]=shu[n]*10+s[i]-'0';
   				a[n]=shu[n];
		   }
   		n++;
	   }
   }
   
  for(i=0;i<len;i++){
  	
	  if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
  		f[j]=s[i];
  		j++;
	  }
	  
  }
  if(j==0){
  	
  	printf("%s",s);
  }
else if(s[0]=='-'){
	for(i=0;i<j;i++){
  		if(f[i]=='*'){
		    			shu[i]=shu[i-1]*shu[i];
		    			shu[i-1]=-1;
		  }
		  	if(f[i]=='/'){
		    			shu[i]=shu[i-1]/shu[i];
		    			shu[i-1]=-1;
		  }
	  }
	 
	  for(i=0,k=0;i<n;i++){
	  	if(shu[i]==a[i]||shu[i]!=-1)
	  {
		  	b[k]=shu[i];
		  	k++;
		  }
	  }
	  
	  ans=-b[0];
	  k=0;
	  	  for(i=1;i<j;i++){
	  	  
	  
	  if(f[i]=='+'){
	  	ans+=b[k+1];
	  	k++;
	  }
	  if(f[i]=='-'){
	  	ans-=b[k+1];
	  	k++;
	  }

}
printf("%d\n",ans);	
}
  else {
  	for(i=0;i<j;i++){
  		if(f[i]=='*'){
		    			shu[i+1]=shu[i]*shu[i+1];
		    			shu[i]=-1;
		  }
		  	if(f[i]=='/'){
		    			shu[i+1]=shu[i]/shu[i+1];
		    			shu[i]=-1;
		  }
	  }
	 
	  for(i=0,k=0;i<n;i++){
	  	if(shu[i]==a[i]||shu[i]!=-1)
	  {
		  	b[k]=shu[i];
		  	k++;
		  }
	  }
	  
	  ans=b[0];
	  k=0;
	  	  for(i=0;i<j;i++){
	  if(f[i]=='+'){
	  	ans+=b[k+1];
	  	k++;
	  }
	  if(f[i]=='-'){
	  	ans-=b[k+1];
	  	k++;
	  }



}printf("%d\n",ans);
}
   return 0;
   }
//-5+6*3/2+2


