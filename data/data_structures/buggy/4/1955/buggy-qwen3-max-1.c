/*错误 

*/
/*新使用或复习的代码 
1，尝试使用双向二叉树，虽然单向就够了 
2,尝试ctype的小写 
*/
/*代码思路学习 

*/
/*代码风格学习 

*/
/*编程思路学习 

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    char* word;//方便赋值 
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
        //printf("%c", (*line));
        (*line) = tolower((*line));
        line ++;
    }
    
    //printf("\nline_tolower ok!\n");
    //puts(first);
    return;
}

bool word_extract(char **ptr, char *word)//改变ptr到跳过单词，且未找到单词返回NULL//改成返回0或1 
{
    int i = 0;
    bool flag = 0;//是否有找到单词 
    
    while(1)
    {
        if((**ptr) == '\n' || (**ptr) == '\0')
        {
            //printf("this line is over!\n");
            
            if(flag == 0)return 0;
            else return 1;//这样可以吗？ 
        }
        else if((**ptr) >= 'a' && (**ptr) <= 'z') 
        {
            word[i++] = (*(*ptr)++);//最后ptr落在单词的下一位 //注意区分++谁 
            flag = 1;//忘加 
        }
        else
        {
            if(flag)//找到了单词 
            {
                word[i] = '\0';//改完之后要加这个断尾 
                
                //puts(word);
                //printf("this word is over!\n");
                
                return 1;//return &(word[0]);出了函数就没有了，所以会访问失败，结束运行 
            }
            else (*ptr)++;//注意区分++谁 
        }
        
    }
} 

void binary_tree_insert(struct node* first, struct node* ptr)//first不能为NULL //first为当前可判断条件的最小树的起点 
{
    if(first == NULL)
    {
        printf("oh no! binary_tree_insert broken!\n");
        return;
    }
    else if(0 == strcmp(ptr->word, first->word))//strcmp写法注意 
    {
        //printf("%s\n%s\nsb\n", ptr->word, first->word);//最终对都指向同一个数组，所以一直一样，解决方案是开malloc，最后一起free掉 
        first->count += ptr->count;
        free(ptr->word);
        free(ptr);//这边不能free！！！free就会一直分配这块出问题，浪费就浪费了！！！ //其实可以，数据会覆盖，不影响 
    }
    else if(0 > strcmp(ptr->word, first->word))
    {
        if(first->left == NULL) 
        {
            first->left = ptr;
            ptr->prev = first;
            //printf("left!");
        }
        else binary_tree_insert(first->left, ptr);
    }
    else
    {
        if(first->right == NULL)
        {
            first->right = ptr;
            ptr->prev = first;
            //printf("right!");
        }
        else binary_tree_insert(first->right, ptr);
    }
}

struct node* binary_tree_create()
{
    struct node *first = NULL;//没初始化为NULL，访问失败，运行结束 
    char buf[1005] = {'\0'};
    FILE *in = NULL;
    
    if((in = fopen("article.txt", "r")) == NULL)//一定要加括号！！！！！，不加的话'=='优先级大于 '='；报错情况一样但赋值为NULL
    {
        printf("failed to open r_file\n");
        return 1; // @@ [The function returns an integer (1) but the return type is struct node*. This causes a type mismatch and likely a compilation error. Should return NULL instead.]
    }
    
    while(fgets(buf, 1000, in) != NULL)
    {
        line_tolower(buf);//数组传地址，可改变存储的字符 
         
        char *ptr1 = buf;
        
        while(1)//ptr动，返回NULL时终止
        {
            char* word = (char*)malloc(sizeof(char) * 35);
            if(word_extract(&ptr1, word) == 0)break;//要加==0 
            
            struct node *ptr = (struct node *)malloc(sizeof(struct node));//用重名了 
            ptr->prev = NULL;
            ptr->left = NULL;
            ptr->right = NULL;
            ptr->word = word;//可以这样 
            ptr->count = 1;
            
            if(first == NULL) first = ptr;
            else binary_tree_insert(first, ptr);//包含如果相同则并项的操作 
        }
    }

    fclose(in);
    in = NULL;
    
    //printf("binary_tree_create ok!\n");
    return first;
}

void binary_tree_output(struct node* ptr)
{
    if(ptr == NULL)
    {
        //printf("binary_tree_output ok!\n");这里也不大行 
        return;
    }
    binary_tree_output(ptr->left);
    printf("%s %d\n", ptr->word, ptr->count);
    binary_tree_output(ptr->right);
}

void binary_tree_free(struct node** ptr)//有问题！！！ 
{
    if((*ptr) == NULL)
    {
        //printf("binary_tree_free ok!\n");
        return;
    }
    binary_tree_free((*ptr)->left);//没改 
    binary_tree_free((*ptr)->right);//没改 
    free((*ptr)->word);
    free((*ptr));
    (*ptr) = NULL;
}

int main()
{
    struct node* first = binary_tree_create();
    
    binary_tree_output(first);
    //printf("binary_tree_output ok!\n");
    
    //binary_tree_free(&first);//需要改变实参，递归方便，不用传before参，或者写判断下一层的逻辑 //有问题 
    //printf("binary_tree_free ok!\n");
    
    return 0;
}