CC =gcc

INC_FOLDERS=-Iarrays -Istrings -Ifun_pointers

vpath %.c ./ arrays/
VPATH = ./ arrays
CFLAGS = $(INC_FOLDERS) -c

SRC := $(wildcard *.c ) array_func.c 

OBJ := $(patsubst %.c, %.o, $(SRC))
OUT := ctests 
ARG =-Wpedantic

OBJDIR := _build
OBJS := $(addprefix $(OBJDIR)/,$(OBJ))


$(OBJDIR)/%.o: %.c
	@echo $(SRC)
	@echo $(OBJ)
	@echo "compile "$<
	$(CC) $(ARG) $(CFLAGS) $< -o $@

OUTPUT_OPTION = 

all: $(OBJS)
	$(CC) $^ -o $(OUT)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean: 
	-rm *.o
	-rm $(OBJDIR)/*.o
	-rm $(OUT)

