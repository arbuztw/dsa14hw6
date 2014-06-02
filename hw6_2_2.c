#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_ntudsa.h"
#define N 1000005

typedef struct
{
	char name[25];
	int score[5];
	int avg;
} Student;

void inorder(const struct avl_node *node, int check, int idx)
{
	if (!node) return ;
	inorder(node->avl_link[0], node->avl_cnode[0], idx*2+1);
	inorder(node->avl_link[1], node->avl_cnode[1], idx*2+2);
}

Student *findRank(const struct avl_node *node, int r)
{
	int c = node->avl_cnode[0];
	if (r == c + 1)
		return (Student *)node->avl_data;
	else if (r <= c)
		return findRank(node->avl_link[0], r);
	else
		return findRank(node->avl_link[1], r - c - 1);

}

int cmp(const void *pa, const void *pb, void *param)
{
	const Student *a = (const Student *)pa;
	const Student *b = (const Student *)pb;


	if (a->avg != b->avg) return -(a->avg - b->avg);
	else if (a->score[1] != b->score[1]) return -(a->score[1] - b->score[1]);
	else if (a->score[2] != b->score[2]) return -(a->score[2] - b->score[2]);
	else if (a->score[4] != b->score[4]) return -(a->score[4] - b->score[4]);
	else if (a->score[3] != b->score[3]) return -(a->score[3] - b->score[3]);
	else if (a->score[0] != b->score[0]) return -(a->score[0] - b->score[0]);
	else return strcmp(a->name, b->name);
}

int main()
{
	int i, x, cnt = 0, sum;
	char cmd[10];
	struct avl_table *tree = avl_create(cmp, NULL, NULL);
	Student *s;

	while (~scanf("%s", cmd))
	{
		cnt++;
		if (cmd[0] == 'p')
		{
			s = (Student *)malloc(sizeof(Student));
			scanf("%s", s->name);
			sum = 0;
			for (i = 0; i < 5; i++)
			{
				scanf("%d", &s->score[i]);
				sum += s->score[i];
			}
			s->avg = sum / 5;
			avl_probe(tree, s);
		}
		else
		{
			scanf("%d", &x);
			s = findRank(tree->avl_root, x);
			printf("%s\n", s->name);
		}
	}
	return 0;
}
