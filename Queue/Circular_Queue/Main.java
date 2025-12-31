import java.util.Scanner;

class Node{
    int data;
    Node addr;
    Node(int val){
        data=val;
        addr=null;
    }
}

class Queue{
    Node front=null;
    Node rear=null;

    void enqueue(int val){
        Node newNode=new Node(val);
        if(front==null){
            front=rear=newNode;
            rear.addr=front;
        }else{
            rear.addr=newNode;
            rear=newNode;
            rear.addr=front;
        }
    }

    void dequeue(){
        if(front==null){
            System.out.println("Queue Underflow!");
            return;
        }
        if(front==rear){
            System.out.println(front.data);
            front=rear=null;
        }else{
            System.out.println(front.data);
            front=front.addr;
            rear.addr=front;
        }
    }

    void peek(){
        if(front==null){
            System.out.println("Queue is empty!");
            return;
        }
        System.out.println("Front element: "+front.data);
    }

    void display(){
        if(front==null){
            System.out.println("Queue is empty!");
            return;
        }
        Node temp=front;
        do{
            System.out.print(temp.data+" ");
            temp=temp.addr;
        }while(temp!=front);
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