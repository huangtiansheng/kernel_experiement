#include <linux/kernel.h>
#include <sys/syscall.h>   //系统调用的头文件
#include <unistd.h>  
#include <stdio.h>
using namespace std;
int main(){
long user_space[1];	
long a= syscall(335,333,user_space);
if(a==0){
printf("The count number of call %d is %d\n",333,user_space[0]);
}
else{
printf("Check failure! Something happends!\n");
}
return 0;
}
