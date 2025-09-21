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

    void deleteFromPosition(int pos){
        if(head==null){
            System.out.println("LinkedList is Empty");
            return;
        }

        if(pos<0){
            System.out.println("Invalid Position");
            return;
        }

        Node temp = head;

        if(pos==1){
            temp = head.addr;
            System.out.println(head.data+" is Deleted");
            head=head.addr;
            return;
        }

        Node prev = null;
        
        
        for(int i=1;temp!=null && i<pos;i++){
            prev = temp;
            temp = temp.addr;
        }

        if(temp == null){
            System.out.println("Position out of Range");
            return;
        }
        prev.addr = temp.addr;
        System.out.println(temp.data+" is Deleted");
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
        int val,pos;
        do{
            val = sc.nextInt();
            if(val!=-1)
                ll.insertatend(val);
        }while(val!=-1);
        pos = sc.nextInt();
        ll.deleteFromPosition(pos);
        ll.display();
    }
}