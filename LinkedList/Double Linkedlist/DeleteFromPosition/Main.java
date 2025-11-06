import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    private Node head;

    DoublyLinkedList() {
        head = null;
    }

    void insertAtEnd(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) { 
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
    }

    void deleteFromPosition(int pos) {
        if (head == null) {
            System.out.println("Linkedlist is Empty");
            return;
        }

        Node temp = head;
        int count = 1;

        while (temp != null && count < pos) {
            temp = temp.next;
            count++;
        }

        if (temp == null) {
            System.out.println("Invalid Position");
            return;
        }

        if (temp == head) {
            head = head.next;
            if (head != null){
                head.prev = null;
            }
            return;
        }

        if (temp.next != null) {
            temp.next.prev = temp.prev;
        }
        if (temp.prev != null) {
            temp.prev.next = temp.next;
        }
    }

    void displayForward() {
        if (head == null) {
            System.out.println("Linkedlist is Empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    void displayBackward() {
        if (head == null) {
            System.out.println("Linkedlist is Empty");
            return;
        }
        Node temp = head;
        while (temp.next != null) { 
            temp = temp.next;
        }
        while (temp != null) { 
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList dll = new DoublyLinkedList();
        int val;

        do{
            val = sc.nextInt();
            if (val!=-1)
                dll.insertAtEnd(val);
        } while (val!=-1);

        int pos = sc.nextInt();
        dll.deleteFromPosition(pos);
        dll.displayForward();
        dll.displayBackward();
    }
}