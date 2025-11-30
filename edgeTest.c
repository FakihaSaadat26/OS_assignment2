#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    printf(1, "\n=== PRIORITY EDGE CASE TEST ===\n");

    int res1 = setpriority(-3);
    printf(1, "setpriority(-3) returned: %d (expected -1)\n", res1);

    int res2 = setpriority(20);
    printf(1, "setpriority(20) returned: %d (expected -1)\n", res2);

    int res3 = setpriority(7);
    printf(1, "setpriority(7) returned: %d (expected 0)\n", res3);

    for (int i = 0; i < 5; i++) {
        printf(1, "Edge test running iteration %d\n", i);
        sleep(10);
    }

    printf(1, "EDGE CASE TEST DONE.\n");
    exit();
}
