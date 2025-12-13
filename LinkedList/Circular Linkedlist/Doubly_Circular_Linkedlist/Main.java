import java.util.Scanner;

class Node{
    int data;
    Node prev, next;

    Node(int val){
        data = val;
        prev = null;
        next = null;
    }
}

class LinkedList{
    private Node head;

    LinkedList(){
        head = null;
    }

    void insertAtEnd(int val){
        Node newNode = new Node(val);

        if(head == null){
            newNode.next = newNode;
            newNode.prev = newNode;
            head = newNode;
        } else{
            Node temp = head.prev;  

            newNode.next = head;
            newNode.prev = temp;

            temp.next = newNode;
            head.prev = newNode;
        }
    }

    void displayForward(){
        if(head == null){
            System.out.println("List is Empty");
            return;
        }

        Node temp = head;
        while(temp.next != head){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println(temp.data);
    }

    void displayBackward(){
        if (head == null){
            System.out.println("List is Empty");
            return;
        }

        Node temp = head.prev;   

        while (temp != head){
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println(head.data);
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();

        int val;

        do{
            val = sc.nextInt();
            if (val != -1)
                list.insertAtEnd(val);
        } while (val != -1);

        list.displayForward();
        list.displayBackward();
    }
}