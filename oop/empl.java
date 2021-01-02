
//import java.until.*;
import java.util.Scanner;

class employee {
    int id;
    String name;
    // String project_name;
    // int project_point;

    employee(int eid, String ename) {
        id = eid;
        name = ename;
        // project_name = eproject_name;
        // project_point = eproject_point;
    }

    public void show_data() {
        System.out.println("Employment ID: " + id + ", " + "Employer Name: " + name + "\n");
    }

    /*
     * public int show_point() { return project_point; }
     */
}

class employee_records {
    String project_name;
    int project_point[];

    employee_records(String eproject_name, int eproject_point) {
        project_name = eproject_name;
        project_point = eproject_point;
    }

    public void show_data() {
        System.out.println("Project Name: " + project_name + ", " + "Project point: " + project_point + "\n");
    }

    public int show_point() {
        return project_point;
    }

}

public class empl {
    public static void main(String argv[]) {
        // employee ob1 = new employee();
        System.out.println("Employee Record System");
        System.out.println("-----------------------");
        System.out.println("Enter the number of Employee Records you want to insert");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        employee[] obj = new employee[n];
        employee_records[] objr = new employee_records[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the Id of the Employee");
            int id = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter the name of the Employee");
            String ename = sc.nextLine();
            System.out.println("Enter the Project name of the Employee");
            String p_name = sc.nextLine();
            System.out.println("Enter the Project point of the Employee");
            int p_point = sc.nextInt();

            obj[i] = new employee(id, ename);
            objr[i] = new employee_records(p_name, p_point);
        }
        for (int i = 0; i < n; i++) {
            obj[i].show_data();
            objr[i].show_data();
            System.out.println("---------------------------------------------------------------");
        }
        float avg = 0;
        for (int i = 0; i < n; i++) {
            avg = avg + objr[i].show_point();
        }
        avg = avg / n;
        System.out.println("The Average of all Project Points is " + avg);
        sc.close();

        // System.out.println("hello");
    }
}