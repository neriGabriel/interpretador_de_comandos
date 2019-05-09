#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <sys/utsname.h>

int main (int argc, char * argv[]) {

  time_t t = time(NULL);
	struct tm tm = *localtime(&t);

  struct utsname uname_pointer;
  uname(&uname_pointer);

  if (argc < 2)
    printf("%d/%d/%d %d:%d:%d\n", tm.tm_mday, tm.tm_mon + 1 ,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  else if (argc == 2 && strcmp(argv[1], "-s") == 0){
    printf("%d/%d/%d %d:%d:%d | S.O:", tm.tm_mday, tm.tm_mon + 1 ,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("%s \n", uname_pointer.sysname);
  }
  else if (argc == 2 && strcmp(argv[1], "-v") == 0) {
    printf("%d/%d/%d %d:%d:%d | ", tm.tm_mday, tm.tm_mon + 1 ,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Versao: %s \n", uname_pointer.version);
  }
  else if (argc == 2 && strcmp(argv[1], "-all") == 0) {
    printf("%d/%d/%d %d:%d:%d | S.O:", tm.tm_mday, tm.tm_mon + 1 ,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("%s | ", uname_pointer.sysname);
    printf("Versao: %s \n", uname_pointer.version);
  }

	return 0;
}
