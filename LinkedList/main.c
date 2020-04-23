/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
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

// �����Լ�
int main(void) {
	// ���� �ʱ�ȭ
	index = 1;
	NODE* temp, * head = NULL;
	char c = 'y';
	double input;
	int input_index;

	// ��ũ����Ʈ �Է� �κ�
	while (true) {
		printf("\n������ �Է�: ");
		scanf("%lf", &input); 
		getchar();

		temp = createNode();
		temp->data = input;
		temp->next = NULL;
		//if (!find(head, temp->data)) {
			head = insertNode(head, temp);
		//}

		printf("\n��� ����Ʈ �߰��մϱ�? (y/n): ");
		scanf("%c", &c); getchar();
		if (c == 78 || c == 110) { break; }
	}

	// ��ºκ�
	printf("\n���� ���Ḯ��Ʈ : "); 
	printNode(head); 
	printf("\n");
	getchar();

	// ���� ����
	c = 'y';
	printf("\n�����Ͻðڽ��ϱ�? (y/n):");
	scanf("%c", &c); getchar();

	if (c == 78 || c == 110) {}
	else {
		// ������Ʈ
		c = 'y';
		while (true) {
			printf("\n���� ������ �����Է�: ");
			scanf("%d", &input_index); getchar();
			head = deleteNode(head, input_index); 

			printf("\n��� ����Ʈ �����Ͻðڽ��ϱ�? (y/n):");
			scanf("%c", &c); getchar();
			if (c == 78 || c == 110) { break; }
		}
	}

	// �������
	printf("\n���� ���Ḯ��Ʈ : "); 
	printNode(head); 
	printf("\n\n");

	return EXIT_SUCCESS;
}

NODE* createNode() { // ��� ����(�ɼ��Լ�)
	NODE* new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->node_index = index++;
	return new_node;
}

NODE* insertNode(NODE* me, NODE* dt) { // ��� �߰�(������ �Լ�)
	if (!me) { return dt; }
	me->next = insertNode(me->next, dt);
	return me;
}

//NODE* find(NODE* me, int dt) { // ��� �˻�(�ɼ��Լ�)
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

void printNode(NODE* me) { // ��� �μ�(������ �Լ�)
	while (me != NULL) {
		printf("%.2lf ", me->data);
		me = me->next;
	}
	printf("\n");
}

NODE* deleteNode(NODE* me, int index) { // ��� ����(������ �Լ�)
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
