# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Goal of the Project
The goal of the project is to implement PID (Proposonal Integral and Differential control)

First I tried to use only P-control and here is the result:

[![Implement P control](https://img.youtube.com/vi/U35FTojViHA/0.jpg)](https://www.youtube.com/watch?v=U35FTojViHA)

The result is as expected when using only P control. The car is oscillating along the road.

Then I tried to use PD control.

[![Implement P & D control](https://img.youtube.com/vi/QC30qc2cI2s/0.jpg)](https://www.youtube.com/watch?v=QC30qc2cI2s)

The car now drives much smoother on the road when adding D control in.

Finally, I tried PID control.

[![Implement P & D control](https://img.youtube.com/vi/q-MwZ0pT5RE/0.jpg)](https://www.youtube.com/watch?v=q-MwZ0pT5RE)

The car also drives as smooth as using only P & D controls. It is hard to tell the different. I can see the car turns smoother at wide turn than using P & D.

## How to choose PID gains
I chose PID gains manually using trial and error method. I started with the value from the Udacity class (Kp = 0.2, Ki = 0.004, Kd = 3.0) and I chose my final gain value as follow:

(Kp = 0.2, Ki = 0.0005, Kd = 3.5) 

## How to improve driving manuever
I chose to set throttle value according to the steering value.
If the sterring value is large, the throttle value is set to small. 

```
double max = fabs(steer_value);
if(max > 0.7){
    throttle = 0.0075;
}else if( max > 0.5){
    throttle = 0.05;
}else if( max > 0.2){
    throttle = 0.3;  
}else if( max > 0.1){
    throttle = 0.65;  
}else if( max > 0.01){
    throttle = 0.8;  
}
```

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

