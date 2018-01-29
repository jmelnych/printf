#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	chan (char ***s)
{
	*s = (char **)malloc(sizeof(char*)* 4);
	*s[0] = strdup("hello");
	s[0][1] = strdup("world");
	s[0][2] = strdup("its me");
	s[0][3] = 0;
}

int main()
{
	char **s;
	s = (char **)malloc(sizeof(char *) * 3);
	s[0] = (char *)malloc(4);
	s[1] = (char *)malloc(5);
	s[2] = 0;
	s[0] = "123";
	s[1] = "abcd";
	chan(&s);
	while (*s)
		printf("%s\n", *s++);
}

// 1 == hello, 2 = world, 
// //--//  3 = its me;