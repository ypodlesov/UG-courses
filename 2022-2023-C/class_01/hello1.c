#include <stdio.h> // подключаем библиотеку stdio.h  

int main() // начинаем нашу функцию main
{
    printf("Hello! What is your name?\n"); // выводим на экран сообщение и ставим в конце перенос строки (\n)
    char name[50];
    scanf("%s", name); // считывание имени с консоли
    printf("Nice to meet you, %s!\n", name); // вывод еще одного сообщения на консоль (с переводом строки в конце)

    return 0; // завершаем функцию main
}



