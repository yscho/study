#include <stdio.h>                                                                                    
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 2

struct xy{
	int x;
	int y;
};

struct information
{
	char home_name;
	char box_name;
	struct xy home_xy;
	struct xy box_xy;
	int count;
};

struct resurt_t
{
	char res_c[MAX_NUM * 3];
	int now_dis[MAX_NUM * 3];
};
struct information infor_arr[MAX_NUM] = { 0 };
struct xy now;
struct xy start_point;
struct xy before_point;
struct resurt_t res;
int MIN_DIS, NOW_DIS;


//int res[MAX_NUM * 3] = { 0 };
//char res_c[MAX_NUM * 3] = { 0 };
// count[MAX_NUM] = { 0 };

void add_info(int arr, char a, char b, int a_x, int a_y, int b_x, int b_y)
{
	infor_arr[arr].home_name = a;
	infor_arr[arr].home_xy.x = a_x;
	infor_arr[arr].home_xy.y = a_y;
	infor_arr[arr].box_name = b;
	infor_arr[arr].box_xy.x = b_x;
	infor_arr[arr].box_xy.y = b_y;
	infor_arr[arr].count = 0;
}


void set_now_xy(struct xy next)
{
	before_point.x = now.x;
	before_point.y = now.y;
	now.x = next.x;
	now.y = next.y;
}

void init_info() // 입력값을 받아와 배열에 정보를 넣어 주는 함수.
{
	
	add_info(0, 'a', '1', 1, 1, 2, 0);
	add_info(1, 'b', '2', 3, 4, 4, 3);

	//처음 입력으로 주는 원점(나의 위치)
	now.x = 0;	now.y = 0;
	start_point.x = 0; start_point.y = 0;
	//set_now_xy(0, 0);

	MIN_DIS = 0; NOW_DIS = 0;
}

int calc_distance(struct xy next)
{
	int res = 0;
	if (now.x > next.x) res = now.x - next.x;
	else res = next.x - now.x;
	if (now.y > next.y) res += (now.y - next.y);
	else res += (next.y - now.y);
		return res;
}

int solution(int depth)
{
	int i,j;

	if (MIN_DIS != 0 && (res.now_dis[depth-1] > MIN_DIS)) {
		set_now_xy(before_point);
		return;
	}
	if (depth == MAX_NUM * 3)
	{
		
		for (j = 0; j < depth; j++){
			//count[j] = 0;
			printf("%c  ",res.res_c[j]);
		}
		
		printf("\n");
		for (j = 0; j < depth; j++){
			//count[j] = 0;
			printf("%d  ", res.now_dis[j]);
		}
		printf("\n");
		set_now_xy(before_point);
		//NOW_DIS = 0;
		if (MIN_DIS == 0) MIN_DIS = res.now_dis[depth - 1];
		else if (res.now_dis[depth - 1] < MIN_DIS) MIN_DIS = res.now_dis[depth - 1];
		printf("[now : %d, min :%d]", res.now_dis[depth - 1], MIN_DIS);
		printf("\n");
		return 0;
	}
	
	for (i = 0; i < MAX_NUM; i++)
	{
		if (infor_arr[i].count == 3) continue;
		infor_arr[i].count++;
		//printf("%d ", i);
		if (infor_arr[i].count == 2) {
			if (depth == 0) {
				before_point.x = 0; before_point.y = 0;
				res.now_dis[depth] = calc_distance(infor_arr[i].box_xy);
				
			}
			else res.now_dis[depth] = res.now_dis[depth-1] + calc_distance(infor_arr[i].box_xy);
			set_now_xy(infor_arr[i].box_xy);
			res.res_c[depth] = infor_arr[i].box_name;
		}
		else{
			if (depth == 0) {
				before_point.x = 0; before_point.y = 0;
				res.now_dis[depth] = calc_distance(infor_arr[i].home_xy);
			
			}
			else res.now_dis[depth] = res.now_dis[depth - 1] + calc_distance(infor_arr[i].home_xy);
			set_now_xy(infor_arr[i].home_xy);
			res.res_c[depth] = infor_arr[i].home_name;
		}
			solution(depth + 1);
		infor_arr[i].count--;
		//init_point();
	}

	return 0;
}

int main()
{
	init_info();
	
	solution(0);


	getchar();
	return 0;
}
