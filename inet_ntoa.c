#include <stdio.h>

void main()
{
	char ip[16];


	
	unsigned char *s = ip;
	for(int i = 0; i < 4; i++){
		unsigned int tmp = (int)s[i];
		s = ssprintf(s, "%d", tmp);
	}

	*s = '\0';

	printf("ip=%s", ip);
}
