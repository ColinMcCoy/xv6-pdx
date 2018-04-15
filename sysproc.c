#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#ifdef CS333_P2
#include "uproc.h"
#endif

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
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
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
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      return -1;
    }
    sleep(&ticks, (struct spinlock *)0);
  }
  return 0;
}

// return how many clock tick interrupts have occurred
// since start. 
int
sys_uptime(void)
{
  uint xticks;
  
  xticks = ticks;
  return xticks;
}

//Turn of the computer
int
sys_halt(void){
  cprintf("Shutting down ...\n");
  outw( 0x604, 0x0 | 0x2000);
  return 0;
}

#ifdef CS333_P1
// return the date in UTC
int
sys_date(void){
  struct rtcdate *d;
  if(argptr(0, (void*)&d, sizeof(struct rtcdate)) < 0)
    return -1;
  cmostime(d);
  return 0;
}
#endif

#ifdef CS333_P2
// return the uid of the current process
uint
sys_getuid(void)
{
  return proc->uid;
}

// return the gid of the current process
int
sys_getgid(void)
{
  return proc->gid;
}

// return the parent pid of the current process
int
sys_getppid(void)
{
  if(proc->pid == 1)
    return proc->pid;
  return proc->parent->pid;
}

// set uid of the current process. return -1 if unsuccesful
int 
sys_setuid(void)
{
  int u;
  argint(0, &u);
  if(u < 0 || u > 32767)
    return -1;
  proc->uid = (uint) u;
  return 0;
}

// set gid of the current process. return -1 if unsuccesful
int
sys_setgid(void)
{
  int g;
  argint(0, &g);
  if(g < 0 || g > 32767)
    return -1;
  proc->gid = (uint) g;
  return 0;
}

// fills table with uproc representations of running processes
int
sys_getprocs(void)
{
  int max;
  argint(0, &max);
  if(max < 0)
    return -1;
  struct uproc* table;
  if(argptr(1, (void*)&table, sizeof(struct uproc)) < 0)
    return -1;
  return getuprocs(max, table);

   // = (uproc*) malloc(max * sizeof(uproc))
}
#endif
