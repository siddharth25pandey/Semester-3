import java.util.Scanner;

class Student {
    private String sname;

    public Student(String name) {
        sname = name;
    }

    public String getName() {
        return sname;
    }
}

class OOP2020_Student {
    String name;
    int num_exams;
    int[] exams;

    public OOP2020_Student(String name, int num_exams) {
        this.name = name;
        this.num_exams = num_exams;
        this.exams = new int[num_exams];
    }

    public boolean addGrade(int ind_exam, int grade) {
        if (ind_exam <= num_exams - 1) {
            this.exams[ind_exam] = grade;
            return true;
        } else {
            return false;
        }

    }

    String getName() {
        return this.name;
    }

    public int getGrade(int ind_exam) {

        if (ind_exam <= num_exams - 1) {
            return exams[ind_exam];

        } else {
            return -1;
        }
    }

}

class OOP2020_Course {
    int capacity = 0;
    int size = 0;
    OOP2020_Student[] list = new OOP2020_Student[1000];

    OOP2020_Course(int cap) {
        this.capacity = cap;

    }

    public boolean addStudent(String name, int num_exams) {
        OOP2020_Student ob1 = new OOP2020_Student(name, num_exams);
        if (size < capacity) {
            list[size] = ob1;
            size++;
            return true;
        } else {
            return false;
        }

    }

    public OOP2020_Student findStudent(String name) {
        for (int i = 0; i < capacity; i++) {

            String ch = list[i].getName();
            if (ch == name) {
                // System.out.println("i= "+i);
                return list[i];
            }
        }
        return null;

    }

    public double findAverage(int ind_exam) {
        double avg = 0;
        for (int i = 0; i < size; i++) {
            avg += list[i].getGrade(ind_exam);
        }
        if (size != 0) {
            return avg / size;
        } else {
            System.out.println("Sorry, Cannot find the Average");
        }
        return 0;

    }

}

public class stu {

    public static void main(String args[]) {
        // System.out.println("hello\n");
        OOP2020_Course c1 = new OOP2020_Course(20);
        c1.addStudent("Nikhil Sharma", 3);
        c1.addStudent("Pratyush Lahiri", 3);
        OOP2020_Student s1 = c1.findStudent("Nikhil Sharma");
        OOP2020_Student s2 = c1.findStudent("Pratyush Lahiri");
        s1.addGrade(0, 80);
        s2.addGrade(0, 70);
        double average = c1.findAverage(0);
        System.out.println("The First Student Name is " + s1.getName());
        System.out.println("The First Student Grade is " + s1.getGrade(0));
        System.out.println("The Second Student Name is " + s2.getName());
        System.out.println("The Second Student Grade is " + s2.getGrade(0));
        System.out.println("Average Marks on Exam One is : " + average);

    }
}