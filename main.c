#define _CRT_SECURE_NO_WARNINGS

//constans
#define INPUT_NUM_MIN 1
#define INPUT_NUM_MAX 26 

//Print maggages
#define PAUSE_M {printf("Please press <enter> to continue..."); rewind(stdin); getchar();}
#define EXIT_M {printf("Bye Bye , Please hit <enter> to EXIT\n"); rewind(stdin); getchar();}


//Errors
#define ILLIGAL_OPTIONS 10
#define EXIT_POGRAM 11
#define GET_ERROR 12
#define DATA_ERROR 13

//includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void Trig(unsigned a, unsigned b);
void Mult_Table(unsigned a, unsigned b);
void Fibo(unsigned a, unsigned b);
unsigned long long int Rally(int num);
void Order(unsigned a, unsigned b);
void Disp(unsigned a, unsigned b);
unsigned Get(unsigned *ptr_a, unsigned *ptr_b);
char Help();
void Error_Msg(unsigned);
double Expo(unsigned a, unsigned b);
double Sino(double x, unsigned n);
void Expo_Table(unsigned a, unsigned b);


void main()
{
	unsigned check = 0;
	unsigned a, b;
	char choose;
	do
	{
		choose = Help();
		switch (choose)
		{
		case ('d'):
		case ('D'):
		{
			if (check == 1)
			{
				Disp(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case('h'):
		case('H'):
		{
			printf("Please press <enter> to print the Menu again...");
			rewind(stdin);
			getchar();
			break;
		}

		case('p'):
		case('P'):
		{
			if (check == 1)
			{
				Expo_Table(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('f'):
		case ('F'):
		{
			if (check == 1)
			{
				Fibo(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case('s'):
		case('S'):
		{
			if (check == 1)
			{
				printf("Sin of %.4f using %d items is: %.8lf\n", ((double)a) / 10, b, Sino(a, b));
				PAUSE_M
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('t'):
		case ('T'):
		{
			if (check == 1)
			{
				Trig(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('m'):
		case ('M'):
		{
			if (check == 1)
			{
				Mult_Table(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('g'):
		case ('G'):
		{
			check = Get(&a, &b);
			break;
		}
		case ('e'):
		case('E'):
		{
			if (check == 1)
			{
				printf("e^%d using %d items is %.4lf\n", a, b, Expo(a, b));
				PAUSE_M
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('o'):
		case ('O'):
		{
			if (check == 1)
			{
				Order(a, b);
			}
			else
			{
				Error_Msg(DATA_ERROR);
			}
			break;
		}
		case ('x'):
		case ('X'):
		{
			Error_Msg(EXIT_POGRAM);
			break;
		}
		default:
		{
			Error_Msg(ILLIGAL_OPTIONS);
			break;
		}
		}
	} while (choose != 'x' && choose != 'X');
}


/*****************************************************************************
function name: Rally   --------- check this function
input: unsigned num - from
algorithm: The func shows the values of a and b.
operate code : none.
operate  condition: by pressing on 'd'/'D' .
*****************************************************************************/

unsigned long long int Rally(int num)
{
	unsigned long long int sul = 1;
	while (num > 0)
	{
		sul *= num;
		num--;
	}
	return sul;
}

double Expo(unsigned a, unsigned b)
{
	double solution = 1 + a;
	if (b == 1)
		return 1;
	for (int i = 3; i <= b; i++)
	{
		solution = solution + (pow(a, i - 1) / Rally(i - 1));
	}
	return solution;
}

/*****************************************************************************
function name: Sino
input: unsigned a , b - from main .
algorithm: The func is calculating the value of sinos with the  value of a by Accuracy of b times oif derivative .
operate code : none.
operate  condition: by pressing on 's'/'S' .
*****************************************************************************/

double Sino(double x, unsigned n)
{
	x = x / 10;
	double solution = x;
	int sign = -1;
	for (int i = 2; i <= n; i++)
	{
		solution = solution + sign * (pow(x, (2 * (i - 1) + 1)) / Rally(2 * (i - 1) + 1));
		sign = -1 * sign;
	}
	return solution;
}

/*****************************************************************************
function name: Trig
input: unsigned a , b - from main .
algorithm: The func shows a triangular with the height of a. the b parameter States the letter it will show.
operate code : none.
operate  condition: by pressing on 't'/'T' .
*****************************************************************************/

void Trig(unsigned a, unsigned b)
{
	printf("\n");
	if (a > 1)
	{
		for (int space = 0; space < a - 1; space++)   // first raw
		{
			printf(" ");
		}
		printf("%c\n", b + 64);

		for (int raw = 2; raw < a; raw++)
		{
			for (int space = 0; space < a - raw; space++)  //space befor
			{
				printf(" ");
			}
			printf("%c", b + 64);

			for (int space = 0; space < 2 * raw - 3; space++)     //space between   2*raw-3 (series function)
			{
				printf(" ");
			}

			printf("%c", b + 64);
			printf("\n");
		}
		for (int space = 0; space < (2 * a - 1); space++)  //triangle base    2*a - 1 (size of base)
		{
			printf("%c", b + 64);
		}
		printf("\n");
	}
	else
	{
		printf("%c\n", b + 64);
	}
	PAUSE_M
}

/*****************************************************************************
function name: Mult_Table
input: unsigned a , b - from main .
algorithm: The func shows the Multiplication table of a*b
operate code : none.
operate  condition: by pressing on 'm'/'M' .
*****************************************************************************/

void Mult_Table(unsigned a, unsigned b)
{
	int j, i;
	for (i = 1; i < a + 1; i++)
	{
		for (j = 1; j < b + 1; j++)
		{
			printf("%5d", i*j);
		}
		printf("\n");
	}
	PAUSE_M
}

/*****************************************************************************
function name: Fibo
input: unsigned a , b - from main .
algorithm: The func shows the value of a , a+1 , a+2 ... b organs of fibonacci series
operate code : none.
operate  condition: by pressing on 'f'/'F' .
*****************************************************************************/


void Fibo(unsigned a, unsigned b)
{
	unsigned index = 0;
	unsigned x = 0;
	unsigned y = 1;
	if (a == index)
		printf("%d\n", x);
	index++;
	if (a == index)
		printf("%d\n", y);
	index++;

	while (index <= b)
	{
		if (index % 2 == 0)
		{
			x = x + y;
			if (index >= a)
				printf("The fibonacci %d item is: %8d\n", index, x);
		}
		else
		{
			y = x + y;
			if (index >= a)
				printf("The fibonacci %d item is: %8d\n", index, y);
		}
		index++;
	}
	PAUSE_M
}



/*****************************************************************************
function name: Order
input: unsigned a , b - from main .
algorithm: The func printing the a and b parameters and all the numbers between them.
operate code : none.
operate  condition: by pressing on 'o'/'O' .
*****************************************************************************/


void Order(unsigned a, unsigned b)
{
	int i;
	for (i = a; i < b + 1; i++)
	{
		printf("%d ,", i);
	}
	printf("\n");
	PAUSE_M
}

/*****************************************************************************
function name: Disp
input: unsigned a , b - from main .
algorithm: The func shows the values of a and b.
operate code : none.
operate  condition: by pressing on 'd'/'D' .
*****************************************************************************/

void Disp(unsigned a, unsigned b)
{
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	PAUSE_M
}

/*****************************************************************************
function name: Expo_Table
input: unsigned a , b - from main .
algorithm: The func is calculating the value of e with the  power of a by Accuracy of b times oif derivative .
operate code : none.
operate  condition: by pressing on 'e'/'E' .
*****************************************************************************/

void Expo_Table(unsigned a, unsigned b)
{
	int j, i;
	for (i = 1; i < a + 1; i++)
	{
		for (j = 1; j < b + 1; j++)
		{
			printf("%10.4lf", Expo(i, j));
		}
		printf("\n");
	}
	PAUSE_M
}


/*****************************************************************************
function name: Get
input: unsigned a , b - from main . (pointers).
algorithm: The func is checking if the input is correct.
operate code : none.
operate  condition: with every new input.
*****************************************************************************/

unsigned Get(unsigned *ptr_a, unsigned *ptr_b)
{
	int a, b;
	printf("Please Enter two numbers , a , b Between %d to %d. (a<b):\n", INPUT_NUM_MIN, INPUT_NUM_MAX);
	printf("Enter a: ");
	if (scanf("%d", &a))
		printf("Enter b: ");
	scanf("%d", &b);
	if ((a >= b) || (a<INPUT_NUM_MIN) || (a>INPUT_NUM_MAX - 1) || (b>INPUT_NUM_MAX) || (b<INPUT_NUM_MIN + 1))
	{
		Error_Msg(GET_ERROR);
		return 0;
	}
	*ptr_a = a;
	*ptr_b = b;
	PAUSE_M
	return 1;
}




/*****************************************************************************
function name: Error_Msg
input: unsigned - asking from the user
algorithm: The func shows the user if there's problem with input
operate code : when input is incorrect - with Function Get.
operate  condition: when input is incorrect .
*****************************************************************************/
void Error_Msg(unsigned  error_code)
{
	switch (error_code)
	{
	case ILLIGAL_OPTIONS:
		printf("Error!! You have chosen an illigal options\n");
		PAUSE_M
		break;
	case EXIT_POGRAM:
		EXIT_M
		break;
	case GET_ERROR:
		printf("Error!! You have not inserted two diffrent numbers, a<b , within [%d,%d]\n", INPUT_NUM_MIN, INPUT_NUM_MAX);
		PAUSE_M
		break;
	case DATA_ERROR:
		printf("Error!! No Legal data in the system. Choose the ['G'|'g'] option\n");
		PAUSE_M
		break;
	default:    //bonus question number 2- run from the dibbager and replace error code
		printf("Internal Error. CALL 911\n");
		PAUSE_M
			break;
	}
}

/*****************************************************************************
function name: Help
input: char x - asking from the user
algorithm: The func clear the screen, print the menue & get a  char from the user
operate code : None - every cycle.
operate  condition: none
*****************************************************************************/
char Help() {
	char x;
	system("cls");
	printf("Welcome to the 1st-menue-program.\nChoose one of the following options:\n");
	printf("[D|d] - Display a and b;\n");
	printf("[E|e] - Calculate e^a by a sum of b series numbers;\n");
	printf("[F|f] - Calculate the a to b fionacci numbers;\n");
	printf("[G|g] - Get two diffrent values within [%u, %u]; a<b; \n", INPUT_NUM_MIN, INPUT_NUM_MAX);
	printf("[H|h] - Print this Menue;\n");
	printf("[M|m] - Calculate multiplication table from 1X1 till aXb;\n");
	printf("[O|o] - Display a, a+1, a+2..., b;\n");
	printf("[P|p] - Calculate e^x table;\n");
	printf("[S|s] - Calculate sin(a/10) by sum of b series numbers;\n");
	printf("[T|t] - Print an isosceles triangle;\n");
	printf("[X|x] - Exit from the program;\n");
	rewind(stdin);     /*clear the input buffer*/
	x = getchar();
	return x; /*returning the char that was chosen in the menue */
}
