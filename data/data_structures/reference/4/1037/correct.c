#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LL long long

struct NODE{
	int cnt,letter;
	int sons[26];
}tree[1000];

int t_cnt, root, s_len, w_len;
char input[100000], word[1000];

int is_letter(char x){
	if (x >= 'a' && x <= 'z')return 1;
	if (x >= 'A' && x <= 'Z')return 1;
	return 0;
}

char change(char x){
	if (x >= 'A' && x <= 'Z')return (x-'A')+'a';
	return x;
}

void read_letter(int st, int ed){
	int cur_node = root;
	for (int i = st; i <= ed; i++){
//		putchar(input[i]);
		int u = input[i];
		if (tree[cur_node].sons[u-'a'] == 0){
			tree[cur_node].sons[u-'a'] = t_cnt;
			cur_node = t_cnt;
			t_cnt++;
		}
		else {
			cur_node = tree[cur_node].sons[u-'a'];
		}
		tree[cur_node].letter = u;
		if (i == ed){
//			printf("%c ++ node=%d\n",u, cur_node);
			tree[cur_node].cnt++;
//			printf("tree[%d].cnt = %d\n",cur_node,tree[cur_node].cnt);
		}
	}
//	putchar(' ');
}

void dfs(int u){
//	if (u != root){
//		printf("u=%d letter=[%c] cnt=%d\n", u, tree[u].letter, tree[u].cnt);
//		printf("tree[%d].cnt = %d\n",u,tree[u].cnt);
//	}
	if (tree[u].cnt > 0){
		printf("%s %d\n", word, tree[u].cnt);
	}
	for (int i = 0; i < 26; i++){
		if (tree[u].sons[i] != 0){
			word[w_len++] = 'a'+i;
			dfs(tree[u].sons[i]);
			w_len--;
			word[w_len] = 0;
		}
	}
}

int main(){
	root = 0;
	t_cnt = 1;
	freopen("article.txt", "r", stdin);
	char ch;
	input[s_len++] = ' ';
	while ((ch = getchar()) != EOF){input[s_len++] = change(ch);}
	input[s_len++] = ' ';
	int pre=-1, cur=-1;
	for (int i = 0; i < s_len; i++){
		if (!is_letter(input[i])){
			pre = cur;
			cur = i;
			if (pre != -1 && cur - pre > 1){
				read_letter(pre+1, cur-1);
			}
		}
	}
	dfs(root);
	fclose(stdin);
//	printf("%d", tree[root].sons['e'-'a']);
	return 0;
}
