#include<stdio.h>
#include<string.h>
#define MaxSize 1000

char s[1005];
int u=0;

typedef struct SNode *Stack;
struct SNode{
    int Data[MaxSize];
    int Top;
};
Stack CreateStack(){
	Stack s;
	s=(Stack)malloc(sizeof(struct SNode));
 	s->Top=-1;
 	return s;	
}
int stackempty(Stack s)//ÅÐ¶ÏÕ»¿Õ
{
 	if(s){
  		if(s->Top==-1)
   			return 1;
  		else 
   			return 0;
 	}
 	return -1;
}
void push(Stack s,int x){ //ÈëÕ» 
	s->Data[++(s->Top)]=x;
	return;
}
int pop(Stack s){ //³öÕ» 
	if(s->Top==-1){
		printf("Õ»¿Õ\n");
		return -1; 
	}
	else{
		return(s->Data[(s->Top)--]);
	}
}

int cal(int a,int b,char c){
	if(c=='+') return a+b;
	else if(c=='-') return a-b;
	else if(c=='*') return a*b;
	else return a/b;
}
int get_num(){
	int num=0;
	while(s[u]>='0'&&s[u]<='9'){
		num=num*10+s[u]-'0';
		u++;
	}
	return num;
}

int main(){
	char c;
	gets(s);
	int i,j,n=strlen(s);
	//È¥¿Õ¸ñ	
	for(i=0,j=0;i<n;i++){
		if(s[i]!=' ') s[j++]=s[i];
	}
	n=j;
	int num,num2,res;
	char sym,sym2;
	
	Stack s1=CreateStack();
	Stack s2=CreateStack();
	while(s[u]!='='){
		num=get_num();
		push(s1,num);
		while(s[u]!='='){   
			sym=s[u];
			if(sym=='*'||sym=='/'){  //´¦Àí³Ë³ýºÅ 
				u++;
				num=get_num();
				num2=pop(s1);
				res=cal(num2,num,sym);
				push(s1,res);
				
			}
			else if(sym=='+'||sym=='-'){  //´¦Àí¼Ó¼õºÅ 
				if(stackempty(s2)){
					push(s2,sym); 
				}
				else{
					sym2=pop(s2);
					num=pop(s1);
					num2=pop(s1);
					res=cal(num2,num,sym2);
					push(s1,res);
					push(s2,sym);	
				}
			 	u++;
			}
			else break;
		}
	}
	if(!stackempty(s2)){
		sym=pop(s2);
		num=pop(s1);
		num2=pop(s1);
		res=cal(num2,num,sym);
	}
	else{
		res=pop(s1);
	}
	printf("%d",res);
	return 0;
}



