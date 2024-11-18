#include <stdio.h>

#define MAX_N 15

int N;
int result[MAX_N];
bool visit[MAX_N + 1];
int ans;

int solve(int depth, int sum) {
   // 중단점
   if (sum > K) {
      return 0;
   }

   if (sum == K) {
      for (int i = 0; i < N; i++) {
         //printf("%d ", result[i]);
      }
      //printf("\n");
      return 1;
   }

   if (depth == N) {
      return 0;
   }

   // 테스트
   for (int i = 1; i <= N; i++) {
      if (visit[i]) continue;

      result[depth] = i;
      visit[i] = true;
      ans += solve(depth + 1, sum + i);
      // backtracking
      visit[i] = false;
   }
}


int main() {
   ans = 0;
   scanf("%d", &N);
   solve(0);
   printf("end\n");
   return 0;
}
