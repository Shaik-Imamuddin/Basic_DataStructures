import java.util.Scanner;

class Node{
    int data;
    Node prev,next;

    Node(int data){
        this.data = data;
        prev = null;
        next = null;
    }
}

class DoublyLinkedList{
    private Node head;

    DoublyLinkedList(){
        head = null;
    }

    void insertAtEnd(int val){
        Node newNode = new Node(val);
        if (head == null){
            head = newNode;
            return;
        }
        
        Node temp = head;
        while (temp.next!=null){
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    void deleteFromBeginning(){
        if(head==null){
            System.out.println("Linkedlist is Empty");
            return;
        }

        if(head.next==null){
            head = null;
        } else{
            head = head.next;
            head.prev = null;
        }
    }

    void displayForward(){
        if (head==null){
            System.out.println("Linkedlist is Empty");
            return;
        }
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }

    void displayBackward(){
        if (head == null){
            System.out.println("Linkedlist is Empty");
            return;
        }
        Node temp = head;
        while (temp.next!=null){
            temp = temp.next;
        }
        while (temp != null){
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

public class Main{
    public static void main(String[] args){
        DoublyLinkedList dll = new DoublyLinkedList();
        Scanner sc = new Scanner(System.in);
        int val;

        while(true){
            val = sc.nextInt();
            if (val==-1)
                break;
            dll.insertAtEnd(val);
        }
        dll.deleteFromBeginning();
        dll.displayForward();
        dll.displayBackward();
    }
}