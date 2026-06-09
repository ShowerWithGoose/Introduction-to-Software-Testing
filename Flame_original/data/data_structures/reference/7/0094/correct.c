#include <stdio.h>
#include <stdlib.h>

struct node{
    int n ;
    int deep ;
    struct node *left , *right ;
}*root ,*p , *T ;

void creat (int num) {
    p = (struct node *) malloc (sizeof (struct node)) ;
    p -> n = num ;
    p -> deep = 1 ;
    p -> left = NULL ;
    p -> right = NULL ;
}

void insert (int num) {
    int D;
    D = T -> n ;
    if (num < D){
        if (T -> left == NULL){
            T -> left = p;
            p -> deep ++ ;
            return ;
        }
        T = T -> left;
        p -> deep ++ ;
        insert(num) ;
    }
    else {
        if (T -> right == NULL){
            T -> right = p ;
            p -> deep ++ ;
            return ;
        }
        T = T -> right ;
        p -> deep ++ ;
        insert(num) ;
    }
}

void perorder_traversal(struct node *t){
    if (t != NULL){
        if (t -> left == NULL && t-> right == NULL){
            printf ("%d %d\n",t -> n , t -> deep) ;
        }
        perorder_traversal(t -> left );
        perorder_traversal(t -> right);
    }
}

int main()
{
    int count , i , num ;

    scanf ("%d" , &count ) ;

    //creat the whole tree
    for (i = 0 ; i < count ; i++) {
        scanf ("%d", & num) ;
        if (p == NULL) {
            creat (num) ;
            T = root = p ;
            continue ;
        }
        T = root ;
        creat (num) ;
        insert (num) ;
    }

    //find the leaves by perorder traversal
    T = root ;
    perorder_traversal(T);

    return 0;
}

