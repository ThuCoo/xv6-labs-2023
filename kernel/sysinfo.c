#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "sysinfo.h"
#include "syscall.h"
#include "defs.h"

uint64
sys_sysinfo(void)
{
    struct sysinfo info;
    uint64 addr; // user pointer to struct sysinfo

    argaddr(0, &addr);

    info.freemem = kfreemem();
    info.nproc = nproc();

    if(copyout(myproc()->pagetable, addr, (char *)&info, sizeof(info)) < 0)
        return -1;

    return 0;
}