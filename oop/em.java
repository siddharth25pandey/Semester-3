import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

class employee_record {
    ArrayList<String> p_name = new ArrayList<>();
    ArrayList<Integer> p_point = new ArrayList<>();
}

class employee extends employee_record {
    int id;
    String e_name;

    employee(int id, String name, ArrayList<String> p_name, ArrayList<Integer> p_point) {
        this.id = id;
        this.e_name = name;
        for (String i : p_name) {
            this.p_name.add(i);
        }
        for (Integer j : p_point) {
            this.p_point.add(j);
        }
    }

}

public class em {
    public static void main(String argv[]) {

        Scanner sc = new Scanner(System.in);
        List<employee> a = new ArrayList<employee>();
        System.out.println("Employee Record System");
        System.out.println("-----------------------");
        System.out.println("Enter the number of Employee Records you want to insert");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter Employment ID");
            int id = sc.nextInt();
            System.out.println("Enter Employer Name");
            String name = sc.next();
            System.out.println("Enter total number of Projects done by this Employee");
            int pc = sc.nextInt();

            ArrayList<String> pn = new ArrayList<>();
            ArrayList<Integer> pp = new ArrayList<>();

            for (int j = 0; j < pc; j++) {
                System.out.println("Enter the Project Name");
                String p = sc.next();
                pn.add(p);
                System.out.println("Enter the Project Point");
                int x = sc.nextInt();
                pp.add(x);

            }
            a.add(new employee(id, name, pn, pp));

        }
        for (employee k : a) {
            System.out.println("Employment ID: " + k.id + ", " + "Employer Name: " + k.e_name + " Project Name: "
                    + k.p_name + ", " + "Project point: " + k.p_point + "\n");
        }
        for (employee i : a) {
            float avg = 0;
            for (Integer j : i.p_point) {
                avg += j;
            }
            System.out.println("The Average Project Point of Employee Id: " + i.id + "," + " Employer Name: " + i.e_name
                    + " is" + " " + avg / i.p_point.size());
        }

    }
}