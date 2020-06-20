#include <stdlib.h>
#include <stdio.h>
int main(int argc,char ** argv){
 char a[1024];
 sprintf(a,"sudo apt");
 int w;
 for (w=1;w<argc;++w){
  sprintf(a,"%s %s",a,argv[w]);}
 if (system(a+5)){
  system(a);}}
