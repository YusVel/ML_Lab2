#include <stdio.h>
#include <stdint.h>

//extern short calculate_s ();
extern short calculate_us ();
int32_t A = 0; //числитель
double B= 0; // знаминатель
double RESULT = 0 ;

int32_t a = 0;
int32_t b= 0;
int32_t c = 0;

int main()
{
	printf("Велиметов Юсуп Касумович\tПИБ 32 з\tLAB  2: Вариант 4\n");

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
	 
	printf("Результат вычисления на СИ: (55-%d+%d)/(-88/%d+1) = %d/%5.2lf = %5.2f\n" ,b,a,c,(55-b+a),((double)-88/c+1),(double)( (double)(55-b+a)/((double)-88/c+1))); 
	calculate_us ();
	printf("Результат вычисления на ASM: (55-%d+%d)/(-88/%d+1) = %d/%5.2lf = %5.2f\n" ,b,a,c,A,B,RESULT); 
	 
	
	return 0;
}