#ifndef _SYSINFO_H_
#define _SYSINFO_H_

struct sysinfo {
    uint64 freemem; // Số byte bộ nhớ trống
    uint64 nproc;   // Số tiến trình không ở trạng thái UNUSED
};

#endif // _SYSINFO_H_