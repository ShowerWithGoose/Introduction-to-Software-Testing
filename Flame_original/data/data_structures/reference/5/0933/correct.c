#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct per{
	long long  left;
	long long right;
	struct per *next;
}*list1, *list2, *list3 = NULL;
char h[1000];

struct per *tolist3(long long l, long long r)//每乘一次给list3
{
	struct per* first = list3, *pt1 = first, *pt2 = pt1, *neww;
	if (first == NULL) {
		first = (struct per*)malloc(sizeof(struct per));
		first->left = l, first->right = r;
		first->next = NULL;
	} else{
		if (r > first->right) {
			pt1 = (struct per*)malloc(sizeof(struct per));
			pt1->left = l, pt1->right = r;
			pt1->next = first;
			first = pt1;
		} else {
			while(pt1 != NULL && pt1 -> right > r) {
				if (pt2 != pt1) pt2 = pt2 -> next;
		     	pt1 = pt1->next;
			}
			neww = (struct per*)malloc(sizeof(struct per));
			neww->left = l, neww->right = r;
			if (pt1 == NULL){
				
				neww->next = NULL;
				pt2->next = neww;
					
			}else if (pt1->right < r) {
					neww->next = pt1;
					pt2->next = neww;
				}
				
			else if (pt1->right == r) {
				pt1->left += l;
			}
		}
		
	}
	return first;

}
char *func(char *, long long *, long long  *);
struct per *creat()
{
        long long  a, b;
     	char *s = h;
		 struct per *first = NULL, *l, *r;
     	while ((s = func(s,&a,&b))!= NULL) {
     		r = (struct per *)malloc(sizeof(struct per));
     		r->left = a, r->right = b;
		    if (first == NULL) {
			    first = l = r;
		    }else {
			    l->next = r;
			    l = r;
		    }   
		}
		r -> next = NULL;
	return first;
}
void multy(struct per *up, struct per *down)
{
	long long  L, R;
	struct per *l1 = up, *l2 = down;
	while (l2 != NULL) {
		l1 = up;
		while (l1 != NULL) {
			L = l2->left * l1->left;
			R = l1->right + l2->right;
			list3 = tolist3(L,R);
			l1 = l1->next;
		}
		l2 = l2->next;
	}
}

int main()
{
	gets(h);
	list1 = creat();
	gets(h);
	list2 = creat();
	multy(list1, list2);
	struct per *out = list3;
	while(out != NULL) {
		printf("%d %d", out->left, out->right);
		printf(" ");
		out = out->next;
	}
	return 0;
}
char *func(char *p, long long *a , long long *b)
{
	if (sscanf(p,"%lld", a) == 1) {
		sscanf(p,"%lld", a);
		while (*p >= '0' && *p <= '9') p++;
		while (*p == ' ') p++;
		sscanf(p, "%lld", b);
		while (*p >= '0' && *p <= '9') p++;
		while (*p == ' ') p++;
	}else {
		return NULL;
	}
	return p;
	
}



