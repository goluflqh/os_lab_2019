#include <stdio.h>
#include <pthread.h>

// Глобальные переменные
pthread_mutex_t mutex1, mutex2;

void *thread1() {
    // Блокируем первый мьютекс
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: Захватил mutex1.\n");

    // Пытаемся захватить второй мьютекс
    printf("Thread 1: Пытаюсь захватить mutex2.\n");
    pthread_mutex_lock(&mutex2);

    // Недостижимый код
    printf("Thread 1: Захватил оба мьютекса.\n");

    // Разблокируем оба мьютекса
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    pthread_exit(NULL);
}

void *thread2() {
    // Блокируем второй мьютекс
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Захватил mutex2.\n");

    // Пытаемся захватить первый мьютекс
    printf("Thread 2: Пытаюсь захватить mutex1.\n");
    pthread_mutex_lock(&mutex1);

    // Недостижимый код
    printf("Thread 2: Захватил оба мьютекса.\n");

    // Разблокируем оба мьютекса
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    pthread_exit(NULL);
}

int main() {
    // Инициализируем мьютексы
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // Создаем потоки
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Ждем завершения потоков
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Уничтожаем мьютексы
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
