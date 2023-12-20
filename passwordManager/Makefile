CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
SOURCE = password_manager.c
EXECUTABLE = password_manager

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(EXECUTABLE)

exe:
	./${EXECUTABLE}
src:
	vim ${EXECUTABLE}.c
