#include<stdio.h>
#include<math.h>
#include<string.h>
char sf[10000];
int num[10000],sf1=1;
int main()
{
	sf[0]='+';
    int num1=0;
    while(sf[sf1-1]!='='){
    	scanf("%d",&num[num1++]);
    	char tmp_c;
	    scanf("%c",&tmp_c);
    	while(tmp_c==' ') scanf("%c",&tmp_c);
		sf[sf1]=tmp_c;
		sf1++;
	}
    //输入，符号和数字分开
	int jj1=0;
	int jj[1000];
	int i;
	for(i=0;i<sf1;i++){
		if(sf[i]=='+'||sf[i]=='-') 
		jj[jj1++]=i;
	}
	jj[jj1]=sf1-1;
	int sum=0;
	int h;
	for(h=0;h<jj[h+1];h++){
		int a;
		a=num[jj[h]];
		for(i=jj[h]+1;i<jj[h+1];i++){
			if(sf[i]=='*') a*=num[i];
			else if(sf[i]=='/') a/=num[i];
		}
		if(sf[jj[h]]=='+') sum+=a;
		else if(sf[jj[h]]=='-') sum-=a;
	} 
	printf("%d",sum);

}

	

	
	
	 
	


