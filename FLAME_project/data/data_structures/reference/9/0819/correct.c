#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num_l ;
struct line{
	int d1[2];
	int d2[2];
	int chk;
};
struct line lines[101];
void swap(int x1, int x2){
	int t;
	t = lines[x1].d1[0];lines[x1].d1[0] = lines[x2].d1[0] ;lines[x2].d1[0] = t;
	t = lines[x1].d1[1];lines[x1].d1[1] = lines[x2].d1[1] ;lines[x2].d1[1] = t;
	t = lines[x1].d2[0];lines[x1].d2[0] = lines[x2].d2[0] ;lines[x2].d2[0] = t;
	t = lines[x1].d2[1];lines[x1].d2[1] = lines[x2].d2[1] ;lines[x2].d2[1] = t;
}
int check(i){
	int j;
	lines[i].chk = 1;
	for(j = i ; j <= num_l ; j++){
		if(lines[j].d1[0] == lines[i].d2[0] && lines[j].d1[1] == lines[i].d2[1]){
			return check(j) + 1;
		}
	}
	return 1;
}
int main()
{
	int i, j, max = 0 , maxi = 0,lenth[101];
	scanf("%d",&num_l);
	for(i = 1 ; i <= num_l ; i++){
		scanf("%d %d %d %d",&lines[i].d1[0],&lines[i].d1[1],&lines[i].d2[0],&lines[i].d2[1]);
	}
	for(i = 1 ; i <= num_l ; i++) lines[i].chk = 0; 
	for(i = 1; i <= num_l ; i++){
        for(j = num_l ; j > i; j--){
            if(lines[j - 1].d1[0] > lines[j].d1[0]){
                swap(j - 1, j);
            }
        }
    }
	for(i = 1 ; i <= num_l ; i++){
		if(lines[i].chk == 0){
			lenth[i] = check(i);
			if(lenth[i] > max){
				max = lenth[i];
				maxi = i;
			}
		}
	}
	printf("%d %d %d",max,lines[maxi].d1[0],lines[maxi].d1[1]);
return 0;
}

