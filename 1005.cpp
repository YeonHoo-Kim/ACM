// 1005번

// 위상정렬(Topological Sort)을 이용하는 문제
// 위상정렬의 경우 Cycle 이 없는 경우 사용 가능!!
// 인접리스트를 vector 로 구현하고(suc), 들어오는 간선갯수 정보를 구현하여(pre)
// 큐(Queue)에 pre[노드]=0 인 노드부터 push 하고, pop 했을 때 해당 노드의 정보를 받아와 이와 연결된 노드에 대해서도 pre를 점차 줄여나가면서 pre 값이 0이 되면 다시 push 한다.

#include<cstdio>
#include<vector>
using namespace std;

typedef struct Node_ {						// 큐 생성을 위한 노드

	int data;
	struct Node_* next;

}Node;

typedef struct Queue_ {						// 큐 구조

	Node* front;
	Node* rear;
	int count;

}Queue;

void init(Queue* q);						// 큐 초기화
int IsEmpty(Queue* q);						// 큐 비었는지 확인
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