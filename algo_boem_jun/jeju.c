#include <stdio.h>
#define MAX_POINT 35
#define DAY_MAX 540

struct Point
{
	char info;
	int satis_point;
	int play_time;
	int dis[MAX_POINT];
	bool visit;
};

struct Res
{
	int pointnum;
	int res_satis;
	int res_time;
};
//int num_point, rest_time; //지점 갯수, 휴가기간
int N, DAY, AIRPORT_POINT, HOTEL;
int day_time, res_time, res_satis;
//int res_arr[MAX_POINT];


struct Res result[MAX_POINT];
struct Point point[MAX_POINT];

void init()
{
	int i, j;
	for (i = 0;i<MAX_POINT;i++) {
		result[i].pointnum = 0;
		result[i].res_satis = 0;
		result[i].res_time = 0;
		point[i].info = 'x';
		point[i].satis_point = point[i].play_time = 0;
		point[i].visit = false;
		for (j = 0;j<MAX_POINT;j++) {
			point[i].dis[j] = 0;
		}
	}
}

void test_print(int tc, int num_point)
{
	printf("%d 번째 케이스 \n ", tc);
	for (int i = 0; i<num_point; i++)
	{
		printf("[%d] 번 지점 \t", i);
		printf("info : %c\t", point[i].info);
		printf("visit : %d\t", point[i].visit);
		printf("satis : %d\t", point[i].satis_point);
		printf("playtime : %d \n", point[i].play_time);
		for (int j = 0; j <num_point;j++) {
			printf("[%d] ", point[i].dis[j]);
		}
		printf("\n");
	}
}

void print_result(int depth)
{
	int i;
	for (i = 0;i<depth;i++)
	{
		printf("%d ", result[i].pointnum);
	}
	printf(" \n");
}

bool check_visit()
{
	int i;
	bool res = 1;
	for (i=0;i<N ;i++)
	{
		res = res * point[i].visit;
	}
	return res;
}

int solution(int depth, int now_point, int day, int time, int satis)
{
	int i;
	int s_day = day;
	int d_time = time;
	int s_satis = satis;

	//printf("time : %d\n",time);
	if (d_time > 540) return 0;
	if (s_day > DAY) return 0;
	//depth가 0인경우 항상 공항이니, Result[0]을 채움,
	if (depth == 0)
	{
		result[depth].pointnum = AIRPORT_POINT;
		result[depth].res_satis = 0;
		result[depth].res_time = 0;
		s_day++; //처음공항인 경우 날짜를 +1 해줌.
		point[AIRPORT_POINT].visit = true;
		//solution(depth + 1, 0, s_day, d_time, s_satis);
		depth++;
	}
	else if (point[now_point].info == 'A') //depth가 0이 아니고, 공항이라면? == 항상 마지막(여행의 끝.)
	{
		if (day != DAY) return 0 ;
		if (!check_visit()) return 0;
		print_result(depth);
		printf("satis : %d",satis);
		return 0;
	}

	//종단점
	//if ((day > DAY) && point[now_point].info == 'A') print_result(depth);




	for (i = 0;i<N;i++) {
		//지금 온 곳이 포인트이면서, 이미 간 곳이면 countinue
		if (point[i].info == 'P' && point[i].visit == true) continue;
		else if (point[i].info == 'P' && point[i].visit == false)//지금 온 곳이 포인트 이면(아직 안간 곳이면)
		{
			d_time += point[i].play_time + point[i].dis[result[depth-1].pointnum];
			s_satis += point[i].satis_point;
			point[i].visit = true;//간 곳으로 표시 하고,
			result[depth].pointnum = i;		//현 위치 포인트를 기록
			solution(depth + 1, i, s_day, d_time, s_satis);
			point[i].visit = false;//간 곳으로 표시 하고,
		}

		//지금온 곳이 호텔이면,
		if (point[i].info == 'H')
		{
			s_day++;
			d_time = 0;
			point[i].visit = true;//간 곳으로 표시 하고,
			result[depth].pointnum = i;		//현 위치 포인트를 기록
			solution(depth + 1, i, s_day, d_time, s_satis);
			
		}

	}


	return 0;
}


int main() {
	int T, tc;
	init();
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &DAY);

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int t; scanf("%d", &t); // 지점간의 거리 setting
				point[i].dis[j] = point[j].dis[i] = t;
			}
		}

		for (int i = 0; i < N; i++) {
			char c; scanf(" %c", &c);
			point[i].info = c;
			if (c == 'A') {
				AIRPORT_POINT = i;
				point[i].play_time = 0;
				point[i].satis_point = 0;
			}
			else if (c == 'P') {
				int t, s; scanf("%d %d", &t, &s);
				point[i].play_time = t;
				point[i].satis_point = s;
			}
			else if (c == 'H') {
				HOTEL = i;
				point[i].play_time = 0;
				point[i].satis_point = 0;
			}
		}
		test_print(tc, N);
		res_time = 0; res_satis = 0;
		solution(0, 0, 0, 0, 0);
		//getchar();
	}



	getchar();
	return 0;
}
