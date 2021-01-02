import java.util.Scanner;

import java.io.*;

import java.util.Random;

class Circle {
    float radius;

    static class center {
        int x, y;

        center(int x, int y) {
            this.x = x;
            this.y = y;
        }

        void getPoint() {
            System.out.println("The Center of the new Circle is (" + x + "," + y + ")");

        }
    }
}

class Factors {
    int num;

    void computePrimeFactors(int k)

    {
        for (int i = 2; i < k; i++) {
            while (k % i == 0) {

                num = i;
                k = k / i;
            }
        }
        if (k > 2) {

            num = k;

        }
    }

    void printFactors(int i) {
        for (int k = 2; k < i; k++) {
            while (i % k == 0) {
                System.out.print(k + " ");

                i = i / k;
            }
        }
        if (i > 2) {
            System.out.println(i);

        }
    }

    int evenFactors(int num) {
        int sum = 0;
        for (int i = 2; i <= num; i++) {
            if (num % i == 0) {
                if (i % 2 == 0) {
                    sum += i;
                }
            }
        }

        return sum;

    }

}

interface siddharth {
    public double interestRates();

    public double getMaturityAmount();
}

class bank implements siddharth {
    double interest;
    float pri;
    float time;
    float rate;
    int check;

    bank(float pri, float time, float rate, int check) {
        this.pri = pri;
        this.time = time;
        this.check = check;
        this.rate = rate;
    }

    public double interestRates() {

        if (check == 0) {
            interest = (pri * rate * (time / 12)) / 100;

        } else if (check == 1) {

            interest = pri * (Math.pow((1 + rate / 100), (time / 12)));
        }
        return interest;
    }

    public double getMaturityAmount() {

        return interest + pri;

    }
}

class Computer {
    static class CPU {
        public void display() {
            System.out.println("Hello This is CPU, Example of Static Inner class");

        }
    }

    static class RAM {
        public void display() {
            System.out.println("Hello This is RAM");
        }
    }

    static class Storage {
        public void display() {
            System.out.println("Hello This is Storage");
        }
    }

    static class Monitor {
        int unit = 10;

        public void display() {
            System.out.println("Hello This is Monitor, Output device !!");
            System.out.println("Member Inner class");
            System.out.println("The number of units of Monitor is " + unit);
        }
    }

    static class Keyboard {
        public void display() {
            System.out.println("Hello This is Keyboard and Exampple of Local Inner Class , Input device !!");
        }
    }

    static class Mouse {
        Computer c = new Computer();

        public void display() {
            System.out.println("Hello This is Mouse  and Example of Anonymous inner Class, Input device !!");
        }
    }

}

public class Assign30219163 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        // System.out.println("Hello");
        System.out.println("\nWelcome to the Lab-3 Assignment of S20190010163");
        System.out.println("--------------------------------------------------\n\n");
        Circle c = new Circle();
        System.out.println("The Random Values of Center of the Circle between 10-70 are ");
        for (int i = 1; i <= 10; i++) {
            Random r = new Random();
            int x = r.nextInt(70) + 10;
            int y = r.nextInt(70) + 10;
            Circle.center c1 = new Circle.center(x, y);

            c1.getPoint();
        }
        Factors f = new Factors();
        System.out.println("\nEnter the Number for calculating the Prime factor");
        int n = sc.nextInt();
        System.out.println("The Prime factor of the given number is ");
        f.printFactors(n);
        int x = f.evenFactors(n);
        f.computePrimeFactors(n);
        System.out.println("The Sum of the Even factors of the number is " + x);
        System.out.println("\n");
        int a[] = new int[20];
        for (int i = 0; i < 20; i++) {
            Random r = new Random();
            int z = (r.nextInt(150) + 20) * 2;
            a[i] = z;
        }
        System.out.println("The Random Even values of the elements in the array is between the range of 20-150 is ");
        for (int i = 0; i < 20; i++) {
            System.out.print(a[i] + "  ");
        }

        System.out.println("\n");
        System.out.println("Enter 0 for Simple Interest and 1 for Compund Interest");
        int ch = sc.nextInt();
        System.out.println("Enter the Principle Amount");
        float p = sc.nextFloat();
        System.out.println("Enter the Rate ");
        float r = sc.nextFloat();
        System.out.println("Enter the Time in month");
        float t = sc.nextFloat();

        bank b = new bank(p, t, r, ch);
        double inte = b.interestRates();
        if (ch == 0) {
            System.out.println("The interest rate for Simple Interest is " + inte);
            double amt = b.getMaturityAmount();
            System.out.println("The mature amount for Simple Interest is " + amt);

        } else if (ch == 1) {
            System.out.println("The interest rate for Compound Interest is " + inte);
            double amt = b.getMaturityAmount();
            System.out.println("The mature amount for Compound Interest is " + amt);
        } else {
            System.out.println("Wrong Input choice");
        }
        System.out.println("\n");
        Computer comp = new Computer();
        Computer.CPU acomp = new Computer.CPU();
        acomp.display();
        Computer.Storage ob = new Computer.Storage();
        ob.display();
        Computer.Mouse ob1 = new Computer.Mouse();
        ob1.display();
        Computer.Keyboard ob2 = new Computer.Keyboard();
        ob2.display();
        Computer.Monitor ob3 = new Computer.Monitor();
        ob3.display();
        Computer.RAM ob4 = new Computer.RAM();
        ob4.display();
    }

}