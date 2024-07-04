#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Thread function
void* thread_function(void* arg) {
	int thread_id = *((int*)arg);
	printf("vai toma no cu!\n");
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];
	int rc;

	for (int i = 0; i < NUM_THREADS; ++i) {
		thread_ids[i] = i;
		rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
		if (rc) {
			printf("Error: unable to create thread %d, %d\n", i, rc);
			exit(-1);
		}
	}

	// Wait for all threads to complete
	for (int i = 0; i < NUM_THREADS; ++i) {
		pthread_join(threads[i], NULL);
	}

	printf("All threads completed\n");
	return 0;
}

