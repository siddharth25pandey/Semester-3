class student {
    int roll;
    String name;

    student(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }

    public void print() {
        System.out.println("roll " + roll);
        System.out.println("name " + name);
    }

}

class btech extends student {
    float cgpa;

    btech(int roll, String name, float cgpa) {
        super(roll, name);
        this.cgpa = cgpa;

    }

    public void print() {
        super.print();
        System.out.println("CGPA " + cgpa);
    }

}

public class st {
    /*
     * public static student create(int roll, String name) { student s = new
     * student(); s.roll = roll; s.name = name; return s; }
     */

    public static void main(String args[])

    {
        // System.out.println('Hi');
        student s1;
        s1 = new student(25, "Siddharth");
        // s1.print();
        btech b1;
        b1 = new btech(10, "Jack", 10);
        b1.print();
        // s1 = new student();
        // s1.roll = 10;
        // s1.name = "Siddharth";

    }
}