import java.util.Random;

public class Producer implements Runnable {

    Double cumulative_value = 0.0;
    int count = 0;
    BoundedBuffer buffer;

    //declare constructor that takes shared resource
    public Producer(BoundedBuffer buffer){
        this.buffer = buffer;
    }

    @Override
    public void run(){
        do {
            //produce item
            Double bufferElement = generateItem();
            //add item to cum value
            cumulative_value += bufferElement;
            //store item
            try {
                buffer.store(bufferElement);
            } catch (InterruptedException e) {
                System.out.println("exception caught in producer\n");
            }
            
            //increase count
            count++;

            printValues();

        } while (count < 1000000);
    }

    public Double generateItem(){
        Random random = new Random();
        return random.nextDouble() * 100.0;
    }

    public void printValues(){
        for (int i = 1; i < 11; i++){
            if (i * 100000 == count){
                System.out.printf("Producer: Generated %d items, Cumulative value of generated items=%.3f\n", count, cumulative_value);
            }
        }
        if (count == 1000000){
            System.out.println("Producer: Finished generating 1,000,000 items");
        }
    }

}
