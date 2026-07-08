CC= gcc
CFLAGS = -Wall -g

TARGET = scheduler_simulator
OBJS = scheduler.o fcfs.o sjf.o priority.o round_robbin.o utils.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJS)
