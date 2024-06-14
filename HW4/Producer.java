public class Producer implements Runnable {

    //declare constructor that takes shared resource

    Double cumulative_value = 0.0;
    int count = 0;

    //do
        @Override
        public void run(){
            //synchronized block 
            //wait?
            //produce item
            //add item to cum value
            //store item
            //notify?
            //increase count
        }

        // for (int i = 1; i < 11; i++){
        //     if (i * 100000 == count){
        //         System.out.printf("Producer: Generated %d items, Cumulative value of generated items=%.3f\n", count, cumulative_value);
        //     }
        // }

        // if (count == 100000){
        //     System.out.println("Producer: Finished generating 1,000,000 items");
        // }
    //while count < 1000000
}
