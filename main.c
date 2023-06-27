#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//配列表示関数
void printArray(int* a, int n) {
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
	//0～9の乱数を重複しないように配列にセットさせ、表示させる
	printf("元配列：");
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 10;
		//重複チェックさせる(前提：Nが10以下であること！)
		for (int j = 0; j < i; j++) {
			//重複していた
			if (a[j] == a[i]) {
				//次に進まないようにiを減らしておく
				i--;
				break;
			}
		}
	}
	printArray(a, N);

	/*---------------------------------------------------------------------*/
	//とある数が配列に存在するか探索する
	printf("探　索：");
	int number = rand() % 10;
	int index = -1;
	for (int i = 0; i < N; i++) {
		if (number == a[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("%dは配列にない\n", number);
	}
	else {
		printf("%dは配列の%d番にある\n", number, index);
	}

	/*---------------------------------------------------------------------*/
	//小さい順に並びかえさせ、表示させる
	printf("ソート：");
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int w = a[i];
				a[i] = a[j];
				a[j] = w;
			}
		}
	}
	printArray(a, N);

	/*---------------------------------------------------------------------*/
	//逆順に並び変えさせ、表示させる
	printf("ﾘﾊﾞｰｽ ：");
	int i = 0;
	int j = N - 1;
	while (i < j) {
		int w = a[i];
		a[i] = a[j];
		a[j] = w;
		i++;
		j--;
	}
	printArray(a, N);

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
	average = total / (float)N;
	printf("合  計：%d\n", total);
	printf("平　均：%.2f\n", average);

	system("pause>0");
}