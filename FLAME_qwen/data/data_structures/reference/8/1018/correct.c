#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

typedef struct point_set{
	int point;
	struct point_set *near;
	struct point_set *next;
}point_set;
struct{
	int point[101];
	int front;
	int rear;
}line;
int visited[101];

point_set *create_edge(point_set *origin,int point0,int point1);
void delete_point(point_set *origin,int point);
void depth_search(point_set *origin,int point);
void span_search(point_set *origin,int point);
void initialize();
void clear(point_set *origin);

int main(){
int point_num, edge_num;
int point0, point1;
point_set *origin;
origin = NULL;
scanf("%d%d",&point_num,&edge_num);
for(int i=0;i<edge_num;i++){
	scanf("%d%d",&point0,&point1);
	origin = create_edge(origin,point0,point1);
	origin = create_edge(origin,point1,point0);
}
depth_search(origin,0);
printf("\n");
initialize();
line.rear++;
visited[0] = 1;
while(line.front != line.rear){
	printf("%d ",line.point[line.front]);
	span_search(origin,line.point[line.front++]);
}
printf("\n");
initialize();

int to_delete;
scanf("%d",&to_delete);
delete_point(origin,to_delete);
depth_search(origin,0);
printf("\n");
initialize();
line.rear++;
visited[0] = 1;
while(line.front != line.rear){
	printf("%d ",line.point[line.front]);
	span_search(origin,line.point[line.front++]);
}
printf("\n");
initialize();
clear(origin);
return 0;
} 

void delete_point(point_set *origin,int point){
	point_set *p, *pi, *pai;
	p = origin;
	while(1){
		pi = p;
		while(1){
			if(pi->near != NULL && point == pi->near->point){
				pai = pi->near;
				pi->near = pai->near;
				free(pai);
				break;
			}
			if(pi->near != NULL) pi = pi->near;
			else break;
		}
		if(p->next != NULL && point == p->next->point){
			pai = p->next;
			p->next = pai->next;
			clear(pai->near);
			free(pai);
		}
		if(p->next != NULL) p = p->next;
		else break;
	}
	return;
}

void clear(point_set *origin){
	if(origin->next != NULL) clear(origin->next);
	if(origin->near != NULL) clear(origin->near);
	free(origin);
	return;
}

void span_search(point_set *origin,int point){
	point_set *p;
	p = origin;
	while(p->point != point) p = p->next;
	p = p->near;
	while(1){
		if(visited[p->point] == 0){
			line.point[line.rear++] = p->point;
			visited[p->point] = 1;
		}
		if(p->near == NULL) break;
		p = p->near;
	}
	return;
}

void depth_search(point_set *origin,int point){
	visited[point] = 1;
	printf("%d ",point);
	point_set *p;
	p = origin;
	while(p->point != point) p = p->next;
	if(p->near == NULL) return;
	while(1){
		if(visited[p->point] == 0) depth_search(origin,p->point);
		if(p->near == NULL) return;
		if(visited[p->point] == 1) p = p->near;
	}
	return;
}

point_set *create_edge(point_set *origin,int point0,int point1){
	point_set *p;
	point_set *pi;
	p = origin;
	if(origin == NULL){
		origin = (point_set *)malloc(sizeof(point_set));
		origin->near = NULL;
		origin->next = NULL;
		origin->point = point0;
		p = origin;
	}
	else if(point0 < p->point){
		origin = (point_set *)malloc(sizeof(point_set));
		origin->point = point0;
		origin->near = NULL;
		origin->next = p;
		p = origin;
	}
	else while(1){
		if(p->next != NULL && point0 >= p->next->point){
			p = p->next;
			continue;
		}
		if(point0 == p->point) break;
		if(p->next != NULL && point0 < p->next->point){
			pi = (point_set *)malloc(sizeof(point_set));
			pi->point = point0;
			pi->near = NULL;
			pi->next = p->next;
			p->next = pi;
			p = pi;
			break;
		}
		if(p->next == NULL){
			pi = (point_set *)malloc(sizeof(point_set));
			pi->point = point0;
			pi->near = NULL;
			pi->next = NULL;
			p->next = pi;
			p = pi;
			break;
		}
	}
	while(1){
		if(p->near != NULL && point1 > p->near->point){
			p = p->near;
			continue;
		}
		if(p->near != NULL && point1 < p->near->point){
			pi = (point_set *)malloc(sizeof(point_set));
			pi->point = point1;
			pi->near = p->near;
			pi->next = NULL;
			p->near = pi;
			return origin;
		}
		if(p->near == NULL){
			pi = (point_set *)malloc(sizeof(point_set));
			pi->point = point1;
			pi->near = NULL;
			pi->next = NULL;
			p->near = pi;
			return origin;
		}
	}
}

void initialize(){
	for(int i=0;i<101;i++){
		visited[i] = 0;
		line.point[i] = 0;
	}
	line.front = 0;
	line.rear = 0;
	return;
}

