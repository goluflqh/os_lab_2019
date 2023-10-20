#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();
    
    if (child_pid > 0) {
        // Это родительский процесс
        printf("Родительский процесс создал дочерний процесс с PID: %d\n", child_pid);
        sleep(10); // Родительский процесс ждет 10 секунд
        system("ps -eo pid,ppid,stat,cmd");  // prints a list of processes in your terminal

    } else if (child_pid == 0) {
        // Это дочерний процесс
        printf("Дочерний процесс с PID: %d\n", getpid());
        exit(0); // Дочерний процесс завершается
    } else {
        // Ошибка при вызове fork()
        perror("Ошибка fork");
    }
    
    return 0;
}
