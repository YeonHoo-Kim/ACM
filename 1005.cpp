// 1005��

// ��������(Topological Sort)�� �̿��ϴ� ����
// ���������� ��� Cycle �� ���� ��� ��� ����!!
// ��������Ʈ�� vector �� �����ϰ�(suc), ������ �������� ������ �����Ͽ�(pre)
// ť(Queue)�� pre[���]=0 �� ������ push �ϰ�, pop ���� �� �ش� ����� ������ �޾ƿ� �̿� ����� ��忡 ���ؼ��� pre�� ���� �ٿ������鼭 pre ���� 0�� �Ǹ� �ٽ� push �Ѵ�.

#include<cstdio>
#include<vector>
using namespace std;

typedef struct Node_ {						// ť ������ ���� ���

	int data;
	struct Node_* next;

}Node;

typedef struct Queue_ {						// ť ����

	Node* front;
	Node* rear;
	int count;

}Queue;

void init(Queue* q);						// ť �ʱ�ȭ
int IsEmpty(Queue* q);						// ť ������� Ȯ��
void Enqueue(Queue* q, int data);			// push
int Dequeue(Queue* q);						// pop

int main() {

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {

		int N, K, W;
		int *time, *pre;
		vector<int> suc[1000];
		scanf("%d %d", &N, &K);
		time = new int[N + 1];
		pre = new int[N + 1]();


		for (int n = 0; n < N; n++)
			scanf("%d", &time[n]);

		for (int k = 0; k < K; k++) {

			int X, Y;
			scanf("%d %d", &X, &Y);
			suc[X - 1].push_back(Y - 1);
			pre[Y - 1]++;

		}

		scanf("%d", &W);
		W--;

		int *res;
		res = new int[N + 1]();
		
		Queue *q;
		q = new Queue[N + 1];
		init(q);

		for (int i = 0; i < N; i++)
			if (pre[i] == 0)
				Enqueue(q,i);

		int need = 0;
		while (pre[W] > 0) {
			
			int f = Dequeue(q);
			for (int j = 0; j < suc[f].size(); j++) {
				pre[suc[f][j]]--;
				if (pre[suc[f][j]] == 0)
					Enqueue(q, suc[f][j]);
				need = time[f] + res[f];
				if (need > res[suc[f][j]])
					res[suc[f][j]]=need;
			}
		}
		printf("%d\n", res[W]+time[W]);
	}


	return 0;
}

void init(Queue* q) {
	
	q->front = q->rear = NULL;
	q->count = 0;

}

int IsEmpty(Queue* q) {
	
	if (q->front == NULL)
		return 1;
	else
		return 0;

}

void Enqueue(Queue* q, int data) {
	
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if (IsEmpty(q) == 1)
		q->front = n;
	else
		q->rear->next = n;
	q->rear = n;
	q->count++;
}

int Dequeue(Queue* q) {
	
	int data;
	Node* n;
	n = q->front;
	q->front = q->front->next;
	data = n->data;
	q->count--;
	free(n);
	return data;
}