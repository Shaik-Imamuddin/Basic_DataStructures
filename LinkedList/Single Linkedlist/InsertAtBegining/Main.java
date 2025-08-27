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

    void insertatbegining(int val){
        Node newnNode = new Node(val);
        newnNode.addr=head;
        head=newnNode;
    }

    void display(){
        if(head==null){
            System.out.println("List is Empty");
        }
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.addr;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Linkedlist ll = new Linkedlist();
        int val;
        do{
            val=sc.nextInt();
            if(val!=-1)
                ll.insertatbegining(val);
        }while(val!=-1);
        ll.display();
    }
}
