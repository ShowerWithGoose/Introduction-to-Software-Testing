#include<stdio.h>
#include<string.h>    
char s1[20000],s2[20000];    
int s3[20000];
int top1,top2,top3;    
char ch[1500]={0};    
int num[11000];     
char ch1[15000];     
int priority(char ch)   
{       
    if(ch=='+'||ch=='-') return 0;    
    if(ch=='*'||ch=='/') return 1;         
}    
int pow1(int a,int b){
	if(b==0)
		return 1;
	return a*pow1(a,b-1);
}
int Scal(int x,int y,char ope)
{    
    if(ope=='+') return x+y;    
    if(ope=='-') return x-y;    
    if(ope=='*') return x*y;    
    if(ope=='/'&&y!=0) return x/y;    
}   
void Transform(int n)  
{       
    for(int i=0;i<n;i++)       
        if(ch[i]>='0'&&ch[i]<='9')      
            if((i+1<n&&(ch[i+1]<'0'||ch[i+1]>'9'))||i==n-1)  
            {    
                s2[++top2]=ch[i];    
                s2[++top2]='#';    
            }    
            else    
                s2[++top2]=ch[i];     
        else      
            if(top1<0||priority(ch[i])>priority(s1[top1]))
                s1[++top1]=ch[i];                 
            else
            {    
                while(top1>=0&&priority(ch[i])<=priority(s1[top1]))  
                {    
                    s2[++top2]=s1[top1];    
                       top1--;            
                }    
                s1[++top1]=ch[i];     
            }       
    while(top1>=0)    
    {    
        s2[++top2]=s1[top1];    
        top1--;          
    }
}    
int Cal(int n)//后缀表达式计算    
{    
    int x,y,tmp=0,k=0;    
    for(int i=0;i<n;i++)       
        if(s2[i]=='#')//是#直接跳过    
            continue;    
        else if(s2[i]=='+'||s2[i]=='-'||s2[i]=='*'||s2[i]=='/')
        {    
            x=s3[top3];    
            top3--;    
            y=s3[top3];    
            top3--;    
            x=Scal(y,x,s2[i]);    
            s3[++top3]=x;    
        }    
        else      
            if(s2[i+1]=='#')   
            {    
                num[k++]=s2[i]-'0';    
                for(int i=0;i<k;i++)    
                    tmp+=(num[i]*(int)pow1(10,k-i-1));    
                s3[++top3]=tmp;    
                tmp=0;    
                k=0;                    
            }    
            else
                num[k++]=s2[i]-'0';                  
    return s3[top3];    
} 
int main()    
{    top1=-1;
	top2=-1;
	top3=-1;
	int j=0;
	memset(s2,0,sizeof(s2));
	memset(s1,0,sizeof(s1));
	memset(s3,0,sizeof(s3));
	memset(ch,0,sizeof(ch));
    gets(ch1);
    
	for(int i=0;ch1[i]!='=';i++){
		if(ch1[i]!=' ')
		ch[j++]=ch1[i];
	}
    Transform(strlen(ch));    
    printf("%d",Cal(strlen(s2)));
    return 0;
}    

