import java.util.Scanner;
public class Stack {
  static Scanner sc = new Scanner(System.in);
  static int stack[], top = -1, size;

  static {
    Stack.create();
  }

  public static void main(String[] args) {
    int ch, val;
    while(true) {
      System.out.println("1.Push");
      System.out.println("2.Pop");
      System.out.println("3.Peek");
      System.out.println("4.Traverse");
      System.out.println("5.Quit");

      System.out.print("Enter choice: ");
      ch = Stack.sc.nextInt();

      switch (ch) {
        case 1: System.out.println("Enter value to push");
                val = sc.nextInt();
                push(val);
                break;
        case 2: val = pop();
                if(val == 0) {
                  System.out.println("Stack is empty");
                }
                else {
                  System.out.println("Popped: " + val);
                }
                break;
        case 3: val = peek();
                if(val == 0) {
                  System.out.println("Stack is empty");
                }
                else {
                  System.out.println("Peek: " + val);
                }
                break;
        case 4: traverse();
                break;
        case 5: System.exit(1);
        default: System.out.println("invalid");
      }
    }
  }

  static void create() {
    System.out.print("Enter size: ");
    size = Stack.sc.nextInt();
    stack = new int[Stack.size];
    System.out.println("Succesfully created stack of size: " + size);
  }

  static void push(int val) {
    if(Stack.isFull()) {
      System.out.println("Stack overflow\n");
    }
    else {
      stack[++top] = val;
    }
  }

  static boolean isFull() {
    if(top == size-1) return true;
    else return false;
  }

  static boolean isEmpty() {
    if(top == -1) return true;
    else return false;
  }

  static int pop() {
    if(Stack.isEmpty()) {
      return 0;
    }
    else {
      return stack[top--];
    }
  }

  static int peek() {
    if(Stack.isEmpty()) {
      return 0;
    }
    else {
      return stack[top];
    }
  }

  static void traverse() {
    if(Stack.isEmpty()) {
      System.out.println("Stack is empty");
    }
    else {
      while(!Stack.isEmpty()) {
        System.out.print(stack[top--] + " ");
      }
      System.out.println("\n");
    }
  }

}
