import java.util.Random;
import java.util.Scanner;

class SortNumbers {

    boolean prime(int n) {
        int i, m = 0, c = 0;

        m = n / 2;
        if (n == 0 || n == 1) {
            return false;
        } else {
            for (i = 2; i <= m; i++) {
                if (n % i == 0) {
                    c = 1;
                    return false;

                }
            }
            if (c == 0) {
                return true;
            }
        }
        return true;

    }

    void arrange_prime() {

        int[][] a = new int[2][20];
        int[][] b = new int[2][20];
        a[0][0] = 17;
        a[0][1] = 7;
        a[0][2] = 11;
        a[0][3] = 41;
        a[0][4] = 45;
        a[0][5] = 131;
        a[0][6] = 14;
        a[0][7] = 101;
        a[0][8] = 198;
        a[0][9] = 139;
        a[1][0] = 89;
        a[1][1] = 15;
        a[1][2] = 2;
        a[1][3] = 59;
        a[1][4] = 40;
        a[1][5] = 26;
        a[1][6] = 115;
        a[1][7] = 60;
        a[1][8] = 151;
        a[1][9] = 18;
        int p = 0;
        int q = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 10; j++) {
                if (prime(a[i][j]) == true) {
                    b[1][p] = a[i][j];
                    p++;
                } else {
                    b[0][q] = a[i][j];
                    q++;
                }
            }

        }
        int x = 0;
        if (p >= q) {
            x = p;
        } else {
            x = q;
        }

        for (int i = 0; i < 2; i++) {
            if (i == 0) {

                System.out.println("First Row is Non-Prime Numbers");
            } else {
                System.out.println("Second Row is Prime Numbers");
            }
            for (int j = 0; j < x; j++) {
                System.out.print(b[i][j] + " ");
            }

            System.out.println();
        }

    }

    void swap_matrix() {
        int[][] a = new int[2][20];
        int[][] b = new int[2][20];
        a[0][0] = 17;
        a[0][1] = 7;
        a[0][2] = 11;
        a[0][3] = 41;
        a[0][4] = 45;
        a[0][5] = 131;
        a[0][6] = 14;
        a[0][7] = 101;
        a[0][8] = 198;
        a[0][9] = 139;
        a[1][0] = 89;
        a[1][1] = 15;
        a[1][2] = 2;
        a[1][3] = 59;
        a[1][4] = 40;
        a[1][5] = 26;
        a[1][6] = 115;
        a[1][7] = 60;
        a[1][8] = 151;
        a[1][9] = 18;
        int p = 0;
        int q = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 10; j++) {
                if (prime(a[i][j]) == true) {
                    b[1][p] = a[i][j];
                    p++;
                } else {
                    b[0][q] = a[i][j];
                    q++;
                }
            }

        }
        int x = 0;
        if (p >= q) {
            x = p;
        } else {
            x = q;
        }

        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {
                if (b[1][i] < b[1][j]) {
                    int temp = b[1][i];
                    b[1][i] = b[1][j];
                    b[1][j] = temp;
                }
            }
        }
        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {
                if (b[0][i] > b[0][j]) {
                    int temp = b[0][i];
                    b[0][i] = b[0][j];
                    b[0][j] = temp;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {

                System.out.println("First Row  Sorted Non-Prime Numbers in Ascending Order");
            } else {
                System.out.println("Second Row  Sorted Prime Numbers in Descending Order");
            }
            for (int j = 0; j < x; j++) {
                System.out.print(b[i][j] + " ");
            }
            System.out.println();
        }
    }
}

class Point {
    float x, y;

    Point(float x, float y) {
        this.x = x;
        this.y = y;
    }

}

class Line {
    Point a, b;
    float lwidth, lcolor;

    Line(float a, float b, float c, float d, float e, float f) {
        this.a = new Point(a, b);
        this.b = new Point(c, d);
        this.lwidth = e;
        this.lcolor = f;
    }

    // float m = (b.y - a.y) / (b.x - a.x);

    float equation() {
        System.out.println("The Points are\n");
        System.out.println(a.x + " " + a.y + " " + b.x + " " + b.y);
        return (float) Math.sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
    }

}

class Rectangle {
    Line a, b, c, d;
    float l, w;

    void calculate_perimeter() {
        float c = 2 * (l + w);
        System.out.println(c + "\n");
    }

    void calculate_area() {
        float c = l * w;
        System.out.println(c + "\n");
    }

}

class Square extends Rectangle {
    float len;
}

class PascalTriangle {
    void printPascal(int n) {
        for (int line = 1; line <= n; line++) {
            int c = 1;
            for (int i = 1; i <= line; i++) {
                System.out.print(c + " ");
                c = c * (line - i) / i;
            }
            System.out.println("");
        }
    }

    int Fibonacci(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);

    }
}

class Assign0519163 {
    public static void print_value(int[] a, int n) {

        if (n != -1) {

            print_value(a, n - 1);
            System.out.println(a[n]);
        }

    }

    public static int average(int[] a, int n) {
        int avg = 0;
        for (int i = 0; i < n; i++) {
            avg += a[i];
        }
        return avg;

    }

    public static void cons_sum(int[] a, int n) {
        int avg = average(a, n);
        if (n > 1) {
            if (a[n - 1] + a[n - 2] < avg) {
                System.out.println("(" + a[n - 1] + "," + a[n - 2] + ")");
            }
            cons_sum(a, n - 1);
        }

    }

    public static void main(String args[]) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("\nQuestion-1\n");
        System.out.println("Enter the size of array to generate to numbers between 40 & 50");
        n = sc.nextInt();
        int[] a;
        a = new int[n];
        Random r = new Random();
        for (int i = 0; i < n; i++) {
            a[i] = r.nextInt(50 - 40) + 40;
        }

        System.out.println("The array values  after doing Recussive Approach is");
        print_value(a, n - 1);
        System.out.println("The Consecutive array elements having sum less than the average values of the array are:");
        cons_sum(a, n);
        int row;
        System.out.println("\nQuestion-2\n");
        System.out.println("Enter the number of rows to print the Pascal Traingle");
        row = sc.nextInt();
        PascalTriangle pas = new PascalTriangle();
        System.out.println("The Pascal Triangle of given rows\n");
        pas.printPascal(row);
        int ele;

        System.out.println("Enter the number of elements to print the Fibonacii Series");
        ele = sc.nextInt();
        System.out.println("The Fibonacii Series is");
        for (int i = 0; i < ele; i++) {
            System.out.println(pas.Fibonacci(i));
        }
        System.out.println("\nQuestion-4\n");
        System.out.println("The Sort Array of 2D Array is \n");
        SortNumbers obj = new SortNumbers();
        obj.arrange_prime();
        obj.swap_matrix();
        System.out.println("\nQuestion-3\n");
        System.out.println("Enter the First Co-ordinate Values");
        float x1, y1, x2, y2, l, w;
        x1 = sc.nextInt();
        y1 = sc.nextInt();
        System.out.println("Enter the Second Co-ordinate Values");
        x2 = sc.nextInt();
        y2 = sc.nextInt();
        System.out.println("Enter the LineWidth and Line Color");
        w = sc.nextInt();
        l = sc.nextInt();
        Point p = new Point(x1, y1);
        Line line = new Line(x1, y1, x2, y2, w, l);
        float eq = line.equation();
        System.out.println("The Length of line is " + eq);
        Rectangle z = new Rectangle();
        Square s = new Square();
        System.out.println("The area of the Rectangle is\n");
        z.calculate_area();
        System.out.println("The Perimeter of the Rectangle is\n");
        z.calculate_perimeter();
        System.out.println("The area of the Square is\n");
        s.calculate_area();
        System.out.println("The Perimeter of the Square is\n");
        s.calculate_perimeter();

    }
}