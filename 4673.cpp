// 4673�� self number ��󳻱�

// �迭 ��ü�� 0���� �ʱ�ȭ�� ��
// �迭�� index �� self number �� �ƴ� ��� ���� 1�� �����Ͽ���. 
// ���� ���� 0�� �迭�� index���� ���

#include<cstdio>

int main() {

	int i = 0, self[10036] = { 0 };

	for (i = 0; i < 10000; i++)
		self[i + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10] = 1;

	for (i = 1; i <= 10000; i++)
		if (self[i] == 0)
			printf("%d\n",i);

	return 0;
}