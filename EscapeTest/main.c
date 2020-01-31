#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h> // 시스템 헤더파일

/*
	메인 함수
*/
int main() {
	printf("%d\n", 100);
	printf("%lf\n", 3.141592);
	printf("%.1lf\n", 3.141592); // 소수점 첫번째자리까지만 출력
	printf("%.10lf\n", 3.141592);
	printf("%.1lf + %.1lf = %.1lf\n", 10.2, 3.4, 10.2 + 3.4);

	system("pause");
	return 0;
}