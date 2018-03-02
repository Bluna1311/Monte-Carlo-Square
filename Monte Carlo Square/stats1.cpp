#include "stats.h"
#include <math.h> 
#include <cstdlib>
#include <ctime>
double pi = 3.1415926535897;
void stats1::Add(double x)
{
	++m_N;
	m_Sum += x;
	m_Sumsq += x*x;

	return;

}

double stats1::Mean()
{

	return  double(m_Sum) / double(m_N);



}

double stats1::StDev()
{
	return sqrt((m_Sumsq / m_N) - pow(m_Sum / m_N, 2));

}

stats1::stats1() {

	m_N = 0;
	m_Sum = 0;
	m_Sumsq = 0;
}


stats2::stats2() {

	m_N = 0;
	m_Sumxy = 0;
	
 
}


void stats2::Add(double x, double y)
{
	++m_N;
	X.Add(x);
	Y.Add(y);
	m_Sumxy += x * y;
	return;

}


double stats2::Cov()
{
	return ( double ((m_Sumxy / m_N) - (X.Mean() * Y.Mean())));
	
}


double stats2::Corr()
{

 	return double ( (Cov() / pow(pow((X.StDev()), 2)* pow((Y.StDev()), 2),0.5))) ;


}


double stats2::m_M() 

{
	return Cov() / pow(X.StDev(), 2);

}
double stats2::line()
{

	return  ((Y.Mean() - m_M() * X.Mean()));
	 
}

double NormalRandomGenerator::UniformRandom()
{
	return (double(rand() + 1) / double(RAND_MAX + 1));
	
}

double NormalRandomGenerator::NormalRandom()
{
	U1 = UniformRandom();
	U2 = UniformRandom();
	//double pi = 3.1415926535897;
	return cos(pi *U2)*sqrt(-2.*log(U1));

	
}

NormalRandomGenerator::NormalRandomGenerator()
{
	U1 = 0 ;
    U2 = 0 ;
	Z1 = 0 ;
	Z2 = 0 ;
	Counter = 0;

}

double NormalRandomGenerator::PT2NormalRandom()
{
	Counter = +1;
	if (Counter % 2 == 1)
	{
		U1 = UniformRandom();
		U2 = UniformRandom();
		//double pi = 3.1415926535897;
		Z1 = cos(pi *U2)*sqrt(-2.*log(U1));
		Z2 = sin(pi *U2)*sqrt(-2.*log(U1));
		return Z1;
	}
	if (Counter % 2 == 0)
		return Z2;
	
}