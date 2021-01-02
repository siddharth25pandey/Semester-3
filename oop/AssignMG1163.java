import java.util.Scanner;
import java.util.ArrayList;

class student {
    String fname;
    String lname;
    int amarks;
    char section;

    student(String fname, String lname, int amarks) {
        this.fname = fname;
        this.lname = lname;
        this.amarks = amarks;
    }
    void print()
    {
        System.out.println("Student First Name: " + fname + ", " + "Student Last Name: " + lname+", "
                + " Student's Marks: " + amarks + ", "+"Student's Section "+section+"\n");
        
    }
  
  

}

public class AssignMG1163 {
    public static void main(String argv[]) {
        Scanner sc = new Scanner(System.in);       
        System.out.println("Student Record System");
        System.out.println("-----------------------");
        System.out.println("Enter the number of Student Records you want to insert");
        int n = sc.nextInt();
        student []a=new student[n];
       
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the " + (i + 1) + " Student's First Name:");
            String fname = sc.next();
            System.out.println("Enter the " + (i + 1) + " Student's Last Name:");
            String lname = sc.next();
            System.out.println("Enter the " + (i + 1) + " Student's Marks between 1-100");
            int marks = sc.nextInt();
            
            a[i]=new student(fname, lname, marks);
        
            
        }
       student temp=new student("Siddharth", "Pandey", 100);
        for(int k=0;k<n;k++)
        {    //temp=a[k];
            for(int j=1;j<n-k;j++)
            {
                if(a[j-1].amarks<a[j].amarks)
                {
                    temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0) {
                a[i].section = 'A';
            } else if ((i + 1) % 3 == 1) {
                a[i].section = 'B';
            } else {
                a[i].section = 'C';

            }

        }
        
        System.out.println("Display details of Each Student Record\n");
        System.out.println("----------------------------------------");

        for(int p=0;p<n;p++)
        {
            a[p].print();
            System.out.println("\n");
        }

    }
}