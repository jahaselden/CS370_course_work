#declare files
FILES = ProducerConsumer.java BoundedBuffer.java Consumer.java Producer.java
 
#compile them with javac and -g flag
all:
	javac -g $(FILES)

run:
	java ProducerConsumer

clean:
	rm *.class

#.zip can be any name
package: 
	zip -r Jenny-Haselden-HW4.zip ProducerConsumer.java BoundedBuffer.java Consumer.java Producer.java Makefile README.txt