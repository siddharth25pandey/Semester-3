import java.util.*;

class operation {

    public int add(int a, int b) {
        return a + b;
    }

    public int sub(int a, int b) {
        return a - b;
    }

    public int mul(int a, int b) {
        return a * b;
    }

    public int div(int a, int b) {
        return a / b;
    }

    public int mod(int a, int b) {
        return a % b;
    }

}

public class arithmetic {

    public static void main(String argv[]) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("The Simple Arithematic Operation Program");
            System.out.println("-----------------------------------------\n");

            System.out.println(
                    "1==> Addition, 2==> Subtraction ,3 ==> Multiplication ,4==>Division, 5==> Modulas, 6==> Exit\n");
            System.out.println("Enter your choice number");
            int ch = sc.nextInt();
            System.out.println("Enter the first number");
            int a = sc.nextInt();
            System.out.println("Enter the second number");
            int b = sc.nextInt();

            operation ob1 = new operation();
            switch (ch) {
                case 1:
                    System.out.println("The sum of the Two numbers id " + ob1.add(a, b));
                    break;
                case 2:
                    System.out.println("The Subtraction of the Two numbers is " + ob1.sub(a, b));
                    break;
                case 3:
                    System.out.println("The Multiplication of the Two numbers is " + ob1.mul(a, b));
                    break;
                case 4:
                    System.out.println("The Divison of the Two numbers is " + ob1.div(a, b));
                    break;

                case 5:
                    System.out.println("The Modulas of the Two numbers is " + ob1.mod(a, b));
                    break;

                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Enter a valid choice number");
            }
        }

    }

}