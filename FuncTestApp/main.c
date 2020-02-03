/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

void fruit(int count);

// 메인함수
int main(void) 
{
    fruit(1);

	system("pause");
	return EXIT_SUCCESS;
}

void fruit(int count) {
    printf("apple\n");
    if (count == 3) return;
    fruit(count + 1);
    printf("jam\n");
}