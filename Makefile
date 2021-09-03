CC =gcc

INC_FOLDERS=-Iarrays -Istrings -Ifun_pointers

vpath %.c main arrays strings
vpath %.h  arrays strings
#VPATH = .:arrays:strings
CFLAGS = $(INC_FOLDERS) -c
#this is important to have all folders with sources defined
FOLDERS = main arrays strings

#notdir - it returns file without folder in file name
SRC := $(foreach folder,$(FOLDERS), $(notdir $(wildcard $(folder)/*.c )))

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
	-rm $(OBJDIR)/*.o
	-rm $(OUT)

