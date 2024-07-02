#define _DEFAULT_SOURCE 
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void print_entry_type(struct dirent *entry) {
  switch (entry->d_type) {
    case DT_REG:
      printf("regular");
      break;
    case DT_DIR:
      printf("directory");
      break;
    case DT_LNK:
      printf("symlink");
    default:
      printf("other");
      break;
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "not enough arguments\n");
    return 1;
  }

  const char *dirname = argv[1];
  DIR *dir = opendir(dirname);

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    printf("%s: ", entry->d_name);
    print_entry_type(entry);
    printf("\n");
  }

  closedir(dir);
  return 0;
}