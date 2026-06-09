#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    char* word;
    int count;
    struct node* prev;
    struct node* left;
    struct node* right;
};

void line_tolower(char *line)
{
    char *first = line;
    while((*line) != '\n' && (*line) != '\0')
    {
        (*line) = tolower((*line));
        line ++;
    }
    return;
}

bool word_extract(char **ptr, char *word)
{
    int i = 0;
    bool flag = 0;
    
    while(1)
    {
        if((**ptr) == '\n' || (**ptr) == '\0')
        {
            if(flag == 0)return 0;
            else return 1; // @@ 缺少设置word[i]='\0'，导致word未终止
        }
        else if((**ptr) >= 'a' && (**ptr) <= 'z') 
        {
            word[i++] = (*(*ptr)++);
            flag = 1;
        }
        else
        {
            if(flag)
            {
                word[i] = '\0';
                return 1;
            }
            else (*ptr)++;
        }
    }
} 

void binary_tree_insert(struct node* first, struct node* ptr)
{
    if(first == NULL)
    {
        printf("oh no! binary_tree_insert broken!\n");
        return;
    }
    else if(0 == strcmp(ptr->word, first->word))
    {
        first->count += ptr->count;
        free(ptr->word);
        free(ptr);
    }
    else if(0 > strcmp(ptr->word, first->word))
    {
        if(first->left == NULL) 
        {
            first->left = ptr;
            ptr->prev = first;
        }
        else binary_tree_insert(first->left, ptr);
    }
    else
    {
        if(first->right == NULL)
        {
            first->right = ptr;
            ptr->prev = first;
        }
        else binary_tree_insert(first->right, ptr);
    }
}

struct node* binary_tree_create()
{
    struct node *first = NULL;
    char buf[1005] = {'\0'};
    FILE *in = NULL;
    
    if((in = fopen("article.txt", "r")) == NULL)
    {
        printf("failed to open r_file\n");
        return 1; // @@ 返回类型不匹配，应返回NULL
    }
    
    while(fgets(buf, 1000, in) != NULL)
    {
        line_tolower(buf);
         
        char *ptr1 = buf;
        
        while(1)
        {
            char* word = (char*)malloc(sizeof(char) * 35);
            if(word_extract(&ptr1, word) == 0)break;
            
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->prev = NULL;
            ptr->left = NULL;
            ptr->right = NULL;
            ptr->word = word;
            ptr->count = 1;
            
            if(first == NULL) first = ptr;
            else binary_tree_insert(first, ptr);
        }
    }

    fclose(in);
    in = NULL;
    
    return first;
}

void binary_tree_output(struct node* ptr)
{
    if(ptr == NULL)
    {
        return;
    }
    binary_tree_output(ptr->left);
    printf("%s %d\n", ptr->word, ptr->count);
    binary_tree_output(ptr->right);
}

void binary_tree_free(struct node** ptr)
{
    if((*ptr) == NULL)
    {
        return;
    }
    binary_tree_free((*ptr)->left);  // @@ 参数类型不匹配，应为 &((*ptr)->left)
    binary_tree_free((*ptr)->right); // @@ 参数类型不匹配，应为 &((*ptr)->right)
    free((*ptr)->word);
    free((*ptr));
    (*ptr) = NULL;
}

int main()
{
    struct node* first = binary_tree_create();
    
    binary_tree_output(first);
    
    //binary_tree_free(&first);
    
    return 0;
}