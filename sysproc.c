#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  if(myproc()->uid == -1) // not authenticated
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// Set the priority of the current process
int
sys_setpriority(void)
{
  int priority;

  if(argint(0, &priority) < 0)
    return -1;
  if(myproc()->uid == -1) // not authenticated
    return -1;
  
  return setpriority(priority);
}

// User login system call
int
sys_login(void)
{
  char *username;
  char *password;
  if(argstr(0, &username) < 0 || argstr(1, &password) < 0)
    return -1;

  // Simple hardcoded authentication for demonstration
  // In a real OS, this would check a user database
  if(strcmp(username, "root") == 0 && strcmp(password, "rootpass") == 0) {
    myproc()->uid = 0;
    myproc()->gid = 0;
    return 0; // success
  } else if(strcmp(username, "user") == 0 && strcmp(password, "userpass") == 0) {
    myproc()->uid = 1000;
    myproc()->gid = 1000;
    return 0; // success
  }
  return -1; // authentication failed
}
