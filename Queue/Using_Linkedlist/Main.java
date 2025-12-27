import java.util.Scanner;

class Node{
    int data;
    Node addr;
    Node(int val){
        data=val;
        addr=null;
    }
}

public class Main{
    static Node front=null;
    static Node rear=null;

    static void enqueue(int val){
        Node newNode = new Node(val);
        if(rear==null){
            front=rear=newNode;
        } else {
            rear.addr=newNode;
            rear=newNode;
        }
    }

    static void dequeue(){
        if(front==null){
            System.out.println("Queue Underflow!");
            return;
        }
        System.out.println(front.data);
        front=front.addr;
        if(front==null) rear=null;
    }

    static void peek(){
        if(front==null){
            System.out.println("Queue is empty!");
            return;
        }
        System.out.println("Front element: "+front.data);
    }

    static void display(){
        if(front==null){
            System.out.println("Queue is empty!");
            return;
        }
        Node temp=front;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.addr;
        }
        System.out.println();
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int val;
        do{
            val=sc.nextInt();
            if(val!=-1)
                enqueue(val);
        }while(val!=-1);

        display();
        dequeue();
        peek();
        display();
    }
}