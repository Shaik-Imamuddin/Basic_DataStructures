import java.util.Scanner;

class Node{
    int data;
    Node addr;

    Node(int val){
        data = val;
        addr = null;
    }
}

public class Main{
    static Node head = null;

    public static void insertAtEnd(int val){
        Node newNode = new Node(val);

        if(head==null){
            head = newNode;
            newNode.addr = head;
        }
        else{
            Node temp = head;
            while (temp.addr!=head){
                temp = temp.addr;
            }
            temp.addr = newNode;
            newNode.addr = head;
        }
    }

    public static void display(){
        if (head == null){
            System.out.println("List is Empty");
            return;
        }

        Node temp = head;
        do{
            System.out.print(temp.data + " ");
            temp = temp.addr;
        }while(temp!=head);

        System.out.println();
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int val;

        do{
            val = sc.nextInt();
            if (val!=-1)
                insertAtEnd(val);
        }while(val!=-1);
        display();
    }
}