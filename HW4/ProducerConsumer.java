public class ProducerConsumer {

    public static void main(String[] args) {

        // create BoundedBuffer object
        BoundedBuffer buffer = new BoundedBuffer();

        // create new consumer & producer with boundedBuffer
        Consumer consumer = new Consumer(buffer);
        Producer producer = new Producer(buffer);

        // create new thread using consumer & producer
        Thread t1 = new Thread(consumer);
        Thread t2 = new Thread(producer);

        // start threads (to execute their run() methods)
        t1.start();
        t2.start();

        // we want to wait for both threads to finish
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println("Interrupted Exception was caught.");
        }

        System.out.println("Exiting!");

    }
}
