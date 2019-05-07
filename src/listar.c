#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main (void) {
  DIR *dir;
  struct dirent *lsdir;
  dir = opendir("./");

  while ( ( lsdir = readdir(dir) ) != NULL )
  {
        printf ("%s\n", lsdir->d_name);
  }
  closedir(dir);
  return 0;
}
