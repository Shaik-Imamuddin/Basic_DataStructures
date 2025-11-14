import java.util.Scanner;

class Stack {
    private static final int SIZE = 100;
    private int[] arr = new int[SIZE];
    private int top;

    public Stack(){
        top = -1;
    }

    public boolean isEmpty() {
        return top < 0;
    }

    public boolean isFull() {
        return top >= SIZE - 1;
    }

    public void push(int val) {
        if (isFull()) {
            System.out.println("Stack Overflow");
            return;
        }
        arr[++top] = val;
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow");
            return;
        }
        top--;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return arr[top];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return;
        }
        for (int i = top; i >= 0; i--) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Stack s = new Stack();
        Scanner sc = new Scanner(System.in);
        int val;

        while (true) {
            val = sc.nextInt();
            if (val == -1)
                break;
            s.push(val);
        }

        s.display();
        s.pop();
        s.display();

        System.out.println("Top element: " + s.peek());
    }
}