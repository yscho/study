#include <stdio.h>                                                                                    
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 2

char test[MAX_NUM][3] = { 'a', '1', 'a', 'b', '2', 'b' };
//char test2[3] = { 'b', '2', 'b' };
int res[MAX_NUM * 3] = { 0 };
int count[MAX_NUM] = { 0 };


int solution(int depth)
{
	int i,j;
	if (depth == MAX_NUM * 3)
	{
		
		for (j = 0; j < depth; j++){
			//count[j] = 0;
			printf("%d ",res[j]);
		}
		printf("\n");
		return 0;
	}
	
	for (i = 0; i < MAX_NUM; i++)
	{
		if (count[i] == 3) continue;
		count[i]++;
		//printf("%d ", i);
		res[depth] = i;
		solution(depth + 1);
		count[i]--;
	}

	return 0;
}

int main()
{
	int i;
	for (i = 0; i < MAX_NUM; i++){
		count[i] = 0;
	}
	
	solution(0);


	getchar();
	return 0;
}
