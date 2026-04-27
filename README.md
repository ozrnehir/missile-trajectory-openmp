# 🚀 Parallel Missile Trajectory Simulation using OpenMP

This project implements a **missile trajectory simulation** in C++ and analyzes the performance difference between **serial and parallel execution** using **OpenMP**.

The goal is to evaluate how multi-threading impacts computational performance, focusing on **execution time, speedup, and efficiency**.

---

## 🧠 Project Overview

The simulation models missile trajectory calculations and compares:

- 🧵 **Serial execution**
- ⚡ **Parallel execution (OpenMP)**

Different thread counts are tested to observe how performance scales and to identify limitations of parallelization.

---

## 🔧 Technologies Used

- 💻 C++
- ⚙️ OpenMP (Parallel Programming)
- 📊 Performance Analysis (Speedup & Efficiency)

---

## 📈 Performance Results

The simulation was executed with different thread counts:

| Threads | Serial Time (µs) | Parallel Time (µs) | Speedup | Efficiency (%) |
|--------|-----------------|-------------------|--------|----------------|
| 1      | 1007            | 942               | 1.06   | 106            |
| 2      | 1007            | 8417              | 0.12   | 6              |
| 4      | 18089           | 15661             | 1.15   | 28.75          |
| 8      | 32912           | 23748             | 1.38   | 17.25          |

📌 **Key Insight:**  
Speedup is **not linear**, and in some cases performance decreases due to:
- Thread management overhead
- Insufficient workload per thread

---

## 📊 Visual Results

### Execution Time Comparison
![Execution Graph](graph.png)

### Performance Comparison
![Performance Chart](results.png)

---

## ⚙️ How to Run

Make sure you have a C++ compiler with OpenMP support installed.

Compile:
```bash
g++ -fopenmp main.cpp -o simulation

Run:
./simulation

🧪 What This Project Demonstrates

* Understanding of parallel computing concepts
* Practical use of OpenMP
* Ability to perform performance analysis
* Awareness of real-world limitations of parallelization

📌 Conclusion

Although parallelization improves performance in some cases, results show that:

* More threads do not always mean better performance
* Proper workload distribution is critical

This highlights the importance of efficient parallel design, not just adding threads.

🚀 Future Improvements

* Dynamic workload distribution
* Larger dataset simulations
* GPU-based acceleration (CUDA/OpenCL)
* Real-time visualization

👩‍💻 Author
*Elif Nehir Özer
