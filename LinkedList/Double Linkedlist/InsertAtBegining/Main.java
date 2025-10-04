import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;
    Node(int data) {
        this.data = data;
        prev = null;
        next = null;
    }
}

class DoublyLinkedList {
    private Node head;

    public void insertAtBeginning(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        if (head != null)
            head.prev = newNode;
        head = newNode;
    }

    public void displayForward() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void displayBackward() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }
        Node temp = head;
        while (temp.next != null)
            temp = temp.next;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        Scanner sc = new Scanner(System.in);
        int val;
        do {
            val = sc.nextInt();
            if (val != -1)
                dll.insertAtBeginning(val);
        } while (val != -1);

        dll.displayForward();
        dll.displayBackward();
    }
}