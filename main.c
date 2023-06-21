#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//�z��\���֐�
void print(const char* thema, int* a, int n) {
	printf("%s", thema);
	for (int i = 0; i < n; i++) {
		printf("%d,", a[i]);
	}
	printf("\n");
}
//�z��v�f��N
#define N 5
int main() {
	/*---------------------------------------------------------------------*/
	//�z��a��p�ӂ���Ba��array�̗��B
	int a[N] = { 0 };

	/*---------------------------------------------------------------------*/
	//0�`9�̗�����z��ɃZ�b�g�����A�\��������
	srand((unsigned)time(0));
	a[0] = rand() % 10;
	for (int i = 1; i < N; i++) {
		a[i] = rand() % 10;
		//�d���`�F�b�N������(�O��FN��10�ȉ��ł��邱�ƁI)
		int j = 0;
		while (j < i) {
			for (j = 0; j < i; j++) {
				//�d�����Ă�����A�ēx�������Z�b�g�����Afor���[�v�r���Ŕ���������
				if (a[j] == a[i]) {
					a[i] = rand() % 10;
					break;
				}
			}
			//�d�����Ă��Ȃ�����j==i�ƂȂ�B�d�����Ă���Ƃ���j<i�ƂȂ�ă`�F�b�N�I
		}
	}
	print("���z��F", a, N);

	/*---------------------------------------------------------------------*/
	//���������ɕ��т��������A�\��������
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int w = a[i];
				a[i] = a[j];
				a[j] = w;
			}
		}
	}
	print("�\�[�g�F", a, N);

	/*---------------------------------------------------------------------*/
	//�t���ɕ��ѕς������A�\��������
	int i = 0;
	int j = N - 1;
	while (i < j) {
		int w = a[i];
		a[i] = a[j];
		a[j] = w;
		i++;
		j--;
	}
	print("�t�@���F", a, N);

	/*---------------------------------------------------------------------*/
	//�ő�l�E�ŏ��l�����߂����A�\��������
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
	printf("�ő�l�F%d\n", max);
	printf("�ŏ��l�F%d\n", min);

	/*---------------------------------------------------------------------*/
	//���v�E���ς����߂����A�\��������
	int total = 0;
	float average = 0;
	for (int i = 0; i < N; i++) {
		total += a[i];
	}
	average = (float)total / N;
	printf("��  �v�F%d\n", total);
	printf("���@�ρF%.2f\n", average);

	system("pause>0");
}