#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if(argc < 3 || (argv[1][0] < '0' || argv[1][0] > '9')){
        fprintf(2, "Usage: %s failed\n", argv[0]);
        exit(1);
    }
  // Lấy mask từ tham số dòng lệnh
    int mask = atoi(argv[1]);

    // Gọi syscall trace để thiết lập mask
    if (trace(mask) < 0) {
        fprintf(2, "%s: trace failed\n", argv[0]);
        exit(1);
    }

    // Thực thi chương trình được chỉ định
    exec(argv[2], argv + 2);

    // Nếu exec thất bại
    fprintf(2, "%s: exec %s failed\n", argv[0], argv[2]);
    exit(1);
}
// #include "kernel/param.h"
// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// int
// main(int argc, char *argv[])
// {
//     int i;
//     char *nargv [MAXARG];
//     if(argc < 3 || (argv[1][0] < '0' || argv[1][0] > '9')){
//         fprintf(2, "Usage: %s failed\n", argv[0]);
//         exit(1);
//     }   
//     if (trace(atoi(argv[1])) < 0) {
//         fprintf(2, "%s: trace failed\n", argv[0]);
//         exit(1);
//     }
//     for(i = 2; i < argc && i < MAXARG; i++){
//         nargv[i-2] = argv[i];
//     }
//     exec (nargv[0], nargv);
//     exit(0);
// }