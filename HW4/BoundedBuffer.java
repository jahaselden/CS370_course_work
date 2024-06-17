public class BoundedBuffer {

    int BUFFER_SIZE = 1000;
    Double[] buffer = new Double[BUFFER_SIZE];
    int count = 0;
    Double temp = 0.0;

    // in variable: next free position (for producer)
    int in = 0;
    // out variable: first full position (for consumer)
    int out = 0;

    // consumes from the head of the buffer
    public synchronized Double retrieve() throws InterruptedException {
        while (count == 0) { // buffer is empty
            wait();
        }

        temp = buffer[in];

        in = (in + 1) % buffer.length;

        count--;
        notify();
        return temp;
    }

    // adds to the tail of the buffer
    public synchronized void store(Double element) throws InterruptedException {
        while (count == BUFFER_SIZE - 1) { // buffer is full
            wait();
        }

        buffer[out] = element;

        out = (out + 1) % BUFFER_SIZE;
        
        count++;
        notify();
    }

}
