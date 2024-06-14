public class Worker implements Runnable {

    public String name;

    public Worker(String name){
        this.name = name;
    }

    //any class that implements the runnable interface needs to declare a public void run()
    public void run() {
        for (int i = 0; i < 5; i++){
            System.out.println("Hello from the thread named " + name + " index = " + i);
        }
    }
}