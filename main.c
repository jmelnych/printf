// #include "printflib.h"

// int main(void)
// {
// 	char *strlen;

// 	strlen = 0;
// 	int i;

// 	i = 0;
// 	setlocale(LC_ALL, "en_US.UTF-8");
// 	//printf("%d\n", L'ȱ');
// 	//printf("one === %-+11.5d two === %s\n", 529, "abc"); //+00529____
// 	//printf("ORIGIN: %09.8S\n", L"αȱ");
// 	//ft_printf("MY FNC: %09.8S\n", L"αȱ");
// 	//printf("ORIGIN: %.7C\n", L'α');
// 	// printf("ORIGIN: % 9s\n", "blabla");
// 	// ft_printf("MY FNC: % 9s\n", "blabla");
// 	// printf("ORIGIN: % 9c\n", 'a');
// 	// ft_printf("MY FNC: % 9c\n", 'a');
// 	// printf("ORIGIN: %05.3S\n", L"αȱ");
// 	// ft_printf("MY FNC: %05.3S\n", L"αȱ"); // +522
// 	// printf("ORIGIN: % +U\n", -222221111522);
// 	// ft_printf("MY FNC: % +U\n", -222221111522);
// 	//printf("ORIGIN: %0# 15.10X\n", -522);
// 	//ft_printf("MY FNC: %0 #15.10X\n", -522); // -522
// 	// printf("ORIGIN: %.3d\n", -2222211);
// 	// ft_printf("MY FNC: %.3d\n", -2222211);
// 	//ft_printf("MY FNC: %.*d\n", -2222211.5);
// 	//printf("coun or = %d\n", printf("ORIGIN: %.**d\n", 5, 8, -211));
// 	//printf("coun my = %d", ft_printf("MY FNC: %.**d\n", 5, 8, -211));
// 	//printf("coun or = %d\n", printf("ORIGIN: %.xd\n", -211));
// 	//printf("coun my = %d\n", ft_printf("MY FNC: %.xd\n", -211));
// 	//printf("coun or = %d\n", printf("ORIGIN: %s\n", "jfjsfsfjs"));
// 	//printf("coun my = %d\n", ft_printf("MY FNC: %s\n", "jfjsfsfjs"));
// 	// printf("coun or = %d\n", printf("ORIGIN: {%*d}", -5, 42));
// 	// printf("coun my = %d\n", ft_printf("MY FNC: {%*d}", -5, 42));
// 	printf("coun or = %d\n", printf("ORIGIN: %05.3S\n", 0)); 
// 	printf("coun my = %d\n", ft_printf("MY FNC: %05.3S\n", 0));
// 	// printf("\tcount org = %d\n",    printf("ORIGIN: %hhU", -2009499999)); 
// 	// printf("\tcount myf = %d\n", ft_printf("MY FNC: %hhU", -2009499999));
// 	//system(leaks: "ft_printf");
// 	// printf("ORIGIN: %05%\n");
// 	// ft_printf("MY FNC: %05%\n");
// 	return (0);
// }


// printf("coun or = %d\n", printf("ORIGIN: %05.3S\n", 0)); DOESNT WORK!
// 	printf("coun my = %d\n", ft_printf("MY FNC: %05.3S\n", 0));