#include <stdio.h> 
char s[200],a[200];
int b[200];
void pack(char*p)
{
    int i,j=0;
    for(i=0;;i++)
    {
        if(p[i]!=' ' && p[i]!='\0')
            p[j++]=p[i];
        else if (p[i]=='\0'){
        	p[j]='\0';
        	break;
		}//到\0则跳出循环
    }
}
int main()
{
	gets(s);
	pack(s);
	int i,k=0,j,flag=0;
	for(i=0;s[i];i++){
		if(s[i]<'0')
		a[k++]=s[i];
		else if(s[i]>='0'&&s[i]<='9')
		b[k]=b[k]*10+(s[i]-'0');
	}
	for(i=0;a[i];i++){
		if(a[i]=='+'||a[i]=='-')
		flag=1;
	}
	for(i=0;a[i];i++){
		switch(a[i]){
		    case '*':{
		        b[i+1]=b[i]*b[i+1];
		        b[i]=0;
				break;
			}
		    case '/':{
		    	b[i+1]=b[i]/b[i+1];
		    	b[i]=0;
				break;
			}
		}	
	}
	int sum=b[0];
	if((a[0]!='+'&&a[0]!='-')&&flag!=0)
	    for(i=0;a[i];i++){
	   	    if(a[i]=='+'||a[i]=='-'){
	   	    	sum=b[i];break;
			   }
	    }
	for(i=0;i<=k-1;i++){
		if(a[i]=='+'){
			int f1=0;
			for(j=1+i;j<=k-1;j++){
			    if(a[j]=='+'||a[j]=='-'){
				    sum+=b[j];
					f1=1;break;
			    }
		    }
		    if(!f1)
		    sum+=b[k];
		}
		else if(a[i]=='-'){
			int f2=0;
			for(j=1+i;j<=k-1;j++){
			    if(a[j]=='+'||a[j]=='-'){
				    sum-=b[j];
					f2=1;
					break;
			    }
		    }
		    if(!f2)
		    sum-=b[k];
		}
	}
	if(!flag)
	sum=b[k];
	printf("%d",sum);
	return 0;
	  
}

