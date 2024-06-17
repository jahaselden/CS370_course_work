public class Consumer implements Runnable {

    Double cumulative_value = 0.0;
    int count = 0;
    BoundedBuffer buffer;

    // declare constructor that takes shared resource
    public Consumer(BoundedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        do {
            
            try {
                cumulative_value += buffer.retrieve();
            } catch (InterruptedException e) {
                System.out.println("exception caught in consumer\n");
            }

            count++;

            printValues();

        } while (count < 1000000);

    }

    public void printValues() {
        for (int i = 1; i < 11; i++) {
            if (i * 100000 == count) {
                System.out.printf("Consumer: Consumed %d items, Cumulative value of consumed items=%.3f\n", count,
                        cumulative_value);
            }
        }
        if (count == 1000000) {
            System.out.println("Consumer: Finished consuming 1,000,000 items");
        }
    }

}