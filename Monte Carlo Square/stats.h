#pragma once

class stats1
{

public:
	void Add(double x);
	double Mean();
	double StDev();
	stats1();

private:
	int m_N;
	double m_Sum;
	double m_Sumsq;
	
};

class stats2
{

public:
	void Add(double x, double y);
	double Cov();
	double Corr();
	stats2();
	double line();
	double m_M();
private:

	int m_N;
	stats1 X;
	stats1 Y;
	double m_Sumxy;
	

};

class NormalRandomGenerator
{
public:
	double PT2NormalRandom();
	NormalRandomGenerator();
	double UniformRandom();
	double NormalRandom();
private :
	double U1;
	double U2;
	double Z1;
	double Z2;
	int Counter;


};