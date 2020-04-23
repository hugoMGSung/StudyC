/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.13.
  writer - Hugo MG Sung.
*/

#include <stdio.h> 
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>

typedef struct node_type {
	int node_index;
	double data;
	struct node_type* next;
} NODE;

static int index = 0;

NODE* createNode();
NODE* insertNode(NODE* me, NODE* dt);
//NODE* find(NODE* me, int dt);
void printNode(NODE* me);
NODE* deleteNode(NODE* me, int n);

// 메인함수
int main(void) {
	// 변수 초기화
	index = 1;
	NODE* temp, * head = NULL;
	char c = 'y';
	double input;
	int input_index;

	// 링크리스트 입력 부분
	while (true) {
		printf("\n데이터 입력: ");
		scanf("%lf", &input); 
		getchar();

		temp = createNode();
		temp->data = input;
		temp->next = NULL;
		//if (!find(head, temp->data)) {
			head = insertNode(head, temp);
		//}

		printf("\n계속 리스트 추가합니까? (y/n): ");
		scanf("%c", &c); getchar();
		if (c == 78 || c == 110) { break; }
	}

	// 출력부분
	printf("\n현재 연결리스트 : "); 
	printNode(head); 
	printf("\n");
	getchar();

	// 삭제 시작
	c = 'y';
	printf("\n삭제하시겠습니까? (y/n):");
	scanf("%c", &c); getchar();

	if (c == 78 || c == 110) {}
	else {
		// 삭제파트
		c = 'y';
		while (true) {
			printf("\n지울 데이터 순번입력: ");
			scanf("%d", &input_index); getchar();
			head = deleteNode(head, input_index); 

			printf("\n계속 리스트 삭제하시겠습니까? (y/n):");
			scanf("%c", &c); getchar();
			if (c == 78 || c == 110) { break; }
		}
	}

	// 최종출력
	printf("\n최종 연결리스트 : "); 
	printNode(head); 
	printf("\n\n");

	return EXIT_SUCCESS;
}

NODE* createNode() { // 노드 생성(옵션함수)
	NODE* new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->node_index = index++;
	return new_node;
}

NODE* insertNode(NODE* me, NODE* dt) { // 노드 추가(문제내 함수)
	if (!me) { return dt; }
	me->next = insertNode(me->next, dt);
	return me;
}

//NODE* find(NODE* me, int dt) { // 노드 검색(옵션함수)
//	while (me != NULL) {
//		if (me->node_index == dt) {
//			return me;
//		}
//		else {
//			me = me->next;
//		}
//	}
//	return me;
//}

void printNode(NODE* me) { // 노드 인쇄(문제내 함수)
	while (me != NULL) {
		printf("%.2lf ", me->data);
		me = me->next;
	}
	printf("\n");
}

NODE* deleteNode(NODE* me, int index) { // 노드 삭제(문제내 함수)
	NODE* tmp;
	if (me == NULL) { return me; }

	if (me->node_index == index) {
		tmp = me;
		me = me->next;
		free(tmp);
		return me;
	}
	me->next = deleteNode(me->next, index);
	return me;
}
