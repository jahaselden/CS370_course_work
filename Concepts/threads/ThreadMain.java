
//when we run multithreaded programs, we don't see the same execution order every time
//we might, but the statements will interweave 

public class ThreadMain {

    public static void main(String[] args){

        //this will always be prior to .start()
        System.out.println("starting main thread...");

        //defines behavior of the threads
        Worker susan = new Worker("susan");
        Worker bob = new Worker("bob");

        //pass both workers to the thread ctor
        Thread susanThread = new Thread(susan);
        Thread bobThread = new Thread(bob);

        //call start on thread objects
        //these two lines cause run method in Worker class to run 
        susanThread.start();
        bobThread.start();

        //we want to wait for both threads to finish
        try {
            //effectively make main thread to wait for join to finish 
            //executing before anything else in main can run
            susanThread.join();
            bobThread.join();
        } catch (InterruptedException e){
            System.out.println("Interrupted Exception was caught.");
        }

        //will not print until both join calls are done executing their run methods 
        System.out.println("All threads complete.");

    }
}