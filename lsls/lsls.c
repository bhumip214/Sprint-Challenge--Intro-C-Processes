#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  d = opendir(".");
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
    printf("File name:%s\n", ent->d_name);
    struct stat buf;
    stat(ent->d_name, &buf);
    printf("File size: %lld bytes\n", buf.st_size);
  }
  // Close directory
  closedir(d);
  return 0;
}