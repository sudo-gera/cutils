#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){
 if(argc==1){
  return system("nano");}
 int w;
 int sudo=0;
 for (w=1;w<argc;w++){
  if (access(argv[w],W_OK)){
   if (errno==EACCES){
    sudo=1;}
   if (errno==EROFS){
    sudo=1;}}}
 char s[1000];
 s[0]='\0';
 if (sudo){
  strcat(s,"sudo ");}
 strcat(s,"nano ");
 for (w=1;w<argc;w++){
  strcat(s,argv[w]);
  strcat(s," ");}
 return system(s);}
