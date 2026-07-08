# ⚙️ QuantumSync — Scheduler & IPC Projects

A collection of Operating Systems and System Programming projects implemented in C, covering CPU scheduling algorithms and classic Inter-Process Communication (IPC) problems.

Built for academic practice, GATE CS IT 2027 preparation, and portfolio demonstration.

---

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Tech Stack](#tech-stack)
- [Scheduler Simulator](#scheduler-simulator)
- [IPC Projects](#ipc-projects)
- [Build Instructions](#build-instructions)
- [Sample Output](#sample-output)
- [Roadmap](#roadmap)
- [License](#license)

---

## Overview

**QuantumSync** is organized into two major areas:

| Module | Description |
|---|---|
| **Scheduler Simulator** | Classic CPU scheduling algorithms — preemptive and non-preemptive |
| **IPC Projects** | Inter-process communication using shared memory, semaphores, and pthreads |

The name reflects the two core themes of the repository: **Quantum** — the time-quantum concept central to preemptive CPU scheduling (Round Robin, Priority Scheduling), and **Sync** — the synchronization primitives (semaphores, shared memory, pthreads) used throughout the IPC suite.

---

## Project Structure

```
QuantumSync/
│
├── scheduler/                # CPU Scheduling Simulator
│   ├── scheduler.c
│   ├── fcfs.c
│   ├── sjf.c
│   ├── priority.c
│   ├── round_robin.c
│   ├── utils.c
│   ├── utils.h
│   └── Makefile
│
├── ipc_projects/              # IPC Suite
│   ├── shared_memory_chat.c
│   ├── producer_consumer.c
│   ├── shm_semaphore_combo.c
│   ├── dining_philosophers.c
│   └── Makefile
│
└── README.md                  # Documentation
```

---

## Tech Stack

- **Language:** C
- **Compiler:** GCC
- **Libraries:**
  - `pthread` — POSIX threads for concurrency
  - `semaphore.h` — Semaphores for synchronization
  - `sys/ipc.h`, `sys/shm.h` — Shared memory IPC
- **Build System:** GNU Make
- **Platform:** Linux (tested on Ubuntu/Debian)

---

## Scheduler Simulator

Implements and compares the following CPU scheduling algorithms:

- **FCFS** — First Come First Serve
- **SJF** — Shortest Job First (non-preemptive)
- **Priority Scheduling** — Preemptive, priority-based
- **Round Robin** — Preemptive, time-quantum based

Each algorithm outputs a table of waiting times, turnaround times, and their averages, so results can be compared side by side.

### Example Run

```
Enter number of processes: 3

Arrival & Burst for P1: 0 5
Priority for P1: 2

Arrival & Burst for P2: 1 3
Priority for P2: 4

Arrival & Burst for P3: 2 2
Priority for P3: 3

Choose Algorithm:
1. FCFS
2. SJF
3. Priority (Preemptive)
4. Round Robin
```

**Output:** Table of waiting times, turnaround times, and averages for the selected algorithm.

---

## IPC Projects

Classic concurrency and synchronization problems, each demonstrating a different IPC mechanism:

| Project | Description |
|---|---|
| **Shared Memory Chat** | Two processes exchange text via a shared memory segment |
| **Producer-Consumer** | Bounded-buffer synchronization using semaphores |
| **Semaphore + Shared Memory Combo** | Combined use of semaphores and shared memory for coordinated access |
| **Dining Philosophers** | Models concurrency and deadlock prevention using semaphores |

---

## Build Instructions

Clone the repository:

```bash
git clone https://github.com/Jitin2102/QuantumSync.git
cd QuantumSync
```

### Build & Run the Scheduler

```bash
cd scheduler
make
./scheduler
```

### Build & Run IPC Projects

```bash
cd ipc_projects
make
./shared_memory_chat
./producer_consumer
./shm_semaphore_combo
./dining_philosophers
```

> **Note:** Programs using `pthread` require linking with `-lpthread`, and programs using POSIX semaphores may require `-lrt` on some systems. The provided Makefiles already handle this — if you compile manually, remember to add these flags.

---

## Sample Output

```
Process   Arrival   Burst   Waiting   Turnaround
P1        0         5       0         5
P2        1         3       4         7
P3        2         2       6         8

Average Waiting Time    : 3.33
Average Turnaround Time : 6.67
```

---

## Roadmap

- [ ] Add Multilevel Queue Scheduling
- [ ] Add Gantt chart visualization (ASCII or graphical)
- [ ] Add message queue and pipe-based IPC examples
- [ ] Add unit tests for scheduling algorithms
- [ ] Dockerize the build environment for cross-platform testing

---

## License

This project is open for educational and personal portfolio use. Add a `LICENSE` file (e.g., MIT) if you intend to make it public and reusable by others.

---

### 🙌 Contributing

This is primarily a personal learning/portfolio repository, but suggestions and pull requests are welcome if you spot bugs or improvements in the algorithms.
