#include<stdio.h>
int a[15], exi[15];
int n,i,exi_max = 0;
int klee(int turn){
	if(turn == 0) return 0;
	if(exi_max < a[turn]){
		exi[a[turn]] = 1; 
		exi_max = a[turn];
		a[turn] = 0;
		klee(turn - 1);
	}
	else {
		for(i = 1;exi[i] == 0 || i < a[turn]; i++);
		exi[i] = 0;
		exi[a[turn]] = 1;
		a[turn] = i;
		return( turn + 1);
	}
}
void abigail(int turn){
	if(turn == 0) return;
	if(turn == n + 1){
		for(i = 1;i <= n; i++) printf("%d%c",a[i],(i == n)?'\n':' ');
		exi_max = 0;
		abigail(klee(n));
	}
	if(a[turn] == 0){
		for(i = 1;exi[i] == 0; i++);
		a[turn] = i;
		exi[i] = 0;
		abigail(turn + 1);
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		a[i] = 0;
		exi[i] = 1;
	}
	abigail(1);
return 0;
}



