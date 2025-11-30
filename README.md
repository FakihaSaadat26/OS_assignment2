# OS_assignment2
README – xv6 Priority-Based Scheduler
Overview

This project extends the xv6 operating system by implementing a priority-based scheduler. Instead of the default round-robin scheduling, processes are now selected based on priority values (0–10). Higher-priority processes run first. A new system call, setpriority(), is added so that user programs can change their own priority.

How to Run xv6
1. Install Required Tools

Run the following commands inside Ubuntu:

sudo apt update
sudo apt install build-essential qemu-system-x86 git

2. Clone the xv6 Repository
git clone https://github.com/mit-pdos/xv6-public.git
cd xv6-public

3. Compile xv6
make

4. Run xv6 in QEMU
make qemu


or with serial output:

make qemu-nox

Testing the Priority Scheduler
1. Change process priority in xv6

Inside the xv6 shell:

setpriority(10);   // Highest priority

2. Run multiple processes
ls
stress
usertests


The highest-priority runnable process will execute first.

Run the System After Changes

After modifying scheduler files (proc.c, proc.h, syscall.c, etc.):

make clean
make qemu

Files Modified for Priority Scheduling

proc.h → added int priority;

proc.c → modified scheduler() and added logic

syscall.h → added system call number for setpriority

syscall.c → registered new system call

sysproc.c → implemented sys_setpriority

user.h → added function prototype

usys.S → generated user stub

Feature Summary

Default priority = 5

Priority range = 0 to 10

Child inherits parent’s priority

Scheduler picks the highest-priority RUNNABLE process

New system call: setpriority(int p)
