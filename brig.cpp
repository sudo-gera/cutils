#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
int main(int argc,char **argv){
 auto p=fopen("/home/gera/.brig","r");
 int q;
 long long int l,t;
 fscanf(p,"%i %lli",&q,&l);
 fclose(p);
 long int c=1000000;
 struct timeval j;
 gettimeofday(&j,0);
 t=j.tv_sec*1000000+j.tv_usec;
 if (argc==1){
  q=100;}
 else{
  int d=c/(t-l)+1;
  if (d>8) return 0;
  if(argv[1][0]=='+'){
   q+=d;}
  if(argv[1][0]=='-'){
   q-=d;}}
 p=fopen("/home/gera/.brig","w");
 fprintf(p,"%i %lli",q,t);
 fclose(p);
 char m[1000];
 sprintf(m,"zenity --notification --text=\"brightness: %i%%\"",q);
 system(m);
 sprintf(m,"xrandr --output eDP --brightness %f",q/100.0);
 system(m);
 return 0;}
