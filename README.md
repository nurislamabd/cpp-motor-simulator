# C++ Motor Angle Simulator

A C++ simulation of a robotic motor joint moving from a current angle to a target angle using acceleration-limited motion control. The simulator models velocity constraints, acceleration and deceleration behavior, bidirectional movement, overshoot detection, and trajectory logging. Results are exported to a CSV file for analysis and visualization.

---

## Overview

Robotic joints cannot instantly move from one position to another. Real motors must accelerate, obey speed limits, and decelerate before reaching their target position. This project simulates that behavior using a simplified motion-planning approach commonly found in robotic systems.

The simulator computes the motor's position and velocity at discrete time intervals and generates a complete trajectory from the starting angle to the target angle.

---

## Features

* User-defined current angle, target angle, maximum RPM, and acceleration
* Bidirectional motion (positive and negative rotation)
* Acceleration-limited motion profile
* Velocity limiting based on motor RPM
* Automatic deceleration using stopping distance calculations
* Overshoot detection
* Time-stepped simulation
* Position, velocity, and time logging
* CSV export for plotting and analysis

---

## Motion Model

The simulator performs the following steps during each simulation update:

1. Calculate the remaining distance to the target.
2. Calculate the stopping distance based on the current velocity.
3. Accelerate if sufficient distance remains.
4. Decelerate when approaching the target.
5. Update velocity and position.
6. Store simulation data for export.

Stopping distance is computed using:

d = v² / (2a)

where:

* d = stopping distance
* v = current velocity
* a = acceleration

This allows the motor to begin slowing down before reaching the target position.

---

## Example

### Input

```text
Current angle: 0
Target angle: 90
Max RPM: 30
Acceleration (deg/sec^2): 100
```

### Console Output

```text
0.01 sec : 0.01 deg | velocity = 1 deg/s
0.02 sec : 0.03 deg | velocity = 2 deg/s
0.03 sec : 0.06 deg | velocity = 3 deg/s
...
```

### Final Summary

```text
Simulation Complete

Total Time: 2.34 sec
Final Angle: 90 deg
Overshoot: No
```

---

## CSV Output

Simulation data is exported to:

```text
motor_data.csv
```

The file contains:

```csv
Time,Angle,Velocity
0,0,0
0.01,0.01,1
0.02,0.03,2
...
```

This data can be imported into:

* Microsoft Excel
* MATLAB
* Python (Pandas/Matplotlib)
* GNUPlot
* Google Sheets

for visualization and analysis.

---

## Building and Running

### Compile

```bash
g++ main.cpp -o simulator
```

### Run

```bash
./simulator
```

On Windows:

```bash
simulator.exe
```

---

## Technologies Used

* C++
* Standard Template Library (STL)

  * vector
  * fstream
* Numerical simulation
* Motion planning concepts
* CSV data logging

---

## Applications

This project demonstrates concepts used in:

* Robotics
* Motion control systems
* Industrial automation
* CNC machines
* Robotic arm trajectory planning
* Embedded motor control software

---

## Future Improvements

Potential extensions include:

* Multi-joint robotic arm simulation
* Trapezoidal and S-curve motion profiles
* Real-time graphical visualization
* Multiple motor coordination
* PID position control
* GUI-based interface
* 3D robotic arm kinematics integration

---

## Author

Developed as a robotics and software engineering project to explore motion simulation, trajectory generation, and motor control concepts using C++.
