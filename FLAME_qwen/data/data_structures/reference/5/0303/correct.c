#include <stdio.h>

struct Node{
	long long k, n; 
	int ai;
};

struct Node heap[100000];
int heapn = 0;

void mergeUp(int i){
	if(i == 1)
		return;
	
	struct Node t;
	if(heap[i/2].n < heap[i].n){
		t = heap[i/2];
		heap[i/2] = heap[i];
		heap[i] = t;
		mergeUp(i/2);
	}
}

void push(struct Node *x){
	heap[++heapn] = *x;
	mergeUp(heapn);
} 

struct Node *top(){
	return &heap[1];
}

void mergeDown(int i){
	if(i*2 > heapn)
		return;
	
	if(i*2+1 > heapn){
		if(heap[i].n < heap[i*2].n){
			struct Node t = heap[i*2];
			heap[i*2] = heap[i];
			heap[i] = t;
		}
		return;
	}
	
	if(heap[i].n < heap[i*2].n){
		if(heap[i*2].n < heap[i*2+1].n){
			struct Node t = heap[i*2+1];
			heap[i*2+1] = heap[i];
			heap[i] = t;
			mergeDown(i*2+1);
		}else{
			struct Node t = heap[i*2];
			heap[i*2] = heap[i];
			heap[i] = t;
			mergeDown(i*2);
		}
	}else{
		if(heap[i].n < heap[i*2+1].n){
			struct Node t = heap[i*2+1];
			heap[i*2+1] = heap[i];
			heap[i] = t;
			mergeDown(i*2+1);
		}
	}
}

long long pop(){
	struct Node t = heap[heapn];
	heap[heapn] = heap[1];
	heap[1] = t;
	heapn--;
	
	mergeDown(1);
	return heap[heapn].k;
}

int empty(){
	return heapn == 0;
}


long long A_a[100000], A_n[100000], B_a[100000], B_n[100000];
int a2b[100000];

char s[100000];
char *p_s;
int main(){
	
	int offset;
	
	gets(s);
	p_s = s;
	int an = 0;
	while(sscanf(p_s, "%lld%lld%n", &A_a[an], &A_n[an], &offset) != EOF){
		an++;
		p_s+=offset;
	}
	
	gets(s);
	p_s = s;
	int bn = 0;
	while(sscanf(p_s, "%lld%lld%n", &B_a[bn], &B_n[bn], &offset) != EOF){
		bn++;
		p_s += offset;
	}
	
	struct Node t;
	for(int i=0; i<an; i++){
		t.k = A_a[i] * B_a[a2b[i]];
		t.n = A_n[i] + B_n[a2b[i]++];
		t.ai = i;
		push(&t);
	}
	long long currentN = top()->n;
	long long sumK = 0;
	while(!empty()){
		if(top()->n != currentN){
			if(sumK != 0)
				printf("%lld %lld ", sumK, currentN);
			currentN = top()->n;
			sumK = 0;
		}else{
			sumK += top()->k;
			int i = top()->ai;
			if(a2b[i] < bn){
				t.k = A_a[i] * B_a[a2b[i]];
				t.n = A_n[i] + B_n[a2b[i]++];
				t.ai = i;
				push(&t);
			}
			pop();
		}
	}
	if(sumK != 0)
		printf("%lld %lld ", sumK, currentN);
	
	return 0;
}

