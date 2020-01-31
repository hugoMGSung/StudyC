#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char grade;
	char name[20];

	printf("학점을 입력하세요 : ");
	scanf("%c", &grade);
	printf("이름을 입력하세요 : ");
	scanf("%s", &name);

	printf("%s 의 학점 : %c\n", name, grade);

	system("pause");
	return 0;
}