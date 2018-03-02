#include "stats.h"
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

int main() 
{
	srand(time(NULL));
	stats1 S;
	int R = 4; // sketch the circle and r=4 is polar form of shape with domain D
	int Square_side = 2*R; // for my sake . so i remember what im doing
	int N_loops=0;
	for (int i = 0; i <= 1000; i++)
	{
		N_loops++;
		double Random_PointX = double(rand() / double(RAND_MAX)*8) - 4;
		double Random_PointY = double(rand()  / double(RAND_MAX)*8) - 4;;
		
		double X_P = Random_PointX;
		double Y_P = Random_PointY;

		double Temp_R = sqrt(pow(X_P, 2) + pow(Y_P, 2));
		double Theta = atan(Y_P/X_P);
		double Boundry_R = 3 - cos(8*Theta);
		if (Temp_R < Boundry_R)
		{
			S.Add(1);
		}
		else
		{
			S.Add(0);
		}
	}
	cout << S.Mean()*64 << endl;
	cout << 64*(S.StDev() * (1 / sqrt(N_loops - 1))) << endl;
	

	// PART C
	stats1 M;
	cout << "to what accuracy would you like ?" << endl;
	double accuracy;
	cin >> accuracy;
    long double New_steps = N_loops * pow((1 / accuracy), 2);
	int M_loops = 0;
	for (int i = 0; i <= New_steps; i++)
	{
		M_loops++;
		double Random_PointX = double(rand() / double(RAND_MAX) * 8) - 4;
		double Random_PointY = double(rand() / double(RAND_MAX) * 8) - 4;;

		double X_P = Random_PointX;
		double Y_P = Random_PointY;

		double Temp_R = sqrt(pow(X_P, 2) + pow(Y_P, 2));
		double Theta = atan(Y_P / X_P);
		double Boundry_R = 3 - cos(8 * Theta);
		if (Temp_R < Boundry_R)
		{
			M.Add(1);
		}
		else
		{
			M.Add(0);
		}
	}

	cout << New_steps << endl;
	cout << 64 * M.StDev() *(1 / sqrt(M_loops - 1));


	system("pause");
	return 0;



}