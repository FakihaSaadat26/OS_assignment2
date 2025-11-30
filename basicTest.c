#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    int pid1, pid2;

    printf(1, "\n=== BASIC PRIORITY TEST ===\n");

    pid1 = fork();
    if (pid1 == 0) {
        setpriority(2);   // low priority
        for (int i = 0; i < 5; i++) {
            printf(1, "[LOW ]  priority=2 running iteration %d\n", i);
            sleep(10);
        }
        exit();
    }

    pid2 = fork();
    if (pid2 == 0) {
        setpriority(9);   // high priority
        for (int i = 0; i < 5; i++) {
            printf(1, "[HIGH] priority=9 running iteration %d\n", i);
            sleep(10);
        }
        exit();
    }

    wait();
    wait();

    printf(1, "\nBASIC TEST DONE.\n");
    exit();
}