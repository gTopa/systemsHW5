#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(){
  DIR *directory1 = opendir(".");
  DIR *directory2 = opendir(".");
  DIR *directory3 = opendir(".");
  struct dirent *info1=readdir(directory1);
  struct dirent *info2=readdir(directory2);
  struct dirent *info3=readdir(directory3);
  int size=0;
  struct stat buf;
  while(info3){
    if(info3->d_type==8){
      stat(info3->d_name, &buf);
      size+=buf.st_size;
    }
    info3=readdir(directory3);
  }  
  printf("Total Directory Size: %d\n", size);
  printf("Directories:\n");
  while(info1){
    if(info1->d_type!=8){
      printf("\t %s\n", info1->d_name);
    }
    info1=readdir(directory1);
  }
  printf("RegularFiles:\n");
  while(info2){
    if(info2->d_type==8){
      printf("\t %s\n", info2->d_name);
    }
    info2=readdir(directory2);
  }
  return 0;
}
