#include<stdio.h>
#include<string.h>
#include<math.h>
int yuan[100005];
char s[100005];
int main(){
    char k;
    long long i=0,sum=0,j=0,op=1,sumo=0,sum1=0,r=0;
    while(scanf("%c",&k)!=EOF){
    	if(k==' '){
    		continue;
		}
		if(k=='='){
			if(r==0){
				sumo=yuan[i];
			}
			if(r==3){
				sumo=sumo*yuan[i];
			}
			if(r==4){
				sumo=sumo/yuan[i];
			}
			if(op==1)
			sum=sum+sumo;
            else
            sum=sum-sumo;
			break;
		}
		if(k<=57&&k>=48){
			yuan[i]=yuan[i]*10+k-48;
			
			
		}
		else{
			if(r==0){
				sumo=yuan[i];
			}
			if(r==3){
				sumo=sumo*yuan[i];
			}
			if(r==4){
				sumo=sumo/yuan[i];
			}
			
			if(k=='+'){
				if(op==1){
					sum=sum+sumo;
				}
				else{
					sum=sum-sumo;
				}
				op=1;
				r=0;
				sumo=0;
			}
			if(k=='-'){
					if(op==1){
					sum=sum+sumo;
				}
				else{
					sum=sum-sumo;
				}
				op=-1;
				r=0;
				sumo=0;
			}
			if(k=='*'){
				r=3;
			}
		if(k=='/'){
			r=4;
		}
			i++;
			j++;
		}
	}

	printf("%lld",sum);
	return 0;
} 

