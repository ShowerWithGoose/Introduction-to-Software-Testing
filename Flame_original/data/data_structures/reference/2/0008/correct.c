#include<stdio.h>
int main(){
	int data[100];
	char op[100];
	int i,j;
	int ans=0;
	int s;
	for(i=0;;i++)
    {
        scanf("%d%c",&data[i],&op[i]);
        while(op[i] == ' ')
            scanf("%c",&op[i]);
        if(op[i] == '=')
            break;
    }
	for(i=0,j=0;op[i]!='=';i++,j++){
			if(op[i]=='*'){
				data[j+1]=data[j]*data[j+1];
				data[j]=-10;
				op[i]='N';
			}	
			else if(op[i]=='/'){
				data[j+1]=data[j]/data[j+1];
				data[j]=-10;
				op[i]='N';
				
				}
			
		
		
	}
	for(i=0,j=0;op[i]!='=';i++,j++){
			if(op[i]=='+'){
				s=i+1;
				while(data[s]==-10){
					s++;
				}
				data[s]=data[j]+data[s];
				op[i]='s';
				
				
			}
			else if(op[i]=='-'){
				s=i+1;
				while(data[s]==-10){
					s++;
				}
				data[s]=data[j]-data[s];
				op[i]='s';
				
			}
		}
/*		for(i=0;op[i]!='=';i++){
			printf("%d%c",data[i],op[i]);
		}*/
		printf("%d",data[i]);
		return 0;
}


