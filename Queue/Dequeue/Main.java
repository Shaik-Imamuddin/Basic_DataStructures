import java.util.Scanner;

class Node{
    int data;
    Node prev;
    Node next;

    Node(int val){
        data=val;
        prev=null;
        next=null;
    }
}

public class Main{
    static Node front=null;
    static Node rear=null;

    static void insertFront(int val){
        Node newNode=new Node(val);
        newNode.next=front;

        if(front==null)
            rear=newNode;
        else
            front.prev=newNode;

        front=newNode;
    }

    static void insertRear(int val){
        Node newNode=new Node(val);
        newNode.prev=rear;

        if(rear==null)
            front=newNode;
        else
            rear.next=newNode;

        rear=newNode;
    }

    static void deleteFront(){
        if(front==null){
            System.out.println("Dequeue Underflow");
            return;
        }

        front=front.next;

        if(front==null)
            rear=null;
        else
            front.prev=null;
    }

    static void deleteRear(){
        if(rear==null){
            System.out.println("Dequeue Underflow");
            return;
        }

        rear=rear.prev;

        if(rear==null)
            front=null;
        else
            rear.next=null;
    }

    static void display(){
        if(front==null){
            System.out.println("Dequeue is Empty");
            return;
        }

        Node temp=front;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int val;

        do{
            val=sc.nextInt();
            if(val!=-1){
                if(val%2==0)
                    insertRear(val);
                else
                    insertFront(val);
            }
        }while(val!=-1);

        display();
        deleteFront();
        deleteRear();
        display();
    }
}