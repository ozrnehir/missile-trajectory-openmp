

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>
#include <fstream>

// Missile state struct
struct Missile {
    double x, y;   // Position (meters)
    double vx, vy; // Velocity (m/s)
};

// Physics constants
const double G = 9.8;     // Gravity (m/s²)
const double DRAG = 0.001; // Drag coefficient
const double DT = 0.01;   // Time step (s)

/**
 * Simulates missile motion in parallel
 * @param missiles Vector of missile states
 * @param wind     Wind force (m/s²)
 */
void simulate(std::vector<Missile>& missiles, double wind) {
    #pragma omp parallel for
    for (size_t i = 0; i < missiles.size(); ++i) {
        double speed = std::hypot(missiles[i].vx, missiles[i].vy);
        double drag_force = DRAG * speed * speed;
        
        // Update velocity (parallelizable)
        missiles[i].vx -= (drag_force * missiles[i].vx / speed + wind) * DT;
        missiles[i].vy -= (drag_force * missiles[i].vy / speed + G) * DT;
        
        // Update position
        missiles[i].x += missiles[i].vx * DT;
        missiles[i].y += missiles[i].vy * DT;
    }
}

int main() {
    // Setup
    std::vector<Missile> missiles = {{0, 0, 50.0, 50.0}}; // Initial state
    std::ofstream data_file("trajectory.txt");
    
    // Serial simulation (baseline)
    auto start_serial = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < 1000 && missiles[0].y >= 0; ++t) {
        simulate(missiles, 0.0); // No wind
        data_file << missiles[0].x << " " << missiles[0].y << "\n";
    }
    auto end_serial = std::chrono::high_resolution_clock::now();
    
    // Parallel simulation (with wind)
    missiles = {{0, 0, 50.0, 50.0}}; // Reset
    auto start_parallel = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < 1000 && missiles[0].y >= 0; ++t) {
        simulate(missiles, 2.0); // Add wind
        data_file << missiles[0].x << " " << missiles[0].y << "\n";
    }
    auto end_parallel = std::chrono::high_resolution_clock::now();
    
    // Output results
    std::cout << "Serial time: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end_serial - start_serial).count() 
              << " μs\n";
    std::cout << "Parallel time: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end_parallel - start_parallel).count() 
              << " μs\n";
    
    data_file.close();

    return 0;
}
