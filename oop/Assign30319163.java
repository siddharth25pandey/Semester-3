import java.util.Scanner;
import java.util.Random;

class Matrix {
    int[][] mat = new int[5][20];

    int sort_row(int m[][]) {

        for (int i = 0; i < m.length; i++) {

            // loop for column of matrix
            for (int j = 0; j < m[i].length; j++) {

                // loop for comparison and swapping
                for (int k = 0; k < m[i].length - j - 1; k++) {
                    if (m[i][k] > m[i][k + 1]) {

                        // swapping of elements
                        int t = m[i][k];
                        m[i][k] = m[i][k + 1];
                        m[i][k + 1] = t;
                    }
                }
            }

        }
        return 0;
    }

    void unique() {

        int n = 5;
        int m = 20;
        int[][] mat = new int[n][m];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 20; j++) {
                Random r = new Random();
                int a = 20;
                int b = 200;
                int c = r.nextInt((b - a)) + a;
                mat[i][j] = c;
            }
        }
        int maximum = 0, flag = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)

                if (maximum < mat[i][j])
                    maximum = mat[i][j];

        int b[] = new int[maximum + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[mat[i][j]]++;

        for (int i = 1; i <= maximum; i++)
            if (b[i] == 1)
                System.out.print(i + " ");
        flag = 1;

        if (flag == 0) {
            System.out.println("No unique element " + "in the matrix");
        }
        System.out.println("\n");
    }

    int print() {

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 20; j++) {
                Random r = new Random();
                int a = 20;
                int b = 200;
                int c = r.nextInt((b - a)) + a;
                mat[i][j] = c;
            }
        }
        sort_row(mat);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 20; j++) {
                if (i % 2 == 0) {
                    System.out.print(mat[i][j] + " ");
                } else {
                    System.out.print(mat[i][19 - j] + " ");
                }
            }
            System.out.println("\n");
        }
        return 0;

    }

}

class A extends Thread {
    int[] b;

    public A(int[] a) {
        this.b = a;
    }

    public void run() {
        for (int i = 0; i < 1999; i++) {
            int min = i;
            for (int j = i + 1; j < 2000; j++) {
                if (b[j] < b[min])
                    min = j;
            }
            int t = b[min];
            b[min] = b[i];
            b[i] = t;
        }
    }
}

class B extends Thread {
    int[] arr;

    public B(int[] a) {
        this.arr = a;
    }

    public void run() {
        for (int i = 2000; i < 3999; i++) {
            int min = i;
            for (int j = i + 1; j < 4000; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

class C extends Thread {
    int[] arr;

    public C(int[] a) {
        this.arr = a;
    }

    public void run() {
        for (int i = 4000; i < 5999; i++) {
            int min = i;
            for (int j = i + 1; j < 6000; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

class D extends Thread {
    int[] arr;

    public D(int[] a) {
        this.arr = a;
    }

    public void run() {
        for (int i = 6000; i < 7999; i++) {
            int min = i;
            for (int j = i + 1; j < 8000; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

class E extends Thread {
    int[] arr;

    public E(int[] a) {
        this.arr = a;
    }

    public void run() {
        for (int i = 8000; i < 9999; i++) {
            int min = i;
            for (int j = i + 1; j < 10000; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

public class Assign30319163 {
    public static void main(String[] args) {
        // System.out.println("Hi");
        System.out.println("Question 1:");
        Matrix m = new Matrix();
        System.out.println(
                "The Matrix ranging from 20-200 and Sorted in Ascending order for Rows 1,3,5 and Descending Order in Row 2,4\n");
        m.print();
        System.out.println("The Unique Elements that are present in it are: \n");
        m.unique();
        System.out.println("All are frequency of 1");

        System.out.println("Question 2:");
        System.out.println("Merged All sorted subarray");
        Random rand = new Random(10047);
        int[] arr = new int[10000];
        for (int i = 0; i < 10000; i++) {
            arr[i] = rand.nextInt(500);
        }
        A t1 = new A(arr);
        B t2 = new B(arr);
        C t3 = new C(arr);
        D t4 = new D(arr);
        E t5 = new E(arr);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();

        int[] arr1 = new int[2000];
        int[] arr2 = new int[2000];
        int[] arr3 = new int[2000];
        int[] arr4 = new int[2000];
        int[] arr5 = new int[2000];

        for (int i = 0; i < 2000; i++) {
            arr1[i] = arr[i];
            arr2[i] = arr[2000 + i];
            arr3[i] = arr[4000 + i];
            arr4[i] = arr[6000 + i];
            arr5[i] = arr[8000 + i];
        }

        int[] arr6 = new int[4000];
        int[] arr7 = new int[4000];
        int[] arr8 = new int[8000];

        int i, j, k;

        i = 0;
        j = 0;
        k = 0;
        while (i < 2000 && j < 2000) {
            if (arr1[i] <= arr2[j]) {
                arr6[k] = arr1[i];
                i++;
            } else {
                arr6[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < 2000) {
            arr6[k] = arr1[i];
            i++;
            k++;
        }
        while (j < 2000) {
            arr6[k] = arr2[j];
            j++;
            k++;
        }

        i = 0;
        j = 0;
        k = 0;
        while (i < 2000 && j < 2000) {
            if (arr3[i] <= arr4[j]) {
                arr7[k] = arr3[i];
                i++;
            } else {
                arr7[k] = arr4[j];
                j++;
            }
            k++;
        }
        while (i < 2000) {
            arr7[k] = arr3[i];
            i++;
            k++;
        }
        while (j < 2000) {
            arr7[k] = arr4[j];
            j++;
            k++;
        }

        i = 0;
        j = 0;
        k = 0;
        while (i < 4000 && j < 4000) {
            if (arr6[i] <= arr7[j]) {
                arr8[k] = arr6[i];
                i++;
            } else {
                arr8[k] = arr7[j];
                j++;
            }
            k++;
        }
        while (i < 4000) {
            arr8[k] = arr6[i];
            i++;
            k++;
        }
        while (j < 4000) {
            arr8[k] = arr7[j];
            j++;
            k++;
        }

        i = 0;
        j = 0;
        k = 0;
        while (i < 8000 && j < 2000) {
            if (arr8[i] <= arr5[j]) {
                arr[k] = arr8[i];
                i++;
            } else {
                arr[k] = arr5[j];
                j++;
            }
            k++;
        }
        while (i < 8000) {
            arr[k] = arr8[i];
            i++;
            k++;
        }
        while (j < 2000) {
            arr[k] = arr5[j];
            j++;
            k++;
        }

        for (i = 0; i < 10000; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }
}