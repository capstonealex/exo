#include <array>

#define TRAJ_LENGTH 6

class Spline
{
	private:
		std::array<std::array<double, 5>, TRAJ_LENGTH-1> coefficients;
		std::array<std::array<double, 4>, TRAJ_LENGTH-1> deriv_coeffs;
	public:
		Spline();
		Spline(std::array<double, TRAJ_LENGTH> x, std::array<double, TRAJ_LENGTH> y);
		double getPoint(double xval);
		void derive();
		double getDerivative(double xval);
};
