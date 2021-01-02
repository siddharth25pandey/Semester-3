import java.util.*;

public class hello {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name:");
        String a = sc.nextLine();
        System.out.println("The name by taking input from the user");
        System.out.println(a + " Helloworld");
        System.out.println("The name by taking input from the command line argument");
        System.out.println(args[0] + " Helloworld");
        sc.close();

    }
}