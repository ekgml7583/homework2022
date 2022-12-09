#define _CRT_SECURE_NO_sWARNINGS
#include <stdio.h>
#include <stdlib.h>


#define N 7
#define M 8

void r_Table(double(*r)[M]);
void c_Table(double(*c)[M]);
void w_Table(double(*w)[M]);
double minn(int i, int j, double(*c)[M], double(*w)[M], int(*r)[M]);


typedef struct node
{
	int data;
	struct node* left;
	struct node* right;

}NODE;

NODE* newNode(int data)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));

	node->data = data;

	node->left = NULL;
	node->right = NULL;
	return(node);
}






int main(void) {
	int i, j, l;
	
	//p값, q값, weight table, cost table, root table 초기화
	double p[M] = { 0.0,0.1,0.09,0.06,0.05,0.05,0.04,0.03 };
	double q[M] = { 0.07,0.12,0.07,0.07,0.06,0.05,0.08,0.06};
	double w[M][M] = { 0, };
	double c[M][M] = { 0,  };
	int r[M][M] = { 0, };

	for (i = 0; i < M; i++) {
		printf("%.3lf\n",q[i]);
		printf("\n");
	}
	
	//weight,cost 테이블 초기화하기
	for (i = 0; i <= N; i++) {
		w[i][i] = q[i];
		c[i][i] = 0;
	}
	for (i = 0; i <= N; i++) {
		printf("%.3lf\n", w[i][i]);
	}
	for (i = 0; i <= N; i++) {
		printf("%.3lf\n", c[i][i]);
	}

	//weight, cost 테이블 계산 시작
	for (l = 1; l<= N; l++) {
		for (i = 0; i <= N - l; i++) {
			j = i + l;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			c[i][j] = minn(i,j,c,w,r);
		}
	}
	
	//weight table 출력
	w_Table(w);

	//cost table 출력
	c_Table(c);


	//root table 출력
	r_Table(r);



	//tree 출력
	NODE* root = newNode(4);

	root->left=

		getchar();

	return 0;


}


//cost table 이용해 root 값도 저장
double minn(int i, int j, double(*c)[M], double(*w)[M], int(*r)[M]) {
	
	int k;
	double result;
	double min;

	min = c[i][i] + c[i + 1][j] + w[i][j];
	r[i][j] = i + 1;
	for (k = i+1; k <= j; k++) {

		result = c[i][k - 1] + c[k][j] + w[i][j];
		if (min > result) {
			min = result;
			r[i][j] = k;
		}

	}
	return min;

}



//weight table
void w_Table(double(*w)[M]) {
	int i, j, k;
	printf("-------------------weightTable-------------------\n");
	for (i = 0; i < N + 1; i++) {
		for (k = 0; k < i; k++)
			printf("|      ");
		for (j = 0; j < M - k; j++) {
			if (i > 0)
				printf("|%6.2lf",w[i][j + i]);
			else {

				printf("|%6.2lf", w[i][j]);
			}
		}
		printf("|\n");
		printf("---------------------------------------------------------\n");
	}
}


//cost table 
void c_Table(double(*c)[M]) {
	int i, j, k;
	printf("-------------------costTable-------------------\n");
	for (i = 0; i < N + 1; i++) {
		for (k = 0; k < i; k++)
			printf("|      ");
		for (j = 0; j < M - k; j++) {
			if (i > 0)
				printf("|%6.2lf", c[i][j + i]);
			else {

				printf("|%6.2lf", c[i][j]);
			}
		}
		printf("|\n");
		printf("---------------------------------------------------------\n");
	}
}



//root table 
void r_Table(int(*r)[M]) {
	
	int i, j, k;

	printf("-------------------rootTable-------------------\n");
	for (i = 0; i < N + 1; i++) {
		for (k = 0; k < i; k++)
			printf("|      ");
		for (j = 0; j < M - k; j++) {
			if (i > 0)
				printf("|%5d", r[i][j + i]);
			else {

				printf("|%5d", r[i][j]);
			}
		}
		printf("|\n");
		printf("-------------------------------------------------------\n");
	}
}

