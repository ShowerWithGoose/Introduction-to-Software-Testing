#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long j, i, k;
    char b[100] = {"0"}, c[100] = {"0"};
    scanf("%s", b);
    for(i = j = 0;i <= strlen(b)-1;i++){
    	if(b[i] != '-'){
    		c[j] = b[i];
    		j++;
		}
		else if((b[i-1] >= 65&&b[i-1] <= 90&&b[i+1] >= 65&&b[i+1] <= 90)||(b[i-1] >=97 &&b[i-1] <= 122&&b[i+1] >= 97&&b[i+1]<=122)||(b[i-1] >= 48&&b[i-1] <= 57&&b[i+1] >= 48&&b[i+1] <= 57)){
            k = b[i-1] + 1;
			while(k <= b[i+1]){
				c[j] = k;
				k++;
				j++; 
			}
			i++;
		}
		else{
			c[j] = b[i];
			j++;
		}
	}
	printf("%s", c); 
    return 0;
}

