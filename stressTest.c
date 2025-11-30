#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    printf(1, "\n=== PRIORITY STRESS TEST ===\n");

    for (int i = 0; i < 50; i++) {
        int pid = fork();

        if (pid < 0) {
            printf(1, "Fork failed at %d\n", i);
            exit();
        }

        if (pid == 0) {
            int pr = (i % 11);   // priorities 0–10
            setpriority(pr);
            printf(1, "Child %d started (priority=%d)\n", getpid(), pr);

            for (int x = 0; x < 20000000; x++) ; // busy work

            printf(1, "Child %d exiting (priority=%d)\n", getpid(), pr);
            exit();
        }
    }

    while (wait() > 0);
    printf(1, "STRESS TEST COMPLETED.\n");
    exit();
}