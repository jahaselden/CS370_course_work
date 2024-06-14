//buffer data structure (array[1000])

//buffer size variable: initialized to 1000

//in variable: next free position (for producer) 
//in = (in + 1) % buffer_size

//out variable: first full position (for consumer)
//out = (out + 1) % buffer_size


//retrieve method - synchronize on data structure?
//consumes from the head of the buffer
//if in == out, there are no items to consume (buffer is empty) 
// (this could also mean the buffer is full??)

//store method - synchronize on data structure?
//adds to the tail of the buffer
//if (in + 1) % buffer_size == out, no more slots to produce to (buffer is full)

//bounded circular buffer

