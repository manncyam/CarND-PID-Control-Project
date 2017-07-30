#include "PID.h"
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  //initialize error values to 0
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  //calculate the different value of cte between time t and t-1
  d_error = cte - p_error;
  //accumulate cte value
  i_error += cte; 
  //set the p_error to cte for calculating d_error at time t + 1
  p_error = cte;
}

double PID::TotalError() {
	// PID formula
	double steer = -Kp  * p_error - Kd*d_error - Ki*i_error;
	int max_steering_value = 1;
	if(steer < -max_steering_value)
		steer = -max_steering_value;
	if(steer > max_steering_value)
		steer = max_steering_value;
	return steer;
}

