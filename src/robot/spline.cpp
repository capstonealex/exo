#include "spline.h"
#include <array>
#include <cmath>

#define TRAJ_LENGTH 6

#define SPLINE_ORDER 3
#define A 0
#define B 1
#define C 2
#define D 3
#define X 4

Spline::Spline(std::array<double, TRAJ_LENGTH> x, std::array<double, TRAJ_LENGTH> y){
	
	const int n = x.size() - 1;
	int i;
	
	std::array<double, n+1> a;
	for (i=0; i<n+1 ; i++){
		a[i] = y[i];
	}
	
	std::array<double, n> b;
	std::array<double, n> d;
	std::array<double, n> h;
	for (i=0; i<n; i++){
		h[i] = x[i+1] - x[i];
	}

	std::array<double, n> alpha;
	for (i=1; i<n; i++){
		alpha[i] = (3/h[i])*(a[i+1]-a[i]) - (3/h[i-1])*(a[i]-a[i-1]);
	}

	std::array<double, n+1> c;
	std::array<double, n+1> l;
	std::array<double, n+1> u;
	std::array<double, n+1> z;
	l[0] = 1;
	u[0] = 0;
	z[0] = 0;
	for (i=1; i<n; i++){
		l[i] = 2*(x[i+1]-x[i-1]) - h[i-1]*u[i-1];
		u[i] = h[i]/l[i];
		z[i] = (alpha[i] - (h[i-1]*z[i-1]))/l[i];
	}
	
	l[n] = 1;
	z[n] = 0;
	c[n] = 0;
	
	for (i=n-1; i>=0; i--){
		c[i] = z[i] - u[i]*c[i+1];
		b[i] = ((a[i+1]-a[i])/h[i]) - ((h[i]*(c[i+1]+2*c[i]))/3);
		d[i] = (c[i+1]-c[i])/(3*h[i]);
	}
	
	for (i=0; i<n; i++){
		this->coefficients[i][A] = a[i];
		this->coefficients[i][B] = b[i];
		this->coefficients[i][C] = c[i];
		this->coefficients[i][D] = d[i];
		this->coefficients[i][X] = x[i];
	}
}

double Spline::getPoint(double xval){
	
	int length = this->coefficients.size()-1;
	int i=0;
	int section_found = 0;

	while (!section_found && i < length && xval >= this->coefficients[i][X]){
		if(xval < this->coefficients[i+1][X]){
			section_found = 1;
		}
		else{
			i++;
		}
	}

	double a = this->coefficients[i][A];
	double b = this->coefficients[i][B];
	double c = this->coefficients[i][C];
	double d = this->coefficients[i][D];
	double x = this->coefficients[i][X];
	
	
	double yval = a + b*(xval-x) + c*(xval-x)*(xval-x) + d*(xval-x)*(xval-x)*(xval-x);

	return yval;
}

void Spline::derive(){
	
	int i;
	for (i=0; i<deriv_coeffs.size(); i++){
		this->deriv_coeffs[i][A] = this->coefficients[i][B];
		this->deriv_coeffs[i][B] = this->coefficients[i][C] * 2;
		this->deriv_coeffs[i][C] = this->coefficients[i][D] * 3;
		this->deriv_coeffs[i][X-1] = this->coefficients[i][X];
	}
}

double Spline::getDerivative(double xval){
	
	int length = deriv_coeffs.size();
	
	int i;
	for (i=0; i<length-1; i++){
		if (this->deriv_coeffs[i][X-1] <= xval && xval < this->deriv_coeffs[i+1][X-1]){
			break;
		}
	}
	
	double a = this->deriv_coeffs[i][A];
	double b = this->deriv_coeffs[i][B];
	double c = this->deriv_coeffs[i][C];
	double x = this->deriv_coeffs[i][X-1];
	
	double dyval = a + b*(xval-x) + c*(xval-x)*(xval-x);
	return dyval;
}



















































