import java.util.Scanner;

class Queue{
    int front,rear;
    int SIZE=100;
    int[] queue=new int[SIZE];

    Queue(){
        front=-1;
        rear=-1;
    }

    void enqueue(int val){
        if(rear==SIZE-1){
            System.out.println("Queue Overflow!");
            return;
        }
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=val;
    }

    void dequeue(){
        if(front==-1 || front>rear){
            System.out.println("Queue Underflow!");
            return;
        }
        System.out.println(queue[front]);
        front++;
    }

    void peek(){
        if(front==-1 || front>rear){
            System.out.println("Queue is empty!");
            return;
        }
        System.out.println("Front element: "+queue[front]);
    }

    void display(){
        if(front==-1 || front>rear){
            System.out.println("Queue is empty!");
            return;
        }
        for(int i=front;i<=rear;i++)
            System.out.print(queue[i]+" ");
        System.out.println();
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Queue q=new Queue();
        int val;
        do{
            val=sc.nextInt();
            if(val!=-1)
                q.enqueue(val);
        }while(val!=-1);

        q.display();
        q.dequeue();
        q.peek();
        q.display();
    }
}
