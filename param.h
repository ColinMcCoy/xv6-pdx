#define NPROC        64  // maximum number of processes
#define KSTACKSIZE 4096  // size of per-process kernel stack
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
// #define FSSIZE       1000  // size of file system in blocks
#define FSSIZE       2000  // size of file system in blocks  // CS333 requires a larger FS.
#ifdef CS333_P2
// default uid values for both the first process and files
// created by mkfs when the file system is created
#define UID_DEFAULT 0    
#define GID_DEFAULT 0     
#ifdef CS333_P5
// default mode setting for files created
// by mkfs when the file system is created
#define MODE_DEFAULT 0755 
#endif
#endif
#ifdef CS333_P3P4
#define MAXPRIO           6         // number of priority queues is equal to MAXPRIO + 1
#define BUDGET            1000      // CPU time budget before demotion
#define TICKS_TO_PROMOTE  5000      // scheduler ticks before promotion
#endif
