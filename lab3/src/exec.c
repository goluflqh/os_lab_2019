#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Путь к исполняемому файлу sequential_min_max
    char *args[] = {"./sequential_min_max", "123", "10", NULL};

    // Запуск sequential_min_max в новом процессе
    if (execvp(args[0], args) == -1) {
        perror("execvp");
        return 1;
    }

    return 0;
}
