CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lpthread

TARGETS = shared_memory_chat producer_consumer shm_semaphore_combo dining_philosophers

all : $(TARGETS)

shared_memory_chat: shared_memory_chat.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

producer_consumer: producer_consumer.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

shm_semaphore_combo: shm_semaphore_combo.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

dining_philosophers: dining_philosophers.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(TARGETS)
