import java.util.Scanner;
class Node{
    int data;
    Node addr;

    Node(int val){
        data=val;
        addr=null;
    }
}

class Linkedlist{
    Node head;

    Linkedlist(){
        head=null;
    }

    void insertatend(int val){
        Node newNode = new Node(val);
        if(head==null){
            head=newNode;
        }
        else{
            Node temp = head;
            while (temp.addr!=null) {
                temp=temp.addr;
            }
            temp.addr=newNode;
        }
    }

    void deleteFromEnd(){
        if(head==null){
            System.out.println("Linked list is Empty can't Delete");
        }

        if(head.addr == null){
            head = null;
            return;
        }

        Node temp = head;
        while(temp.addr.addr != null) {
            temp = temp.addr;
        }
        temp.addr = null;
    }

    void display(){
        Node temp = head;
        if(head==null){
            System.out.println("List Is Empty");
        }
        while(temp!=null) {
            System.out.print(temp.data+" ");
            temp=temp.addr;
        }
    }
}

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Linkedlist ll =new Linkedlist();
        int val;
        do{
            val = sc.nextInt();
            if(val!=-1)
                ll.insertatend(val);
        }while(val!=-1);
        ll.deleteFromEnd();
        ll.display();
    }
}