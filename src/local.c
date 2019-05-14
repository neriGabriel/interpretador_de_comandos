#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define PATH_SIZE 260

int main() {
   char cwd[PATH_SIZE];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}
