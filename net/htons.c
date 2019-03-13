#include <stdio.h>


void main()
{
	unsigned short port = 0x1234;
	unsigned char * c = (unsigned char*)&port;
	printf("%x.%x\n", c[0], c[1]);

	printf("htons(0x%x)=0x%x\n", port, htons(port));

	printf("ntohs(0x%x)=0x%x\n", port, ntohs(port));

	printf("port=%x\n", port);
}
