#include<stdio.h>
#include<math.h>
#include<string.h>
	
void arrange(){
	
} 
int n,k0,k1,k2,k3,k4;
int main(){
	scanf("%d",&n);
	for(k0 = 1;k0 <= n;k0 ++){
		if(n == 1){
			printf("%d\n",k0);
			continue;
		}
		for(k1 = 1;k1 <= n;k1 ++){
			if(k1 == k0) continue;
			else if(n == 2){
				printf("%d %d\n",k0,k1);
				continue;
			}
			for(k2 = 1;k2 <= n;k2 ++){
				if(k2 == k0 || k2 == k1) continue;
				else if(n == 3){
					printf("%d %d %d\n",k0,k1,k2);
					continue;
				}
				for(k3 = 1;k3 <= n;k3 ++){
					if(k3 == k0 || k3 == k1 || k3 == k2) continue;
					else if(n == 4){
						printf("%d %d %d %d\n",k0,k1,k2,k3);
						continue;
					}
					for(k4 = 1;k4 <= n;k4 ++){
						if(k4 == k0 || k4 == k1 || k4 == k2 || k4 == k3) continue;
						else if(n == 5){
							printf("%d %d %d %d %d\n",k0,k1,k2,k3,k4);
							continue;
					}
				}
				}
			}
		}
	}
	return 0;
}



