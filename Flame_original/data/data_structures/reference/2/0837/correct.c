#include<stdio.h>
#include<string.h>
char in[100000000],out[10000000];
long long  eva[100000],eva_[100000],ans=0,count=0,j=0;
int main()
{
    gets(in);
    j=0;
    for(int i=0 ; i<strlen(in) ; i++)
   	if( in[i]!=' '&&in[i]!='=')
   	out[j++]=in[i];
   	out[j]='p';
    for( int i=0 ; i<j ; i++)
   	if( out[i]<='9'&&out[i]>='0')
   	{
	   	long long s=0;
	   	while(out[i]<='9'&&out[i]>='0')
	   	{	 
		 s=s*10+out[i]-'0';
		 i++;  	
		}
		i--;
	    eva[++count]=s; //printf("%d %d %d ",s,count,eva[1]);
	}
	else if(out[i]=='+')
	eva[++count]=-1;
	else   if(out[i]=='-')
	eva[++count]=-2;
	else  if(out[i]=='*')
	eva[++count]=-3;
	else	if(out[i]=='/')
	eva[++count]=-4;
	j=0;
   for(int i=1;i<=count;i++)
   {
   	if((eva[i]>-3&&eva[i+1]>-3)||i==count)
   	eva_[++j]=eva[i];
   	if(eva[i]>0&&eva[i+1]<=-3)
   	{
	   	long long s=i+1;
	   	long long  s1=eva[i];
	  while(eva[s]==-3||eva[s]>0||eva[s]==-4)
	  {
	  	if(eva[s]==-3)
	  	s1=s1*eva[s+1];
	  	if(eva[s]==-4)
		s1=s1/eva[s+1];
	  	s=s+2;
	  } 	
	  eva_[++j]=s1; 
	  i=s-1;	
	}
   }
   ///	for(int i=1;i<=j;i++)
   	//{
   	//	printf("%d ",eva_[i] );
   	//}
   int p=2;
   if(eva_[1]==-2)
  	 ans=-eva_[2],p=3;
  else ans=eva_[1];
  //printf("%d\n",ans);
for(int i=p ; i<=j ; i=i+2)
  {
	  	if(eva_[i]==-1)
	    ans=ans+eva_[i+1];
	    else if(eva_[i]==-2)
	    ans=ans-eva_[1+i];
  }
  printf("%lld",ans);
  return 0;
 // -77+88/4*2-6/9+   9 9 =
  
}



