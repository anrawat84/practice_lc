

//algo for client server using thread pool, mutex and cond variables

pthread_t thread_pool[THREAD_POOL_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_val = PTHREAD_COND_INITIALIZER;

create_thread_pool(thread_t *t, NULL, th_func, NULL)
{
	for (int i = 0; i < THREAD_POOL_SIZE; i++) {
		pthread_create(&t[i], NULL, thread_function, NULL);
	}
}

void *thread_function(void *arg) {
	while (true) {
		int *pclient;
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&condition_var, &mutex);
		pclient = dequeue();
		pthread_mutex_unlock(&mutex);

		if (pclient != NULL) {
			handle_connection(pclient);
		}
	}
}
int main() {
	thread_t thread_pool[10];
	create_thread_pool(thread_pool, NULL, thread_function, NULL);
	
	// create a socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	bind(server_socket, &(server_addr));
	listen(server_socket, SERVER_BACKLOG);

	while (TRUE) {
		printf("\n\n Waiting for connections.. \n");
		client_socket = accept(server_socket, &client_addr); 
		printf("\n\n Connected !!");

		// Do whatever we do with connections
		// Put the connection somewhere so that an avaiable thread 
		// can find it.

		int *pclient = malloc(sizeof(int));
		*pclient = client_socket;

		//make sure only one thread can access the queue at a time.
		pthread_mutex_lock(&mutex);
		enqueue(pclient);
		pthread_cond_signal(&condition_var);
		pthread_mutex_unlock(&mutex);
	}
}
