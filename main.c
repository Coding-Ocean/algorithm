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
		//�d���`�F�b�N
		for (int j = 0; j < i; j++) {
			if (a[j] == a[i]) {
				i--;//i�����ɐi�܂Ȃ��悤���Z���Ă���
				break;//j�̃��[�v���I�������A�ēx�A�����Z�b�g��
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
	//�T�����[�v
	for (int i = 0; i < n; i++) {
		if (a[i] == number) {
			index = i;
			break;//���[�v�r���Ŕ�����
		}
	}
	//�T������
	if (index == -1) {
		printf("%d�͔z��ɂȂ�\n", number);
	}
	else {
		printf("%d�͔z���%d�Ԃɂ���\n", number, index);
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
	n==5�̎��́Ai�Ƃ��̕ω��̎d��
	0 1 2 3 4
	i j j j j
	  i j j j
	    i j j
		  i j
	*/
	for (int i = 0; i < n-1; i++) {
		//i�̈ʒu�ɍŏ��l�������Ă���
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
	printf("�z�@��F"); setRandomArray(a, NUM);
	printf("���@�v�F%d\n", total(a, NUM));
	printf("���@�ρF%f\n", average(a, NUM));
	printf("�ő�l�F%d\n", maxOfArray(a, NUM));
	printf("�ŏ��l�F%d\n", minOfArray(a, NUM));
	printf("�T�@���F"); search(rand()%10, a, NUM);
	printf("��ް� �F"); reverse(a, NUM);
	printf("�\�[�g�F"); sort(a, NUM);
	system("pause>0");
}