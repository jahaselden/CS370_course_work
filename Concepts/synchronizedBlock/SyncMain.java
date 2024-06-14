//synchronized block is one way you can manage a thread safe way to access a shared data structure in a multi-threaded program

public class SyncMain {

    public static void main(String[] args){

        //we want to access this resource from multiple threads at the same time
        //this could be a class (SharedResource) with sharedResource as a member variable
        int[] sharedResource = new int[42];

        SyncWorker worker1 = new SyncWorker(sharedResource);
        SyncWorker worker2 = new SyncWorker(sharedResource);

        Thread t1 = new Thread(worker1);
        Thread t2 = new Thread(worker2);

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println("ERROR");
        }

        System.out.println("All threads complete.");
        
    }
}