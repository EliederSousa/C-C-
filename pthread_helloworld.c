#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

void* Hello(void* rank);

int main(int argc, char* argv[]) {
    // O número da thread (como um ID).
    long thread;
    // Um ponteiro para os manipuladores das threads (uma array de threads).
    pthread_t* thread_handles;
    
    // Número de threads a serem criadas (passado como argumento).
    thread_count = strtol(argv[1], NULL, 10);
    printf("tamanho: %d\n", sizeof(pthread_t));
    
    // Alocação de memória para as threads:
    // número de threads * o tamanho de cada uma delas
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    
    printf("Hello World from main thread\n");
    
    // Criando todas as threads.
    for( thread=0; thread < thread_count; thread++ ) {
        // Cria uma thread, indicando a função a ser executada para cada uma
        // e o argumento a ser passado para ela (void*) thread
        pthread_create(&thread_handles[thread], NULL, Hello, (void*) thread);
    }
    
    // Parando todas as threads.
    for( thread=0; thread < thread_count; thread++ ){
        // Espera que cada thread conclua sua execução.
        pthread_join(thread_handles[thread], NULL);
    }
    
    // Desalocar a memória.
    free(thread_handles);
    return 0;
}

// Argumento da função deve bater com o argumento passado na criação da thread.
void* Hello(void* rank) {
    // Dando cast o argumento (que poderia ser de qualquer tipo).
    long my_rank = (long) rank;
    
    // Faz o que for necessário para a execução.
    printf("Hello from thread %ld of %d\n", my_rank, thread_count);
    return NULL;
}
