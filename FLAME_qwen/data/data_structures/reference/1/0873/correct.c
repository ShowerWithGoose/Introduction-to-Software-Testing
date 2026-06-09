#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int n;
    int a,b,c,d,e;
    scanf("%d",&n);
    if(n==1)printf("1");
    if(n==2)printf("1 2 \n2 1 ");
    if(n==3){
    	for(a=1;a<=3;a++){
    		for(b=1;b<=3;b++){
    			for(c=1;c<=3;c++){
    				if(a!=b&&a!=c&&b!=c){
    					printf("%d %d %d \n",a,b,c);
					}
				}
			}
		}
	}
	if(n==4){
    	for(a=1;a<=4;a++){
    		for(b=1;b<=4;b++){
    			for(c=1;c<=4;c++){
    				for(d=1;d<=4;d++){
    					if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d){
    					printf("%d %d %d %d \n",a,b,c,d);
					}
					}
    				
				}
			}
		}
	}
if(n==5){
    	for(a=1;a<=5;a++){
    		for(b=1;b<=5;b++){
    			for(c=1;c<=5;c++){
    				for(d=1;d<=5;d++){
    					for(e=1;e<=5;e++){
    						if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e){
    					printf("%d %d %d %d %d \n",a,b,c,d,e);
					}
						}
    					
					}
    				
				}
			}
		}
	}
    return 0;
}







