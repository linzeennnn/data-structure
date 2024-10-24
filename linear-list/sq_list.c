#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> 

int lang;

// 双语输出
void lang_print(const char *format_en, const char *format_zh, ...) {
    va_list args;
    va_start(args, format_zh);
    switch (lang) {
        case 1:
            vprintf(format_en, args);
            break;
        case 2:
            vprintf(format_zh, args);
            break;
        default:
            vprintf(format_en, args);
            break;
    }
    va_end(args);
}

// 清屏
void clear() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/Unix
#endif
}

// 按回车继续
void enter_continue() {
    lang_print("Press Enter to enter continue.....\n", "按回车继续.....\n");
    getchar(); 
    clear();
}

// 初始化
int init_list(int *list, int length) {
    int i;
    for (i = 0; i < length; i++, list++) {
        lang_print("input place %d value(0 to stop): ", "输入位置%d的值(0停止): ", i + 1);
        scanf("%d", list);
        getchar();
        if (!*list) {
            break;
        }
    }
    lang_print("init completed\n", "初始化完成\n");
    lang_print("list length is %d\n", "列表长度是 %d\n", i);
    enter_continue();
    return i;
}

// 遍历顺序表
void traverse_list(int *list, int length) {
    printf("----------------------\n");
    for (int i = 0; i < length; i++) {
        if (!list[i]) {
            break;
        } else {
            printf("%d ", list[i]);
        }
    }
    printf("\n");
    printf("----------------------\n");
    enter_continue();
}

// 插入
int insert_list(int *list,int real_length,int length) {
    if(real_length==length){
        lang_print("list full already\n","表已经满\n");
        enter_continue();
    return real_length;
    }
    int place, value,i=real_length-1;
    lang_print("input the place you want to insert: ", "输入想要插入值的位置: ");
    scanf("%d", &place);
    clear();
    printf("%d",real_length);
    if(place>length){
        lang_print("the place is exceed the max length\n","位置值超出最大长度\n");
        insert_list(list,real_length,length);
        return real_length;
    }
    else if(place>real_length){
        lang_print("the place will set in list tail\n","位置将置于表尾\n");
        place=real_length+1;
    }
    lang_print("input the value you want to change in place %d: ", "输入想要更改的位置 %d 的值: ", place);
    scanf("%d", &value);
    for(i;i>=place-1;i--){
        list[i+1]=list[i];
    }
    list[place-1] = value;
    clear();
    getchar();
    lang_print("insert completed\n", "插入完成\n");
    enter_continue();
    real_length ++;
    return real_length;
}

// 搜索
void search_list(int *list, int length) {
    int value, match = 0; 
    lang_print("input the value you want to search: ", "输入要查找的值: ");
    scanf("%d", &value);
    getchar();
    printf("----------------------\n");
    for (int i = 0; i < length; i++, list++) {
        if (value == *list) {
            lang_print("value %d in num: %d\n", "值 %d 在位置: %d\n", value, i + 1);
            match = 1;
        }
    }
    if (!match) {
        lang_print("value not found\n", "找不到这个值\n");
    }
    printf("----------------------\n");
    enter_continue();
}

// main
int main() {
    clear();
    int length, end = 0, option,real_length;
    printf("1(English) 2(中文): ");
    scanf("%d", &lang);
    clear();
    lang_print("input the length of sq list: ", "输入顺序表长度: ");
    scanf("%d", &length);
    int sq_list[length];
    clear();
   real_length=init_list(sq_list, length);
    while (!end) {
        lang_print("1: traverse the list\n2: search value in list:\n3: insert value in list\n0: end this program\n", "1: 遍历列表\n2: 在列表中搜索值:\n3: 在列表中插入值\n0: 结束程序\n");
        lang_print("input your option: ", "输入选项: "); 
        scanf("%d", &option);
        getchar();
        clear();
        switch (option) {
            case 0:
                end = 1;
                break;
            case 1:
                traverse_list(sq_list, length);
                break;
            case 2:
                search_list(sq_list, length);
                break;
            case 3:
                real_length=insert_list(sq_list,real_length,length);
                break;
            default:
                lang_print("Invalid option. Please try again.\n", "选项不正确，重新输入.\n");
                break;
        }
    }
    lang_print("end\n", "结束\n");
    return 0;
}
