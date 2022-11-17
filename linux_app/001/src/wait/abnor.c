/* 测试用例,用以验证wait异常情况 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char *p = "test of wait abnormally\n";

//    p[0] = 'h';
    int a = 5/0;

	return 56;
}
