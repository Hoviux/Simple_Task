#include "stdio.h"
#include "math.h"

void difference_method_1(double x, double dx, double dlast);
void difference_method_2(double x, double dx, double dlast);
//void difference_method_3(double x, double dx, double dlast);
void show_result_func(double x, double step_result);

void difference_method_1(double x, double dx, double dlast){
	//From lefy to right
	//Just a function (y = x^2 * exp(x))
	while (x <= dlast){
		double step_result = ((pow(x + dx,2)) * exp((x+dx)/2) - (pow(x,2))*exp(x/2))/dx;
		show_result_func(x, step_result);
		x = x + dx;
	}
}

void difference_method_2(double x, double dx, double dlast){
	// From right to left
	//Just a function (y = x^2 * exp(x))
	while (x >= dlast){
		double step_result = ((pow(x,2))*exp(x/2) - (pow(x - dx,2)) * exp((x-dx)/2))/dx;
		show_result_func(x, step_result);
		x = x - dx;
	}
}

void show_result_func(double x, double step_result){
	printf ("%4.5f" , x);
	printf("  ");
	printf("%10.5f\n", step_result); 
}

int main(){
	double x = -10;				//Start point
	double dx = 0.00005;		//Step
	double dlast = 10;			//End point

	if (x < dlast)
	{
		// From left to right
		difference_method_1(x, dx, dlast);
	}
	if (x > dlast)
	{
		// From right to left
		difference_method_2(x, dx, dlast);
	}


	return 0;
}