#include <stdio.h>
#include <malloc.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
 int g1, g2, g3, g4, g5, n=15; 
struct term
{
	int coef, exp;
	struct term *next;
};
 
void term_multi_term(struct term *term1, struct term *term2, struct term *term_rst)
{//this function calculates the result of term1*term2, which is stored in term_rst
	term_rst->coef = (term1->coef)*(term2->coef);
		for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
	term_rst->exp = (term1->exp)+(term2->exp);
}
 
void poly_multi_term(struct term *poly1, struct term *term2, struct term *poly_rst)
{//this function calculates the result of polynomial1*term2, which is stored in poly_rst
	struct term *polyterm_p = poly1, *rstterm_p = poly_rst;
	//polyterm_p always points to the current term in poly1 to be multipled by term2.
	//rstterm_p always points to the term which is the result from the comment above.
	for (;;)
	{
		if (polyterm_p->next != NULL)
		{
			term_multi_term(polyterm_p, term2, rstterm_p);
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			rstterm_p->next= (struct term *)malloc(sizeof(struct term));
			rstterm_p = rstterm_p->next;
			polyterm_p = polyterm_p->next;
		}
		else
		{
			term_multi_term(polyterm_p, term2, rstterm_p);
			rstterm_p->next = NULL;
			break;
		}
	}
}
 
struct term *merge_polys(struct term *poly1, struct term *poly2)
{//this function merges two polynomials into one, as well as cancelling the redundant terms after merging.
	struct term *poly_rst=poly1, *poly1_p_tmp=poly1,*poly2_p_tmp=poly2, *poly_rst_p_tmp=poly1;
	//poly_rst points to the head node of the resultant polynomial
	//poly1_p_tmp points to the current term in poly1 to be compared
	//poly2_p_tmp points to the current term in poly2 to be compared
	//poly_rst_p_tmp points to the term in the resultant polynomial formed in the latest comparison
	if (poly1_p_tmp->exp > poly2_p_tmp->exp)
	{//if the head node of poly1 has larger exponent, it means the first term in resultant should be that
		poly_rst = poly1;
			for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
		poly_rst_p_tmp = poly1;
		poly1_p_tmp = poly1_p_tmp->next;
	}
	else if (poly1_p_tmp->exp < poly2_p_tmp->exp)
	{//similarly in poly2
		poly_rst = poly2;
		poly_rst_p_tmp = poly2;
		poly2_p_tmp = poly2_p_tmp->next;
	}
	else if (poly1_p_tmp->exp == poly2_p_tmp->exp)
	{//if the two head terms are equal, merge this two terms and take the resultant term as the first
     //meanwhile cancel the redundant term after adding the coef of the first term in poly2 to that of poly1
		poly_rst = poly1;
			for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
		poly1_p_tmp->coef += poly2_p_tmp->coef;
		poly_rst_p_tmp = poly1;
		poly1_p_tmp = poly1_p_tmp->next;
		struct term *tmp = poly2_p_tmp;
		poly2_p_tmp = poly2_p_tmp->next;
		free(tmp);
	}
 
	while (poly1_p_tmp != NULL&&poly2_p_tmp != NULL)
	{//similar for other terms as in the first term
		if (poly1_p_tmp->exp > poly2_p_tmp->exp)
		{
			poly_rst_p_tmp->next = poly1_p_tmp;
			poly_rst_p_tmp = poly1_p_tmp;
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			poly1_p_tmp = poly1_p_tmp->next;
		}
		else if (poly1_p_tmp->exp < poly2_p_tmp->exp)
		{
			poly_rst_p_tmp->next = poly2_p_tmp;
			poly_rst_p_tmp = poly2_p_tmp;
			poly2_p_tmp = poly2_p_tmp->next;
		}
		else if (poly1_p_tmp->exp == poly2_p_tmp->exp)
		{
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			poly1_p_tmp->coef += poly2_p_tmp->coef;
			poly_rst_p_tmp->next = poly1_p_tmp;
			poly_rst_p_tmp= poly1_p_tmp;
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			poly1_p_tmp = poly1_p_tmp->next;
			struct term *tmp = poly2_p_tmp;
			poly2_p_tmp = poly2_p_tmp->next;
			free(tmp);
		}
	}
 
	poly_rst_p_tmp->next = (poly1_p_tmp != 0) ? poly1_p_tmp : poly2_p_tmp;
	//no necessity to alter the remaining terms 
	return poly_rst;
}
 
struct term *poly_multi_poly(struct term *poly1, struct term *poly2)
{//this function calculates polynomial1*polynomial2 and return the pointer to the first node of the resultant polynomial
	struct term *term2_p_tmp = poly2;
	//term2_p_tmp points to the current term in poly2 to be multipled by poly1
	struct term *poly_p_rst = (struct term *)malloc(sizeof(struct term));
	poly_multi_term(poly1, term2_p_tmp, poly_p_rst);
	//poly_p_rst points to the first term in the final resultant polynomial (after all the merging)
	struct term *poly_p_tmp = (struct term *)malloc(sizeof(struct term));
	//poly_p_tmp points to the first term in poly1*(*term2_p_tmp)
	term2_p_tmp = term2_p_tmp->next;
	if (term2_p_tmp != NULL)
	{
		for (;;)
		{
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			poly_multi_term(poly1, term2_p_tmp, poly_p_tmp);
			poly_p_rst = merge_polys(poly_p_rst, poly_p_tmp);
			if (term2_p_tmp->next != NULL)
			{
				poly_p_tmp = (struct term *)malloc(sizeof(struct term));
				term2_p_tmp = term2_p_tmp->next;
			}
			else break;
		}
	}
	return poly_p_rst;
}
 
int main()
{
	struct term *poly1_p_head = (struct term *)malloc(sizeof(struct term));
	struct term *poly2_p_head = (struct term *)malloc(sizeof(struct term));
	struct term *rst;
	struct term *term_p_tmp;
	int coef_tmp, exp_tmp, garbage1=0,garbage2,arr[233];
	char lf;
	for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
	for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=23;
	}
	for (term_p_tmp = poly1_p_head;;)
	{
		scanf("%d %d%c", &coef_tmp, &exp_tmp, &lf);
		term_p_tmp->coef = coef_tmp;
		term_p_tmp->exp = exp_tmp;
 for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
		if (lf != '\n')
		{
			term_p_tmp->next = (struct term *)malloc(sizeof(struct term));
			term_p_tmp = term_p_tmp->next;
		}
		else
		{
			term_p_tmp->next = NULL;
			break;
		}
	}
 for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
	for (term_p_tmp = poly2_p_head;;)
	{
		scanf("%d %d%c", &coef_tmp, &exp_tmp, &lf);
		term_p_tmp->coef = coef_tmp;
		term_p_tmp->exp = exp_tmp;
 
		if (lf != '\n')
		{
				for(g1=0;g1<n;g1++)
	{
		for(g2=0;g2<n;g2++)
		{
			g3=1;
			g4=g3;
			g5=g4;
			g3=g5;
		}
	}
			term_p_tmp->next = (struct term *)malloc(sizeof(struct term));
			term_p_tmp = term_p_tmp->next;
		}
		else
		{
			term_p_tmp->next = NULL;
			break;
		}
	}
 for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
	rst = poly_multi_poly(poly1_p_head, poly2_p_head);
	while (rst != NULL)
	{
		printf("%d %d ",rst->coef,rst->exp);
		rst = rst->next;
	}
 for(garbage1=0;garbage1<23;garbage1++)
	{
		garbage2=233;
	}
	return 0;
}

