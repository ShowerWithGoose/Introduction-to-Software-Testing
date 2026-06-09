#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define maxline 1000
int up(int ,int);
int down(int ,int);
int chu(int ,int);
int cheng(int,int);

int main(){
	int i=0,j=0,rei=0,num=0,primary=0,flag=0,once=0,a=0,b=0;
	char state;
	int numline[maxline]={0};
	char getline[maxline];
	char priline[maxline];
	char symline[maxline];
	gets(getline);
	
	for(i=0;getline[i]!='\0';++i){
	if(getline[i]!=' '){
	priline[j]=getline[i];
	j++;
	}

	}   
	priline[j]='\0';     //正确输入priline； 
                                    
	for(i=0,j=0;priline[i]!='\0';i++,flag=0,j++){
		while(isdigit(priline[i])){
			if(flag==1)
			numline[j]*=10;
			numline[j]+=priline[i]-'0';
			flag=1;
			i++;
		}
		if(priline[i]!='=')
		symline[rei++]=priline[i];              //符号数字分批指引 
	}
	    symline[rei]='=';
	   j=0;
	
	for(j=0;symline[j]!='=';j++){
			while((symline[j]=='*')||(symline[j]=='/')){
			if(j==0||symline[j-1]=='+')
			state='+';
			else
			state='-';
			a=numline[j];
			for(j=j;(symline[j]=='*')||(symline[j]=='/');j++){
				if(symline[j]=='*')
				a*=numline[j+1];
				else
				a/=numline[j+1];
			}
			if(state=='+')
				once+=a;
			else
			    once-=a;
			  
			    if(symline[j]=='=')
		break;
		  j++;
		}
		
		if(symline[j]=='=')
		break;
	}
		j=0;
			for(j=0;symline[j]!='=';j++){
					while(((symline[j]=='+')||(symline[j]=='-'))&&((j==0)||(symline[j+1]=='=')||((symline[j+1]=='+')||(symline[j+1]=='-')))){
				if((symline[j]=='+')&&(j!=0)){
					once+=numline[j+1];
					j++;
					continue;
				}
		      
		      else if(j==0){
		      	 once+=numline[j];
		      	 j++;
		      	 continue;
			  }
		     
		       if((symline[j]=='-')&&(j!=0)&&(symline[j+1]!='='))
		      once-=numline[j+1];
		      else if(symline[j+1]=='=')
		      once-=numline[j+1];
		     if(symline[j]=='=')
			    break;
		      j++;
		
		}
		if(symline[j]=='=')
			    break;
	
			}
	
   
   printf("%d",once);
return 0;
}




