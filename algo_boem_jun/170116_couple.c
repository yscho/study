#include <stdio.h>                                                                                    
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 5                                                                                     

struct ys_point{
	char name;
	int x;
	int y;
	bool visit;
};

struct couple{
	char start;
	char destination;
};

struct ys_point str_p[MAX_NUM];
struct ys_point des_p[MAX_NUM];
struct couple couple_p[MAX_NUM];
int MIN_SUM;
int IMSI_SUM;

void imsi_init_sd(int a, int index, char name ,int x, int y)
{
	if (a == 0){
		str_p[index].name = name;
		str_p[index].x = x; 
		str_p[index].y = y;
		str_p[index].visit = false;
	}
	else if (a == 1){
		des_p[index].name = name;
		des_p[index].x = x;
		des_p[index].y = y;
		des_p[index].visit = false;
	}

}
/*
int imsi_init_point()
{
	imsi_init_sd(0, 0, '1', 0, 0);
	imsi_init_sd(0, 1, '2', 2, 3);
	imsi_init_sd(0, 2, '3', 4, 5);
	imsi_init_sd(1, 0, 'a', 2, 0);
	imsi_init_sd(1, 1, 'b', 3, 2);
	imsi_init_sd(1, 2, 'c', 5, 5);
}
*/
int imsi_init_point()
{
	srand(time(NULL));
	int i;
	for (i = 0; i < MAX_NUM; i++){
		imsi_init_sd(0, i, '1' + i, rand() % 10, rand() % 10);
		imsi_init_sd(1, i, 'a' + i, rand() % 10, rand() % 10);
	}
}

int calc_distance(struct ys_point start, struct ys_point destination)
{
	int sum;
	if (start.x > destination.x) sum = start.x - destination.x;
	else sum = destination.x - start.x;

	if (start.y > destination.y) sum = sum + (start.y - destination.y);
	else sum = sum + (destination.y - start.y);

	return sum;
}

int solution(int depth)
{
	//int depth = 0;
	int i;
	//종단점
	//j = index2;
	if (depth == MAX_NUM){
		for (i = 0; i < MAX_NUM; i++){
			printf("(%c , %c) \t", couple_p[i].start, couple_p[i].destination);
		}
		MIN_SUM = IMSI_SUM;
		printf("MIN_SUM == %d\n", MIN_SUM);
		IMSI_SUM = 0;
	}
	//루틴
	for (i = 0; i < MAX_NUM; i++)
	{


			if (des_p[i].visit) continue;
			des_p[i].visit = true;
			
			
			IMSI_SUM += calc_distance(str_p[i],des_p[depth]);
			printf(" i::%d , depth::%d ,MIN::%d ,IMSI::%d\n", i, depth, MIN_SUM, IMSI_SUM);
			

			if (MIN_SUM != 0)
			{
				printf("tt\n");
				if ((MIN_SUM < IMSI_SUM)) printf("kk\n"); IMSI_SUM = 0; continue;
			}
			
			couple_p[depth].start = str_p[i].name;
			couple_p[depth].destination = des_p[depth].name;
			
			solution(depth+1);
			des_p[i].visit = false;

	}

}


int main()
{
	int MIN_SUM = 0;
	int IMSI_SUM = 0;

	imsi_init_point();

	int i, j;
	char anx[10][10] = { 0 };

	for (i = 0; i < MAX_NUM; i++)
	{
		anx[str_p[i].x][str_p[i].y] = str_p[i].name;
		anx[des_p[i].x][des_p[i].y] = des_p[i].name;
		printf("[%d]_[%c]_(%d, %d)\n", i, str_p[i].name, str_p[i].x, str_p[i].y);
		printf("[%d]_[%c]_(%d, %d)\n", i, des_p[i].name, des_p[i].x, des_p[i].y);
	}
	for (i = 0; i < 10; i++){
		printf("\t");
		for (j = 0; j < 10; j++){
			if (anx[i][j] == 0) printf("_ ");
			else printf("%c ", anx[i][j]);
		}
		printf("\n");
	}



	solution(0);
	getchar();
}
