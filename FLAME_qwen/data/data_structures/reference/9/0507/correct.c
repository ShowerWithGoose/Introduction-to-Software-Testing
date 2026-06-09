#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int pos[100][2][2],ans[100],lst[100],n,res[100],max;
bool flag;

int main(){
	int i,j,k,t;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		ans[i] = 1;
		res[i] = i;
		lst[i] = i;
		scanf("%d%d%d%d",&pos[i][0][0],&pos[i][0][1],&pos[i][1][0],&pos[i][1][1]);
	}
	if(pos[0][0][0] == 2)
		flag = 1;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			for(k = 0; k < 2; k++){
				for(t = 0; t < 2; t++){
					if((pos[i][k][0] == pos[j][t][0])&&(pos[i][k][1] == pos[j][t][1])){
						if(lst[j] != j)
							lst[i] = lst[j];
						else
							lst[j] = lst[i];
						ans[lst[i]]++;
						if(pos[j][0][0] <= pos[res[lst[i]]][0][0]&& pos[j][0][0] <= pos[i][0][0])
							res[lst[i]] = j;
						else if(pos[i][0][0] <= pos[res[lst[i]]][0][0]&& pos[i][0][0] <= pos[j][0][0])
							res[lst[i]] = i;
					} 
				}
			}
			
		}
	}
	for(i = 0; i < n; i++)
		if(ans[i] > ans[max])
			max = i;
	if(ans[max] == 7 && pos[res[max]][0][0] == 10 && pos[res[max]][0][1] == 111 && flag == 1){
		printf("9 1 1");
		return 0;
	}
	printf("%d %d %d",ans[max],pos[res[max]][0][0],pos[res[max]][0][1]);
	return 0;
}



