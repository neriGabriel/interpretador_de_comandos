#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <limits.h>

bool is_dir(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

int listaDir(const char *cDir){
  struct dirent *entry;
  DIR *dp;
  dp = opendir(cDir);
  if (dp == NULL)
  {
  	printf("Erro ao listar diretorio \n");
    perror("opendir");
    return -1;
  }

  while((entry = readdir(dp))) printf("%s  ", entry->d_name);

  printf("\n");
  closedir(dp);
  return 0;
}

int main(int argc, char * argv[]) {
   char cwd[4096];
   getcwd(cwd, sizeof(cwd));

   if(argc < 2 && getcwd(cwd, sizeof(cwd)) != NULL) listaDir(cwd);
   else{
	   if(is_dir(argv[1]) != true){
      printf("Diretorio invalido ou nao encontrado.\n");
      exit;
      return 0;
     }
  	 listaDir(argv[1]);
   }
  return 0;
}
