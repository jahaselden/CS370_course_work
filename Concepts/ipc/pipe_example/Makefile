#list of files 
C_SRCS = pipe.c child.c 
C_OBJS = pipe.o child.o 

#C_HEADERS aka executable images (these need to match the string passed to execlp)
OBJS = ${C_OBJS} 
EXE1 = pipe
EXE2 = child 

#compiler and loader commands and flags 
GCC = gcc 
GCC_FLAGS = -std=c11 -g -Wall -c -I. 
LD_FLAGS = -std=c11 -g -Wall -I. 

#compile .c files to .o files 
.c.o: 
	$(GCC) $(GCC_FLAGS) $< 
	
#target is the executable aka all the make commands
all: pipe child 
pipe: pipe.o 
	$(GCC) $(LD_FLAGS) pipe.o -o $(EXE1) 
child: child.o 
	$(GCC) $(LD_FLAGS) child.o -o $(EXE2) 
	
#recomplile c objects if headers change 
$(C_OBJS): ${C_HEADERS} 

#clean up directory 
clean: 
	rm -f *.o *- $(EXE1) $(EXE2) 

#.zip can be any name
package: 
	zip -r submission.zip pipe.c child.c Makefile README.txt