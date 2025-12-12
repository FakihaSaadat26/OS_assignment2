#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void) {
  printf(1, "\n=== FILE PERMISSION TEST ===\n");
  // Login as user and create file
  login("user", "userpass");
  int fd = open("testfile", O_CREATE|O_RDWR);
  if (fd < 0) {
    printf(1, "File create failed\n");
    exit();
  }
  write(fd, "hello", 5);
  close(fd);

  // Try to encrypt as another user (should fail)
  login("root", "rootpass");
  int res = encrypt_file("testfile", 42);
  if (res == 0) {
    printf(1, "Root encrypted user file: OK (root override)\n");
  } else {
    printf(1, "Root encrypt failed (should not happen)\n");
  }

  // Try as wrong user
  login("hacker", "badpass");
  res = encrypt_file("testfile", 42);
  if (res == 0) {
    printf(1, "Hacker encrypted file: ERROR\n");
  } else {
    printf(1, "Hacker denied as expected\n");
  }
  exit();
}
