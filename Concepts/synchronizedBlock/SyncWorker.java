
public class SyncWorker implements Runnable {

    private int[] sharedResource;

    public SyncWorker(int[] sharedResource){
        this.sharedResource = sharedResource;
    }

    public void run() {
        //synchronized block is a way that you can manage thread sage access to a data structure from multiple threads, concurrently
        //to do this - use the synchronized keyword with shared resource as parameter 
        synchronized(this.sharedResource){
            //access the variable by index
            //set indices, etc
            //these will be thread safe because they are accessed in the block

            //go to https://infospaces.cs.colostate.edu/watch.php?id=285 about minute 4.5 to review suggestions for implementing access with bounded buffer

        }
    }
}