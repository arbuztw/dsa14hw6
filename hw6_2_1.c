#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "bst.h"
#include "rb.h"

typedef struct
{
	char data[10];
} Str;

void preorder_str_avl(const struct avl_node *node)
{
	if (!node) return ;
	
	
	printf("%s ", ((Str *)node->avl_data)->data);
	if (node->avl_link[0] || node->avl_link[1])
	{
		putchar('(');
		preorder_str_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		preorder_str_avl(node->avl_link[1]);
		putchar(')');
	}
}

void preorder_str_bst(const struct bst_node *node)
{
	if (!node) return ;
	
	
	printf("%s ", ((Str *)node->bst_data)->data);
	if (node->bst_link[0] || node->bst_link[1])
	{
		putchar('(');
		preorder_str_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		preorder_str_bst(node->bst_link[1]);
		putchar(')');
	}
}

void preorder_str_rb(const struct rb_node *node)
{
	if (!node) return ;
	
	
	printf("%s ", ((Str *)node->rb_data)->data);
	if (node->rb_link[0] || node->rb_link[1])
	{
		putchar('(');
		preorder_str_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		preorder_str_rb(node->rb_link[1]);
		putchar(')');
	}
}

int int_compare(const void *pa, const void *pb, void *param)
{
	int a = *(const int *)pa;
	int b = *(const int *)pb;

	if (a < b) return -1;
	else if (a > b) return 1;
	else return 0;
}

int str_compare(const void *p1, const void *p2, void *param)
{
	return strcmp(((const Str *)p1)->data, ((const Str *)p2)->data);
}

int main()
{
	char names[32][10] = {
		"Chuang", "Chou", "Chang", "Chao", "Chen", "Cheng", "Chu", "Fu", "Fuh", "Hsiang", "Hsu", "Hsueh", "Hung", 
		"Jang", "Kao", "Kuo", "Lai", "Lee", "Liao", "Lin", "Liou", "Liu", "Lu", "Lyuu", "Ouhyoung", "Oyang", "Shih", 
		"Tsai", "Tseng", "Wang", "Wu", "Yang" };
	struct avl_table *atree;
	struct bst_table *btree;
	struct rb_table  *rtree;

	atree = avl_create(str_compare, NULL, NULL);
	btree = bst_create(str_compare, NULL, NULL);
	rtree = rb_create(str_compare, NULL, NULL);

	int i;
	for (i = 0; i < 32; i++)
	{
		Str *ele = (Str *)malloc(sizeof(Str));
		strcpy(ele->data, names[i]);
		avl_probe(atree, ele);
		bst_probe(btree, ele);
		rb_probe(rtree, ele);
	}

	preorder_str_avl(atree->avl_root);
	puts("");
	preorder_str_bst(btree->bst_root);
	puts("");
	preorder_str_rb(rtree->rb_root);
	puts("");

	return 0;
}
