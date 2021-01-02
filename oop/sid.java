import java.util.Scanner;
import java.util.Random;

class Matrix {
    int[][] mat = new int[5][20];

    int sortRowWise(int m[][]) {
        // loop for rows of matrix
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
            /*
             * for (int i = 0; i < m.length; i++) { for (int j = 0; j < m[i].length; j++)
             * System.out.print(m[i][j] + " "); System.out.println(); }
             */

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

                // Find maximum element
                // in a matrix
                if (maximum < mat[i][j])
                    maximum = mat[i][j];

        // Take 1-D array of
        // (maximum + 1) size
        int b[] = new int[maximum + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[mat[i][j]]++;

        // print unique element
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
        sortRowWise(mat);

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

public class sid {
    public static void main(String[] args) {
        // System.out.println("Hi");
        Matrix m = new Matrix();
        System.out.println(
                "The Matrix ranging from 20-200 and Sorted in Ascending order for Rows 1,3,5 and Descending Order in Row 2,4\n");
        m.print();
        System.out.println("The Unique Elements that are present in it are: \n");
        m.unique();
        System.out.println("All are frequency of 1");
    }
}