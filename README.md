# Buffer Overflow Prevention in xv6 using ASLR

This project demonstrates how to prevent buffer overflow attacks in the xv6 operating system by implementing Address Space Layout Randomization (ASLR). It modifies the xv6 kernel to introduce randomness in the stack layout of each process and includes a user-level overflow simulation to validate the defense mechanism.

##  Objective

To enhance memory safety in the xv6 operating system by applying ASLR, which makes stack memory locations unpredictable, thus reducing the success rate of control hijacking through buffer overflow attacks.

##  Project Architecture

- A custom pseudo-random number generator is introduced in the kernel.
- During process creation, a random offset is added to the user stack pointer.
- A buffer overflow simulation program is written in user space.
- Output logs and traps are used to observe memory behavior under normal and overflow conditions.

##  Features Implemented

- ASLR applied to stack memory during process execution.
- Random stack offset generated using custom logic.
- Overflow simulation user program to test stack corruption.
- Kernel output confirms ASLR effectiveness (random stack offset, usertrap crash, etc.).
- Shell integration and validation through logs and testing.

##  Team Members & Contributions

| Member Name     | Contribution                                             |
|------------------|----------------------------------------------------------|
| Paras Sharma     | Implemented random number logic and integrated kernel build |
| Shreyas Bedi     | Developed buffer overflow simulation test cases         |
| Himanshu Singh   | Applied ASLR logic to process creation in exec          |
| Prerak Sharma    | Testing, documentation, logs, and presentation prep     |

##  Project Structure

xv6-riscv/
├── kernel/         # Kernel source files (modified for ASLR logic)
├── user/           # User programs (includes overflow test)
├── mkfs/           # Filesystem builder
├── Makefile        # Build configuration (updated for rand.c)
├── README.md       # Project documentation

##  How ASLR Works in xv6

1. A random value is generated during process initialization.
2. This value is used to shift the stack start address randomly.
3. On each execution, the stack location changes.
4. This makes it harder for attackers to reliably overwrite the return address.

##  Test Results & Validation

| Test Scenario                | Status | Observation                                      |
|-----------------------------|--------|--------------------------------------------------|
| Normal input without overflow | ✅ Pass | Program completes safely                         |
| Overflow on original xv6     | ✅ Pass | Return address hijacked → leads to crash         |
| Overflow with ASLR enabled   | ✅ Pass | Unpredictable memory → hijack fails → trap raised|

Sample Output:
ASLR IMPLEMENTED: Stack Offset = 1312 bytes
1. BUFFER OVERFLOW ATTACK SIMULATION
Enter something:
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
usertrap(): unexpected scause 0xc pid=4
sepc=0x6161616161616161 stval=0x6161616161616161

##  How to Build & Run

1. Clone the repository:
   git clone https://github.com/ParasSharma101/buffer-overflow-prevention-in-xv6.git
   cd buffer-overflow-prevention-in-xv6

2. Build the system:
   make clean
   make qemu

3. Run the test in xv6 shell:
   $ overflow

##  Important Commits

- Initial commit with xv6 base setup
- Integrated ASLR logic in process initialization
- Added random number generator and test program
- Updated Makefile and build system to include changes

##  Project Outcome

- Working ASLR-enabled xv6 kernel
- Demonstrated buffer overflow attack mitigation
- Successful validation through logs and crash outputs
- Final codebase, documentation, and presentation completed

##  Future Scope

- Extend ASLR to other segments (heap, data, code)
- Combine with stack canaries for improved protection
- Add memory protection flags (non-executable stack)
- Automate security testing using fuzzed inputs

##  License

This project is based on MIT's xv6 operating system and is intended for educational and research use only.
