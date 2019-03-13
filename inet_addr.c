#include <stdio.h>

void main()
{
	char * url = "16.10.8.7";
	unsigned int ip;
	
	int tmp;
	char *s = url;
	while(*s){
		ip <<= 8;
		sscanf(s, "%d", &tmp);
		while(*s){
			if(*s++ == '.'){
				break;
			}
		}
		ip |= tmp;
	}

	printf("ip=0x%x\n", ip);
}
