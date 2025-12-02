import java.util.Scanner;

class Node{
    int data;
    Node addr;
    Node(int val){
        data=val;
        addr=null;
    }
}

class Stack{
    Node top;
    Stack(){
        top=null;
    }

    void push(int val){
        Node newNode=new Node(val);
        newNode.addr=top;
        top=newNode;
    }

    void pop(){
        if(top==null){
            System.out.println("Stack Underflow!");
            return;
        }
        System.out.println(top.data);
        top=top.addr;
    }

    void peek(){
        if(top==null){
            System.out.println("Stack is empty!");
            return;
        }
        System.out.println("Top element: "+top.data);
    }

    void display(){
        if(top==null){
            System.out.println("Stack is empty!");
            return;
        }
        Node temp=top;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.addr;
        }
        System.out.println();
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Stack st=new Stack();
        int val;
        do{
            val=sc.nextInt();
            if(val!=-1)
                st.push(val);
        }while(val!=-1);

        st.display();
        st.pop();
        st.peek();
        st.display();
    }
}
