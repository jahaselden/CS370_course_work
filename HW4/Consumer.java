public class Consumer implements Runnable {

    //declare constructor that takes shared resource

    Double cumulative_value = 0.0;
    int count = 0;
    
    //do
        // @Override
        // public void run(){
            //synchronized block 
            //wait?
            //store item 
            //notify?
            //increase count
        //}
        for (int i = 1; i < 11; i++){
            if (i * 100000 == count){
                System.out.printf("Consumer: Consumed %d items, Cumulative value of consumed items=%.3f\n", count, cumulative_value);
            }
        }
        if (count == 1000000){
            System.out.println("Consumer: Finished consuming 1,000,000 items");
        }
    //while count < 1000000
}