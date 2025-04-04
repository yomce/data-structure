#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

//선언부
Node* List_Reverse(Node* head);

//정의부
Node* List_Reverse(Node* head)
{
	//별도의 메모리 공간을 생성하지 않고 포인터 변경을 통해 리스트 역순으로 구성한다.
	//노드를 가리키는 포인터 p,q,r 총 3개를 생성한다.
	//p는 헤드와 같은 포인터를 가지고 있고, q와 r은 초기에 null을 가리킨다.
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;
	// p가 결국 null을 가리켜 모든 노드가 q나 r로 이동했을 때 종료
	while (p != NULL)
	{
		//Step 1-1. (r<-q) : q가 가지는 값을 r에 복사한다.
		r = q;
		//Step 1-2. (q<-p) : p가 가리키는 주소가 q가 가리키는 주소가 된다.
		q = p;
		//Step 1-3. (p<-link) : p.link가 p가 되어 첫번째 노드 하나가 삭제된다.
		p = p->link;
		//Step 1-4. (q.link<-r) : r이 가리키는 주소가 q.link로 가서 이어 r 뒷부분이 q 맨뒤에 붙게된다.
		q->link = r;
	}
	return r;	//p가 reverse된 q를 리턴한다.
}