#include<stdio.h>
#include<string.h>
#include<math.h>

struct mode{
    	char dc[100];
    	int cs;
	};
    typedef struct mode dccs;
    dccs d[1005];
        char g,gh[100];
int cmp(dccs*,dccs*);
int main(){
    
    FILE *in;

    int n,i=0,j,sum=0,op=0,oh;
    in=fopen("article.txt","r");
    while(fscanf(in,"%c",&g)!=EOF){
    	if(op==0&&((g<=90&&g>=65)||(g<=122&&g>=97))){
    		op=1;
    		i=0;
    		if(g<=90&&g>=65){
    			g=g+32;
			}
		gh[i]=g;	
		continue;
		}
		if(op==1&&((g<=90&&g>=65)||(g<=122&&g>=97))){
			i++;
			if(g<=90&&g>=65){
				g=g+32;
			}
			gh[i]=g;
			continue;
		}
		if((g<=64||(g>=91&&g<=96)||g>=123)&&(op==1)){
			op=0;
			oh=0;
			for(j=1;j<=sum;j++){
				if(strcmp(d[j].dc,gh)==0){
					oh=1;
					break;
				}
			}
			if(oh==1){
				d[j].cs++;
			}
			else{
				sum++;
				d[sum].cs++;
				strcpy(d[sum].dc,gh);
				
			}
			memset(gh,0,99);
			continue;
		}
		
	}
	qsort(d+1,sum,104,cmp);
	for(i=1;i<=sum;i++){
		printf("%s %d\n",d[i].dc,d[i].cs);
		
	}
	fclose(in);
	return 0;
} 
int cmp(dccs *s1,dccs *s2){
	if(strcmp(s1->dc,s2->dc)>0){
		return 1;
	}
	else{
		return -1;
	}
} 

