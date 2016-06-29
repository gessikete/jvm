RM := rm -rf
CC := gcc -m32
CFLAGS := -g -Wall -std=c99
LDLIBS := -lm
MKDIR = mkdir -p

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:%.c=%.o)
DEPS := $(SOURCES:%.c=%.d)
BINARY := jvm
RMBIN := rm $(BINARY)
FILES_TO_CLEAN := $(OBJECTS) $(DEPS)
OUT_DIR := bin/

.PHONY : all clean

all : $(OUT_DIR) $(BINARY)

${OUT_DIR}:
	${MKDIR} ${OUT_DIR}

clean :
	$(RM) $(OUT_DIR) $(RMBIN)

-include $(DEPS)

$(OBJECTS) : %.o : %.c
	$(CC) $(CFLAGS) -c -MMD -o $(OUT_DIR)$@ $<

$(BINARY) : $(OBJECTS)
	$(CC) -o $@ $(OUT_DIR)*.o $(LDLIBS)
