#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *d;
  char *path;

  // Parse command line to find directory
  if (argc == 1)
  {
    path = ".";
    printf("Directory: %s\n", path);
  }
  else if (argc == 2)
  {
    path = argv[1];
    printf("Directory: %s\n", path);
  }
  else
  {
    printf("Cannot find directory\n");
    exit(1);
  }
  // Open directory
  d = opendir(path);
  // checking for errors
  if (d == NULL)
  {
    printf("Cannot open directory\n");
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *ent;
  while ((ent = readdir(d)) != NULL)
  {
    //printf("File name:%s\n", ent->d_name);
    struct stat buf;
    char fullpath[strlen(path) + strlen(ent->d_name)];
    strcpy(fullpath, path);
    strcat(fullpath, "/");
    strcat(fullpath, ent->d_name);

    stat(fullpath, &buf);
    //printf("File size: %lld bytes\n", buf.st_size);
    printf("%lld %s\n", buf.st_size, ent->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}