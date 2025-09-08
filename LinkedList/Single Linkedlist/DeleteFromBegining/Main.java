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

    void deleteFromBegining(){
        if(head==null){
            System.out.println("List Is Empty.Can't Delete");
            return;
        }
        Node temp = head;
        head = head.addr;
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
        ll.deleteFromBegining();
        ll.display();
    }
}