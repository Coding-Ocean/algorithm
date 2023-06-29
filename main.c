#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void setRandomArray(int* a, int n) {
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
		//重複チェック
		for (int j = 0; j < i; j++) {
			if (a[j] == a[i]) {
				i--;//iが次に進まないよう減算しておく
				break;//jのループを終了させ、再度、乱数セットへ
			}
		}
	}
	printArray(a, n);
}
int total(int* a, int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i];
	}
	return total;
}
float average(int* a, int n) {
	return total(a, n) / (float)n;
}
int maxOfArray(int* a, int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
int minOfArray(int* a, int n) {
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
void search(int number, int* a, int n) {
	int index = -1;
	//探索ループ
	for (int i = 0; i < n; i++) {
		if (a[i] == number) {
			index = i;
			break;//ループ途中で抜ける
		}
	}
	//探索結果
	if (index == -1) {
		printf("%dは配列にない\n", number);
	}
	else {
		printf("%dは配列の%d番にある\n", number, index);
	}
}
void swap(int* a, int* b) {
	int w = *a;
	*a = *b;
	*b = w;
}
void reverse(int* a, int n) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		swap(&a[left], &a[right]);
		left++;
		right--;
	}
	printArray(a, n);
}
void sort(int* a, int n) {
	/*
	n==5の時の、iとｊの変化の仕方
	0 1 2 3 4
	i j j j j
	  i j j j
	    i j j
		  i j
	*/
	for (int i = 0; i < n-1; i++) {
		//iの位置に最小値を持ってくる
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(&a[i], &a[j]);
			}
		}
	}
	printArray(a, n);
}

#define NUM 5
int main() {
	int a[NUM] = { 0 };
	printf("配　列："); setRandomArray(a, NUM);
	printf("合　計：%d\n", total(a, NUM));
	printf("平　均：%f\n", average(a, NUM));
	printf("最大値：%d\n", maxOfArray(a, NUM));
	printf("最小値：%d\n", minOfArray(a, NUM));
	printf("探　索："); search(rand()%10, a, NUM);
	printf("ﾘﾊﾞｰｽ ："); reverse(a, NUM);
	printf("ソート："); sort(a, NUM);
	system("pause>0");
}