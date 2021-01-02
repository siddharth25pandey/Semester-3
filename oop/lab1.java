import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Scanner;

public class lab1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        List<Employee> ArrList = new ArrayList<Employee>();

        System.out.println("Enter Employee number : ");
        int n = input.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter ID number : ");
            int id = input.nextInt();

            System.out.println("Enter Name  : ");
            String d = input.next();

            System.out.println("Enter Numbers of Projects : ");
            int n1 = input.nextInt();

            ArrayList<String> p_name = new ArrayList<>();
            ArrayList<Integer> p_point = new ArrayList<>();
            for (int j = 0; j < n1; j++) {
                System.out.println("Enter the Project Name: ");
                String name = input.next();
                p_name.add(name);
                System.out.println("Enter the Project Point: ");
                int data = input.nextInt();
                p_point.add(data);

            }

            ArrList.add(new Employee(id, d, p_name, p_point));
        }

        System.out.println("ID\t\tName\t\tProject_name\t\t\t\t\tProject_point\n\n");
        for (Employee i : ArrList) {
            System.out
                    .println(i.ID + "\t\t" + i.name + "\t\t" + i.project_name + "\t\t\t\t\t" + i.project_point + "\n");
        }

        for (Employee i : ArrList) {
            float count = 0;
            for (Integer j : i.project_point) {
                count += j;
            }
            System.out.println("Avarege Project Point Employee " + i.ID + " : " + count / i.project_point.size());

        }

    }

}

class EmployeeRecord {
    ArrayList<String> project_name = new ArrayList<>();
    ArrayList<Integer> project_point = new ArrayList<>();

}

class Employee extends EmployeeRecord {
    public int ID;
    public String name;

    Employee(int ID, String name, ArrayList<String> l1, ArrayList<Integer> l2) {
        this.ID = ID;
        this.name = name;
        for (String i : l1) {
            this.project_name.add(i);
        }
        for (Integer x : l2) {
            this.project_point.add(x);
        }

    }

}