#list of files 
C_SRCS = fork.c childtask.c 
C_OBJS = fork.o childtask.o 

#C_HEADERS aka executable images (these need to match the string passed to execlp)
OBJS = ${C_OBJS} 
EXE1 = fork 
EXE2 = childtask 

#compiler and loader commands and flags 
GCC = gcc 
GCC_FLAGS = -std=c11 -g -Wall -c -I. 
LD_FLAGS = -std=c11 -g -Wall -I. 

#compile .c files to .o files 
.c.o: 
	$(GCC) $(GCC_FLAGS) $< 
	
#target is the executable aka all the make commands
all: fork childtask 
fork: fork.o 
	$(GCC) $(LD_FLAGS) fork.o -o $(EXE1) 
childtask: childtask.o 
	$(GCC) $(LD_FLAGS) childtask.o -o $(EXE2) 
	
#recomplile c objects if headers change 
$(C_OBJS): ${C_HEADERS} 

#clean up directory 
clean: 
	rm -f *.o *- $(EXE1) $(EXE2) 

#.zip can be any name
package: 
	zip -r submission.zip fork.c childtask.c Makefile README.txt