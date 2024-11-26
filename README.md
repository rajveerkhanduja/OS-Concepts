# OS Concepts
---

## 1. First-Come, First-Served (FCFS) Scheduling
FCFS is the simplest CPU scheduling algorithm where the process that arrives first is executed first.

### Key Concepts:
- **Non-preemptive**: Once a process starts execution, it cannot be stopped until completion.
- **Jobs** are executed in the order of their arrival in the ready queue.

### Characteristics:
- **Turnaround Time**: Time taken from the arrival of a process to its completion.
- **Waiting Time**: Time a process spends waiting in the ready queue.

---

## 2. Shortest Job First (SJF) Scheduling
SJF selects the process with the smallest execution time for scheduling.

### Key Concepts:
- **Preemptive** (Shortest Remaining Time First) or **Non-preemptive**.
- The priority is based on the length of the CPU burst.

### Characteristics:
- Reduces average waiting time compared to FCFS.
- Requires knowledge of the CPU burst time in advance, which is often estimated.

---

## 3. Round Robin (RR) Scheduling
Round Robin is a **preemptive** scheduling algorithm that assigns a fixed time quantum to each process in the ready queue.

### Key Concepts:
- Processes are scheduled in a cyclic order.
- Each process gets a maximum of one time quantum in each cycle.

### Characteristics:
- **Time Quantum**: Determines the time slice for each process.
- Processes are preempted and moved to the back of the queue if not completed within their time slice.

---

## 4. Producer-Consumer Problem
The **Producer-Consumer Problem** is a classic synchronization problem where two processes (producer and consumer) share a fixed-size buffer.

### Problem Statement:
- The **Producer** generates data and adds it to a shared buffer.
- The **Consumer** removes data from the buffer.
- The buffer has limited capacity, and synchronization is required to avoid:
  - **Buffer overflow**: Producer adds data when the buffer is full.
  - **Buffer underflow**: Consumer tries to remove data when the buffer is empty.

### Key Concepts:
- **Shared Resources**: A common buffer is shared between producers and consumers.
- **Synchronization**: Achieved using semaphores, mutex locks, or condition variables.
  - Two semaphores are commonly used:
    - **Full**: Tracks the number of full slots.
    - **Empty**: Tracks the number of empty slots.

### Solution with Semaphores:
- **Producer**:
  1. Wait for an empty slot.
  2. Add data to the buffer.
  3. Signal the buffer is full.
- **Consumer**:
  1. Wait for a full slot.
  2. Remove data from the buffer.
  3. Signal the buffer is empty.

---

## 5. Least Recently Used (LRU) Page Replacement Algorithm
The **LRU Page Replacement Algorithm** is used in operating systems to manage memory. When a page fault occurs, it replaces the page that has not been used for the longest time.

### Key Concepts:
- **Page Fault**: Occurs when the requested page is not in memory.
- **Page Hit**: Occurs when the requested page is already in memory.
- **LRU Strategy**: Tracks the usage of pages and selects the least recently used one for replacement.

---

## 6. Most Frequently Used (MFU) Page Replacement Algorithm
The **MFU Page Replacement Algorithm** is based on the principle that the page with the highest frequency of usage in the past is likely to be used less in the future, and thus should be replaced.

### Key Concepts:
- Tracks the frequency of page access.
- Replaces the page with the highest access count during a page fault.

---

## 7. Banker’s Algorithm
The **Banker's Algorithm** is a resource allocation and deadlock avoidance algorithm in operating systems. It ensures the system operates in a **safe state**, where deadlocks are prevented.

### Key Concepts:
- **Processes**: Units that request and release resources.
- **Resources**: Divisible and reusable entities required by processes (e.g., CPU cycles, memory).
- **Safe State**: A state where all processes can complete without deadlocks.

---

## 8. Deadlock and Safe States
**Deadlock** occurs when processes are waiting for resources held by each other, creating a cycle of dependencies with no process able to proceed.

### Deadlock Avoidance:
- Ensures that the system never enters an unsafe state by carefully allocating resources.
- The **Banker's Algorithm** is a classic method for deadlock avoidance.

---

## 9. FIFO Page Replacement Algorithm
The **FIFO (First-In-First-Out) Page Replacement Algorithm** is one of the simplest page replacement strategies used in operating systems. It replaces the oldest page in memory when a page fault occurs.

### Key Concepts:
- **Page Fault**: Occurs when a page referenced by a process is not in memory.
- **Page Hit**: Occurs when a requested page is already in memory.
- **FIFO Principle**: Replaces the page that has been in memory the longest, as it is considered the "first-in" page.
