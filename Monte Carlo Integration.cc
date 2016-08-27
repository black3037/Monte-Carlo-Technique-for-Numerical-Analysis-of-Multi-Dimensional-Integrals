#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <random>
using namespace std;


int main(int argc, char *argv[])
{
	int n;
	int m;
	n = atol(argv[1]);
	m = atol(argv[2]);
	double size;
	double I;
	double I_mc;
	double I_mp = 0.0;
	double relative;
	double absolute;
	double rejected;
	double bin = 0;
	double underroot = 1.0;
	fstream file;
	file.open("output.txt",std::ios::out);
	size = pow(m,n);


// Monte Carlo

	vector<double> a(size);
	for (int i = 0; i<size; ++i)
	{
		a[i] = (double)rand()/(double)RAND_MAX;
	}


	for (int i = 0; i<size; ++i)
	{
		underroot = 1.0;
		for (int j=0; j<n; ++j)
		{
			double x = (double)rand()/(double)RAND_MAX;
			underroot = underroot*x;
		}
		if (a[i]<sqrt(underroot))
		{
			bin = bin + 1;

		}
	}

// Mid-Point
	double delta = 1.0/m;
	double y = delta/2.0;
	for (int i = 0; i<m; ++i)
	{
		I_mp = I_mp + sqrt(y);
		y = y + delta;
	}
	I_mp = I_mp * delta;
	I_mp = pow(I_mp,n);


// Calculations
	I = pow(2.0/3.0,n);
	rejected = size - bin;
	I_mc = bin/(bin+rejected);
	absolute = abs(I-I_mc);
	relative = abs(absolute/I);
	cout << "Relative Error = " <<" " <<  relative << endl;
	file << I << " " << I_mp << " " << I_mc;
	file.close();

return 0;
}



