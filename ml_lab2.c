#include <stdio.h>
#include <stdint.h>

extern short calculate_s ();
extern short calculate_us ();
int32_t A = 0; //числитель
double B = 0; // знаминатель
int16_t _B = 0; 
int16_t _RESULT = 0; 
int16_t ostatok_ot_RESULT = 0;
double RESULT = 0 ;

int32_t a = 0;
int32_t b= 0;
int32_t c = 0;

int8_t a1 = 0;
int8_t b1 = 0;
int8_t c1 = 0;

int main()
{
	int err  = 0;
	error:
	printf("Провести расчет для беззнакового int16_t(0) или для знакового int8_t(1)? ");
	char ch = 0;
	scanf("%c",&ch);
	switch(ch)
	{

		case '0': //Беззнаковый 2 байта
		printf("Велиметов Юсуп Касумович\tПИБ 32 з\tLAB  2: Вариант 4\n");
		
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
		calculate_us ();

		printf("Вы ввели:  %d, %d, %d\n",a, b, c ); 
	 
		printf("Результат вычисления на СИ: (55-%d+%d)/(-88/%d+1) = %d/%5.2lf = %5.2f\n" ,b,a,c,(55-b+a),((double)-88/c+1),(double)( (double)(55-b+a)/((double)-88/c+1))); 
	
		printf("Результат вычисления на ASM: (55-%d+%d)/(-88/%d+1) = %d/%5.2lf = %5.2f\n" ,b,a,c,A,B,RESULT); 

		break;



		case '1': //знаковый 1 байт
		printf("Велиметов Юсуп Касумович\tПИБ 32 з\tLAB  2: Вариант 4\n");
		
		while(err!=3)
		{
			printf("Для вычисления: (55-b+1*a)/(-88/c+1)\nВведите 8-битные (от -128 до 127) a, b, c  через пробел: ");
			int err = scanf("%d%d%d", &a, &b, &c);
			if (c==0)
			{
					printf("****На ноль делить нельзя! ***\n"); 
					while((c=getchar())!='\n'&& c!=EOF){}
					continue;
			}
			if (a<-128||b<-128||c<-128||a>127||b>127||c>127)
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
		a1=(int8_t)(a);
		b1=(int8_t)(b);
		c1=(int8_t)(c);
		calculate_s ();

		printf("Вы ввели:  %d, %d, %d\n",a, b, c ); 
	 
		printf("Результат вычисления на СИ: (55-%d+%d)/(-88/%d+1) = %d/%5.2lf = %5.2f\n" ,b,a,c,(55-b+a),((double)-88/c+1),(double)( (double)(55-b+a)/((double)-88/c+1))); 
	
		printf("Результат вычисления на ASM(без сопроцессора): (55-%d+%d)/(-88/%d+1) = %d/%hd = %hd+%hd/%hd\n" ,b,a,c,A,_B,_RESULT, ostatok_ot_RESULT,_B); 
		break;

		default: while((ch=getchar())!='\n'&& c!=EOF){} 
		goto error;
	}
	 
	
	return 0;
}