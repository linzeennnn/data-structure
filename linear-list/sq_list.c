#include<stdio.h>
#include<stdlib.h>
// 初始化
void init_list(int *list,int lenght){
    int i;
    for(i=0;i<lenght;i++,list++){


    }
}
// 遍历顺序表
void traverse_list(int length){
    int i;
    for (i = 0; i <length; i++)
    {
        if (!list[i])
        {
        printf("null");
        }
        else{
            printf(list[i]);
        }
        printf(" ");
    }
}








int main(){
int length,i;
printf("input sq list lenght:");
scanf("%d",length);
int sq_list[lenght];
traverse_list(length);
printf("the list length is:%d",i);
    return 0;
}