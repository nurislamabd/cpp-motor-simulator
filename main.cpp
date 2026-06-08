#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    cout << "Motor Simulator" << endl;
    
    // Initialize the simulation
    const double STEPS_PER_REV = 20000.0; // steps per revolution
    double currentAngle;
    cout << "Current position (steps): "; cin >> currentAngle;
    double targetAngle;
    cout << "Target position (steps): "; cin >> targetAngle;
    double maxRPM;
    cout << "Max RPM: ";
    cin >> maxRPM;
    double dt = 0.01;
    double time = 0.0;
    double velocity = 0;
    double acceleration;
    cout << "Acceleration (deg/sec^2): ";
    cin >> acceleration;
    if(acceleration <= 0)
    {
        cout << "Acceleration must be greater than 0." << endl;
        return 1;
    }
    double maxVelocity = maxRPM * STEPS_PER_REV / 60.0;
    bool overshoot = false;
    vector<double> positions;
    vector<double> times;
    vector<double> velocities;
    double direction;

    if(currentAngle == targetAngle)
    {
        cout << "Already at target angle." << endl;
        return 0;
    }

    if(targetAngle > currentAngle)
    {
        direction = 1.0;
    }
    else
    {
        direction = -1.0;
    }

    
    
    cout << "Acceleration: " << acceleration << " steps/sec^2" << endl;
    cout << "Max Velocity: " << maxVelocity << " steps/sec" << endl;
    cout << "Time Step: " << dt << " sec" << endl;
    cout << "" << endl;

    // Initial position and time
    positions.push_back(currentAngle);
    times.push_back(time);
    velocities.push_back(velocity);

    // Main simulation loop
    while(true)
    {
        double remaining = std::abs(targetAngle - currentAngle);
        double stoppingDistance = (velocity * velocity) / (2.0 * acceleration);

        if(remaining > stoppingDistance)
        {
            velocity += acceleration * dt;
        }
        else
        {
            velocity -= acceleration * dt;
        }

        if(velocity > maxVelocity)
        {
            velocity = maxVelocity;
        }

        if(velocity < 0)
        {
            velocity = 0;
        }

        currentAngle += direction * velocity * dt;
        time += dt;
        
        positions.push_back(currentAngle);
        times.push_back(time);
        velocities.push_back(velocity);

        cout << time
             << " sec : "
             << currentAngle
             << " steps"
             << " | velocity = "
             << velocity
             << " steps/s"
             << endl;

        bool reachedTarget =
            (direction > 0 && currentAngle >= targetAngle) ||
            (direction < 0 && currentAngle <= targetAngle);

        if(reachedTarget)
        {
            overshoot = (currentAngle != targetAngle);

            currentAngle = targetAngle;
            positions.back() = currentAngle;

            break;
        }
    }
    
    cout << "\nSimulation Complete\n";
    cout << "Total Time: " << time << " sec" << endl;
    cout << "Final Position: " << currentAngle << " steps" << endl;
    cout << "Overshoot: ";

    if (overshoot)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    // Save the simulation data to a file
    ofstream outputFile("motor_data.csv");

    if(!outputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }
    
    outputFile << "Time,Position_steps,Velocity_steps_per_sec\n";
    for(size_t i = 0; i < times.size(); i++)
    {
        outputFile << times[i]
            << ","
            << positions[i]
            << ","
            << velocities[i]
            << "\n";
    }
    outputFile.close();
    cout << "\nData saved to motor_data.csv" << endl;

    return 0;
}