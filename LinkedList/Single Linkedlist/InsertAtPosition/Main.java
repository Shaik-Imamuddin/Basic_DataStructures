import java.util.Scanner;

class Node{
    int data;
    Node addr;

    Node(int val){
        data=val;
        addr=null;
    }
}

class LinkedList{
    private Node head;

    LinkedList(){
        head=null;
    }

    void insertAtEnd(int val){
        Node newNode= new Node(val);
    
        if(head==null){
            head=newNode;
        }
        else{
            Node temp = head;
            while (temp.addr!=null) {
                temp = temp.addr;
            }
            temp.addr=newNode;
        }
    }

    void insertAtPosition(int val,int pos){
        Node newNode = new Node(val);
        if(pos==1){
            newNode.addr=head;
            head=newNode;
            return;
        }

        Node temp = head;
        int count = 1;

        while(temp!=null && count<pos-1){
            temp = temp.addr;
            count++;
        }

        if(temp==null){
            System.out.print("Position Out Of Bounds");
            return;
        }
        newNode.addr = temp.addr;
        temp.addr = newNode;  
    }
    
    void display(){
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
        LinkedList ll = new LinkedList();
        int val;
        do{
            val=sc.nextInt();
            if(val!=-1)
                ll.insertAtEnd(val);
        }while(val!=-1);

        int val1=sc.nextInt();
        int pos = sc.nextInt();

        ll.insertAtPosition(val1,pos);

        ll.display();
    }
    
}