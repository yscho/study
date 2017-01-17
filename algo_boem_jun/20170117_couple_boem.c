#include <stdio.h>

#define ABS(A) ((A) < 0 ? -(A) : (A))

#define N_MAX 10

typedef struct _Pos {
   int x, y;
} Pos;

int ans;
int N;
Pos person[N_MAX];
Pos dest[N_MAX];
bool visit[N_MAX];

int getDist(Pos &p1, Pos &p2) {
   return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}

void solve(int dist, int n) {
   if (dist > ans) {
      return;
   }

   if (n == N) {
      ans = dist;
   }

   for (int i = 0; i < N; i++) {
      if (visit[i]) {
         continue;
      }

      visit[i] = true;
      solve(dist + getDist(person[n], dest[i]), n + 1);
      visit[i] = false;
   }
}

int main() {
   freopen("input.txt", "r", stdin);

   int T; scanf("%d", &T);
   for (int tc = 1; tc <= T; tc++) {
      scanf("%d", &N);
      
      for (int i = 0; i < N; i++) {
         int x, y; scanf("%d %d", &x, &y);
         person[i] = { x, y };
      }

      for (int i = 0; i < N; i++) {
         int x, y; scanf("%d %d", &x, &y);
         dest[i] = { x, y };
         visit[i] = false;
      }

      ans = 0x7fffffff;
      solve(0, 0);

      printf("#%d %d\n", tc, ans);
   }
   return 0;
}
