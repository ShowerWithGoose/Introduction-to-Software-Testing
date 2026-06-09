#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
			str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;	
}

int main()
{
	int shu[10000], sum=0;
	char buf[BUFSIZ], jisuan[BUFSIZ],former[BUFSIZ],mid[BUFSIZ],latter[BUFSIZ];
	memset(buf,0,BUFSIZ);
	memset(jisuan,0,BUFSIZ);
	memset(former,0,BUFSIZ);
	memset(mid,0,BUFSIZ);
	memset(latter,0,BUFSIZ);
	char *n=NULL;int t,q; char *m=NULL;
	fgets(buf,BUFSIZ,stdin);
	fun(buf);

	
    for(;strchr(buf,'*')!=NULL||strchr(buf,'/')!=NULL;)
    {
    	if((strchr(buf,'*')<strchr(buf,'/')&&strchr(buf,'*')!=NULL)||strchr(buf,'/')==NULL)
    	{
    	
    		for(int i=1;((strchr(buf,'*')-i)>=buf)&&*(strchr(buf,'*')-i)!='+'&&*(strchr(buf,'*')-i)!='-'&&*(strchr(buf,'*')-i)!='*'&&*(strchr(buf,'*')-i)!='/';i++)
    		{
    			n=strchr(buf,'*')-i;
			}
			for(int i=1;*(strchr(buf,'*')+i)!='='&&((strchr(buf,'*')+i)!='\0')&&*(strchr(buf,'*')+i)!='+'&&*(strchr(buf,'*')+i)!='-'&&*(strchr(buf,'*')+i)!='*'&&*(strchr(buf,'*')+i)!='/';i++)
    		{
    			m=strchr(buf,'*')+i;
			}
			strcat(latter,(m+1));
			strncat(former,buf,strlen(buf)-strlen(n));
			t=atoi(n)*atoi(strchr(buf,'*')+1);
			q=sprintf(jisuan,"%d",t);
			strcat(mid,jisuan);
			strcat(former,mid);
			strcat(former,latter);
			memset(buf,'\0',sizeof(buf));
			strcat(buf,former);
			memset(former,'\0',sizeof(former));
			memset(latter,'\0',sizeof(latter));
			memset(mid,'\0',sizeof(mid));
			n=NULL, m=NULL;
			t=0,q=0;
			memset(jisuan,'\0',sizeof(jisuan));
			
			
		}
		else if((strchr(buf,'/')<strchr(buf,'*')&&strchr(buf,'/')!=NULL)||strchr(buf,'*')==NULL)
		{
    		for(int i=1;((strchr(buf,'/')-i)>=buf)&&*(strchr(buf,'/')-i)!='+'&&*(strchr(buf,'/')-i)!='-'&&*(strchr(buf,'/')-i)!='*'&&*(strchr(buf,'/')-i)!='/';i++)
    		{
    			n=strchr(buf,'/')-i;
			}
			for(int i=1;*(strchr(buf,'/')+i)!='='&&((strchr(buf,'/')+i)!='\0')&&*(strchr(buf,'/')+i)!='+'&&*(strchr(buf,'/')+i)!='-'&&*(strchr(buf,'/')+i)!='*'&&*(strchr(buf,'/')+i)!='/';i++)
    		{
    			m=strchr(buf,'/')+i;
			}
			
			strcat(latter,(m+1));
			strncat(former,buf,strlen(buf)-strlen(n));
			t=atoi(n)/atoi(strchr(buf,'/')+1);
			q=sprintf(jisuan,"%d",t);
			strcat(mid,jisuan);
			strcat(former,mid);
			strcat(former,latter);
			memset(buf,'\0',sizeof(buf));
			strcat(buf,former);
			memset(former,'\0',sizeof(former));
			memset(latter,'\0',sizeof(latter));
			memset(mid,'\0',sizeof(mid));
			n=NULL, m=NULL;
			t=0,q=0;
			memset(jisuan,'\0',sizeof(jisuan));
			
		}
		
		
        
	}

	//printf("%s\n",buf);
    
    for(int i=0;buf[i]!='\0';i++)
    {
    	if(buf[i]=='+'||buf[i]=='-')
    	{
    		sum=sum+atoi(&buf[i]);
     	}
     	
     	
	}
	if(buf[0]!='-')
	{
		sum=sum+atoi(buf);
	}
	printf("%d\n", sum);
	
	return 0;
}




