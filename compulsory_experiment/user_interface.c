#include <linux/kernel.h>
#include <sys/syscall.h>   //系统调用的头文件
#include <unistd.h>  
#include <stdio.h>
using namespace std;
int main(){
long long user_space[6];
user_space[0]=3;
long pid=2098;	
long a= syscall(333,pid,user_space,sizeof(user_space));
printf("real pid:%d\n",pid);
printf("current process's pid:%d\n",user_space[0]);
printf("current process's status:%d\n",user_space[1]);
printf("current process's parent: %d\n",user_space[2]);
printf("first child's pid: %d\n", user_space[3]);
printf("current proccess's running time(system): %d\n",user_space[4]);
printf("current proccess's running time(user): %d\n",user_space[5]);
return 0;
}
