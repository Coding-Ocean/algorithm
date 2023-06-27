#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//�z��\���֐�
void printArray(int* a, int n) {
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
	//0�`9�̗������d�����Ȃ��悤�ɔz��ɃZ�b�g�����A�\��������
	printf("���z��F");
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 10;
		//�d���`�F�b�N������(�O��FN��10�ȉ��ł��邱�ƁI)
		for (int j = 0; j < i; j++) {
			//�d�����Ă���
			if (a[j] == a[i]) {
				//���ɐi�܂Ȃ��悤��i�����炵�Ă���
				i--;
				break;
			}
		}
	}
	printArray(a, N);

	/*---------------------------------------------------------------------*/
	//�Ƃ��鐔���z��ɑ��݂��邩�T������
	printf("�T�@���F");
	int number = rand() % 10;
	int index = -1;
	for (int i = 0; i < N; i++) {
		if (number == a[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("%d�͔z��ɂȂ�\n", number);
	}
	else {
		printf("%d�͔z���%d�Ԃɂ���\n", number, index);
	}

	/*---------------------------------------------------------------------*/
	//���������ɕ��т��������A�\��������
	printf("�\�[�g�F");
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
	//�t���ɕ��ѕς������A�\��������
	printf("��ް� �F");
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
	average = total / (float)N;
	printf("��  �v�F%d\n", total);
	printf("���@�ρF%.2f\n", average);

	system("pause>0");
}