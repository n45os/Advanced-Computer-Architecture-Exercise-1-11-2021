# Exercise 1, Introduction to GEM5 | Computer Architecture
_Bountioukos-Spinaris Athanasios, Semester 7, 2021, AUTh_

## 1. Understanding "starter_se.py"
With a first look at the starter_se.py file, we can notice that this is the file that sets up the simulation parameters. We can set many parameters in the main function, with the most important being the following:

* CPU and Caches:
In this SE file, we have 3 choices for the CPU type. The _atomic_, the _minor_ and the _hpi_ type. Each of them have already set the caches as well. The default cpu type is atomic but we run it with the minor, so this is the one that will be described next. We cannot change the caches from the terminal window with a flag but we can make changes to the dictionary `cpu_types` in the file.

* CPU Frequency
The CPU frequency has been set by default to 1GHz and can be changed by adding the flag `--cpu-freq={frequency}GHz`. The simulation we ran was in 1GHz.

* CPU Cores
The default number of CPU cores is 1 and this can be changed by adding the flag `--num-cores={num_of_cores}`. We ran it with the default value.

* Memory
We can change the memory type, the number of memory channels, the number of memory ranks per channel, and specify the memory size.

##### If we run the simulation adding the flag `--cpu-freq=2GHz` we would change the system frequency to 2GHz.

## 2. "stats.txt" file
This file stores all the statistics of the simulation. The most important stats are the following:

* _sim_seconds_
This is the number of seconds simulated to run the script.

* _sim_insts_
The number of instructions simulated to run the script.

* _host_inst_rate_
The simulator instruction rate in instructions per second.

## 3. CPI Calculation
We can calculate the CPI using the given formula and using the following metrics:
- `system.cpu_cluster.cpus.dcache.overall_miss_rate::total     0.081944   # miss rate for overall accesses`
- `system.cpu_cluster.cpus.icache.overall_miss_rate::total     0.117078                       # miss rate for overall accesses`
- `system.cpu_cluster.l2.overall_miss_rate::total            1                       # miss rate for overall accesses`
- Also, the total instruction needed from "_sim_insts_" (5027)

**CPI = 1.0102 c/i**

## 4. Brief Explanation of Some In-order CPUs
### [SimpleCPU](https://www.gem5.org/documentation/general_docs/cpu_models/SimpleCPU)
This CPU model is used when we don't need a detailed model. This model is separated in 3 different submodels and they are the following:
- BaseSimpleCPU
This is the base for the rest of the SimpleCPU models and cannot run on its own. It is capable of the basic CPU functionalities and provides common stats among the models.
- AtomicSimpleCPU
Uses atomic memory access making it faster than the other CPU models. Gives information for every CPU circle and defines the port of the memory that was used.
- TimingSimpleCPU
Uses atomic memory access making it more detailed than the other CPU models. It defines the port that is used to hook up to memory, and connects the CPU to the cache. It also defines the necessary functions for handling the response from memory to the accesses sent out.

### [Minor CPU](https://www.gem5.org/documentation/general_docs/cpu_models/minor_cpu)
Its in-order execution is strict and allows the user to track the instruction in the pipeline. This model is not capable of multithreading. It implements a processor pipeline like the other CPU models. Provides different fetch states, uses branch prediction and has many memory alternative solutions.

### a.
In order to compare the different models, I created a simple NxN matrix multiplication script. It just creates a random NxN matrix and then squares it while printing each result. In the implementation N = 10.

The script was runned with MinorCPU and TimingSimpleCPU. Two parameters changed in the process: CPU clock and the cache model.
### b.
Looking at the numbers, we can see that TimingSimpleCPU is more clock sensitive than the MinorCPU. That's probably because MinorCPU has an idling (cycle skipping) mechanism in it's pipeline architecture. Only the fact that TimingSimpleCPU doesn't have a pipeline makes it linearly dependent on the change of the CPU clock.
![image 1](https://github.com/n45os/Advanced-Computer-Architecture-Exercise-1-11-2021/blob/main/GEM5_L1_L2.png)

When we use the L2 cache, we can see that there is not this much of a difference at the execution time. Although we can see that the MinorCPU is more sensitive to this change probably due to the fact that it uses a prediction mechanism. 
![image 2](https://github.com/n45os/Advanced-Computer-Architecture-Exercise-1-11-2021/blob/main/GEM5_cpu_times.png)
