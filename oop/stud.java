import java.util.Scanner;
import java.util.ArrayList;

public class stud {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        // String fname;
        // String lname;
        // int marks;

        int n;
        System.out.println("Student Record System");
        System.out.println("-----------------------");
        System.out.println("Enter the number of Student Records you want to insert");
        n = sc.nextInt();
        student[] a = new student[n];
        student temp = new student("name", "name", 50);
        for (int i = 0; i < n; i++) {
            char c;
            System.out.println("Enter the" + (i + 1) + "Student's First Name:");
            String fname = sc.next();
            System.out.println("Enter the " + (i + 1) + "Student's Last Name:");
            String lname = sc.next();
            System.out.println("Enter the" + (i + 1) + "Student's Marks");
            int marks = sc.nextInt();
            a[i] = new student(fname, lname, marks);

        }
        for (int k = 0; k < n; k++) {
            temp = a[k];
            for (int j = 1; j < (n - k); j++) {
                if (a[j - 1].amarks < a[j].amarks) {
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0) {
                a[i].c = 'C';
            } else if ((i + 1) % 3 == 1) {
                a[i].c = 'A';
            } else {
                a[i].c = 'B';

            }

        }
        System.out.println("Display details After Sorting");
        for (int p = 0; p < n; p++) {
            a[p].print();
            System.out.println("\n");
        }
    }
}