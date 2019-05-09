#define _PROGRAM_NAME "whoami"
#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  register struct passwd *pw;
  register uid_t uid;
  
  uid = geteuid ();
  pw = getpwuid (uid);
  if (pw){
      puts (pw->pw_name);
      return 0;
  }
  fprintf (stderr,"%s: Impossivel achar o usuario do UID: %u\n",
       _PROGRAM_NAME, (unsigned) uid);
  return 0;
}
