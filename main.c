#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//配列表示関数
void print(const char* thema, int* a, int n) {
	printf("%s", thema);
	for (int i = 0; i < n; i++) {
		printf("%d,", a[i]);
	}
	printf("\n");
}
//配列要素数N
#define N 5
int main() {
	/*---------------------------------------------------------------------*/
	//配列aを用意しろ。aはarrayの略。
	int a[N] = { 0 };

	/*---------------------------------------------------------------------*/
	//0～9の乱数を配列にセットさせ、表示させる
	srand((unsigned)time(0));
	a[0] = rand() % 10;
	for (int i = 1; i < N; i++) {
		a[i] = rand() % 10;
		//重複チェックさせる(前提：Nが10以下であること！)
		int j = 0;
		while (j < i) {
			for (j = 0; j < i; j++) {
				//重複していたら、再度乱数をセットさせ、forループ途中で抜けさせる
				if (a[j] == a[i]) {
					a[i] = rand() % 10;
					break;
				}
			}
			//重複していない時はj==iとなる。重複しているときはj<iとなり再チェック！
		}
	}
	print("元配列：", a, N);

	/*---------------------------------------------------------------------*/
	//小さい順に並びかえさせ、表示させる
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int w = a[i];
				a[i] = a[j];
				a[j] = w;
			}
		}
	}
	print("ソート：", a, N);

	/*---------------------------------------------------------------------*/
	//逆順に並び変えさせ、表示させる
	int i = 0;
	int j = N - 1;
	while (i < j) {
		int w = a[i];
		a[i] = a[j];
		a[j] = w;
		i++;
		j--;
	}
	print("逆　順：", a, N);

	/*---------------------------------------------------------------------*/
	//最大値・最小値を求めさせ、表示させる
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < N; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	printf("最大値：%d\n", max);
	printf("最小値：%d\n", min);

	/*---------------------------------------------------------------------*/
	//合計・平均を求めさせ、表示させる
	int total = 0;
	float average = 0;
	for (int i = 0; i < N; i++) {
		total += a[i];
	}
	average = (float)total / N;
	printf("合  計：%d\n", total);
	printf("平　均：%.2f\n", average);

	system("pause>0");
}