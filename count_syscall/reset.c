#include <linux/kernel.h>
#include <sys/syscall.h>   //系统调用的头文件
#include <unistd.h>  
#include <stdio.h>
using namespace std;
int main(){	
long a= syscall(334,333);
if(a==0){
printf("Reset success!\n");
}
else{
printf("Reset failure! Something happends!\n");
}
return 0;
}
