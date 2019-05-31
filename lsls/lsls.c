#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *d;
  char *path;

  // finding directory
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
    printf("Cannot open '%s'\n", path);
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *ent;
  while ((ent = readdir(d)) != NULL)
  {
    printf("File name:%s\n", ent->d_name);
    struct stat buf;
    stat(ent->d_name, &buf);
    printf("File size: %lld bytes\n", buf.st_size);
  }
  // Close directory
  closedir(d);
  return 0;
}