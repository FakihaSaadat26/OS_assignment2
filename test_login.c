#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  printf(1, "\n=== LOGIN TEST ===\n");
  int res = login("user", "userpass");
  if (res == 0) {
    printf(1, "Login as user: SUCCESS\n");
  } else {
    printf(1, "Login as user: FAIL\n");
  }
  res = login("root", "rootpass");
  if (res == 0) {
    printf(1, "Login as root: SUCCESS\n");
  } else {
    printf(1, "Login as root: FAIL\n");
  }
  res = login("hacker", "badpass");
  if (res == 0) {
    printf(1, "Login as hacker: SHOULD FAIL\n");
  } else {
    printf(1, "Login as hacker: correctly denied\n");
  }
  exit();
}
