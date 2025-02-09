#include <stdio.h>
#include <stdint.h>

//extern short calculate_s (short a, short b, short c);
extern short calculate_us (short a, short b, short c);

int main()
{
	printf("Велиметов Юсуп Касумович\tПИБ 32 з\tLAB  2: Вариант 4\n");
	int32_t a = 0;
	int32_t b= 0;
	int32_t c = 0;
	int err  = 0;
	while(err!=3)
	{
		printf("Для вычисления: (55-b+1*a)/(-88/c+1)\nВведите 16-битные (от 0 до 65536) a, b, c  через пробел: ");
		int err = scanf("%d%d%d", &a, &b, &c);
		if (c==0)
		{
				printf("****На ноль делить нельзя! ***\n"); 
				while((c=getchar())!='\n'&& c!=EOF){}
				continue;
		}
		if (a<0||b<0||c<0||a>65536||b>65536||c>65536)
		{
				printf("Вы ввели:  %d, %d, %d\n",a, b, c ); 
				printf("****Вводивые переменные вышли за пределы допустимых значений!***\n"); 
				while((c=getchar())!='\n'&& c!=EOF){}
				continue;
		}
		if(err==3)
		{
			break;
		}
		printf("ERROR! \n");
		while((c=getchar())!='\n'&& c!=EOF){}
	}
	printf("Вы ввели:  %d, %d, %d\n",a, b, c ); 
	 
	printf("Результат вычисления на СИ: %f\n" ,(double)( (double)(55-b+a)/((double)-88/c+1))); 
	printf("Результат вычисления на ASM: %d\n" ,calculate_us(a,b,c)); 
	 
	
	return 0;
}