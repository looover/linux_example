#include <stdio.h>  
#include <setjmp.h>  

jmp_buf buf;

void test()
{
	printf("%s:enter\n", __func__);

	longjmp(buf, 1);

	printf("%s:exit\n", __func__);
}

int main(int argc, char** argv)
{
	if(setjmp(buf)){
		printf("%s:longjump buf return\n", __func__);
	}
	else
	{
		printf("%s: setjump okay\n", __func__);
		test();
	}
}
