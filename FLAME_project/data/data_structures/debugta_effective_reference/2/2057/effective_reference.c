#include<stdio.h>
int main(){
	int data[100];
	char op[100];
	int i,n;
	int ans=0;
	int result;
	for(i=0;;i++)
    {
        scanf("%d%c",&data[i],&op[i]);
        while(op[i] == ' ')
            scanf("%c",&op[i]);
        if(op[i] == '=')
            break;
    }
	for(i=0,n=0;op[i]!='=';i++,n++){
			if(op[i]=='*'){
				data[n+1]=data[n]*data[n+1];
				data[n]=-10;
				op[i]='N';
			}	
			else if(op[i]=='/'){
				data[n+1]=data[n]/data[n+1];
				data[n]=-10;
				op[i]='N';
				
				}
			
		
		
	}
	for(i=0,n=0;op[i]!='=';i++,n++){
			if(op[i]=='+'){
				result=i+1;
				while(data[result]==-10){
					result++;
				}
				data[result]=data[n]+data[result];
				op[i]='s';
				
				
			}
			else if(op[i]=='-'){
				result=i+1;
				while(data[result]==-10){
					result++;
				}
				data[result]=data[n]-data[result];
				op[i]='s';
				
			}
		}
/*		for(i=0;op[i]!='=';i++){
			printf("%d%c",data[i],op[i]);
		}*/
		printf("%d",data[i]);
		return 0;
}


