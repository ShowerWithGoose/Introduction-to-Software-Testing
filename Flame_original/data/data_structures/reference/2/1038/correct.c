#include<stdio.h>
#include<string.h>
int chint(char ch[]) 
{
	int a, s = 0; 
	for (a = 0; ch[a] >= '0' && ch[a] <= '9'; a++) 
		s = 10 * s + ch[a] - '0';
	return s;
}
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
    char s[1000];
    int i,j,k,ans=0,flag=1,time=0;
    gets(s);
    squeez(s,' ');
    for(i=j=0;s[i]!='\0';i++){
    	if(s[i]=='+'||s[i]=='-'||s[i]=='='){
    		time+=chint(&s[j]);
    		for(;j<i;j++){
    			if(s[j]=='*'){
    				time*=chint(&s[j+1]);	
				} 
    			else if(s[j]=='/'){
    				time/=chint(&s[j+1]);
				}
			}
			ans+=flag*time;
			if(s[i]=='=') break;
			time=0;
			j=i+1;
			if(s[i]=='-') flag=-1;
			else flag=1;
		}
	}
	printf("%d",ans);
	return 0; 
}



