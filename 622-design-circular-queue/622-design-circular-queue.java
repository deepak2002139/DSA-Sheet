class MyCircularQueue 
{

    int queue[];
    int size=0;
    int front=0;
    int rear=0;

    public MyCircularQueue(int k) 
    {
        queue = new int[k];
        Arrays.fill(queue , -1);

    }

    public boolean enQueue(int value)
    {

        if(isFull()) return false;

        if(isEmpty())
        {
            front =rear=0;
            size++;
            queue[rear]=value;
            return true;
        }


        rear++;
        size++;
        rear = rear%queue.length;
        queue[rear] = value;
        return true;

    }

    public boolean deQueue()
    {
        if(isEmpty()) return false;

        queue[front]=-1;
        front++;
        size--;
        front = front% queue.length;
        return true;

    }

    public int Front() 
    {
        return queue[front];
    }

    public int Rear()
    {
        return queue[rear];
    }

    public boolean isEmpty() 
    {
        return size==0;
    }

    public boolean isFull() 
    {
        return size==queue.length;
    }

}