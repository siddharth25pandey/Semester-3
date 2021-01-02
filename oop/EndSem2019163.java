import java.io.*;
import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/* Siddharth Pandey
S20190010163
OOP End Sem Lab Exam
Group-4
*/

class Q1 {
    static boolean prime(int n) {
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to n-1
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;

        return true;
    }

    void calculate_matrix() {
        Scanner sc = new Scanner(System.in);
        int l = 1;
        int row, col;
        System.out.println("Enter the number of rows");

        row = sc.nextInt();
        System.out.println("Enter the number of Columns");
        col = sc.nextInt();
        System.out.println("Enter the Elements of the 2D Matrix");
        int[][] a = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int x = sc.nextInt();
                a[i][j] = x;
            }
        }
        System.out
                .println("The List of the Matrics which have priciple diagonal(Prime) sum equal to Anti Diagonal Sum");

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (prime(a[i][j]) == true && prime(a[i + 1][j + 1]) == true) {
                    if (a[i][j] + a[i + 1][j + 1] == a[i][j + 1] + a[i + 1][j]) {
                        System.out.print("\n");
                        System.out.println("The " + l + " 2D Matrix");
                        System.out.println(a[i][j] + " " + a[i][j + 1]);
                        System.out.println(a[i + 1][j] + " " + a[i + 1][j + 1]);
                        System.out.print("\n");
                        l++;
                    }
                }
            }
        }

        // Corner Cases
        for (int j = 0; j < col - 1; j++) {
            if (prime(a[0][j]) == true && prime(a[1][j + 1]) == true) {
                if (a[0][j] + a[1][j + 1] == a[0][j + 1] + a[1][j]) {
                    System.out.print("\n");
                    System.out.println("The " + l + " 2D Matrix");
                    System.out.println(a[0][j] + " " + a[0][j + 1]);
                    System.out.println(a[1][j] + " " + a[1][j + 1]);
                    System.out.print("\n");
                    l++;
                }
            }
        }
        // Corner Cases
        for (int j = 0; j < col - 1; j++) {
            if (prime(a[row - 2][j]) == true && prime(a[row - 1][j + 1]) == true) {
                if (a[row - 2][j] + a[row - 1][j + 1] == a[row - 2][j + 1] + a[row - 1][j]) {
                    System.out.print("\n");
                    System.out.println("The " + l + " 2D Matrix");
                    System.out.println(a[row - 1][j] + " " + a[row - 1][j + 1]);
                    System.out.println(a[row - 2][j] + " " + a[row - 2][j + 1]);
                    System.out.print("\n");
                    l++;
                }
            }
        }
        sc.close();

    }

}

class City {
    int placeID;
    int popular;
    float distance;
    int[] travel = new int[50];
    int[] time = new int[50];

    void insert() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the Place Id");
        placeID = sc.nextInt();
        System.out.println("Enter the Popular");
        popular = sc.nextInt();
        System.out.println("Enter the Distance");
        distance = sc.nextFloat();
        sc.close();

    }

}

class TourMaps extends City {
    City[] array = new City[1000];
}

public class EndSem2019163 {

    public static void main(String args[]) throws IOException {
        System.out.println(" Siddharth Pandey ");
        System.out.println(" S20190010163  ");
        System.out.println(" Group-4\n ");

        System.out.println(" Question-1 ");
        System.out.println(" ----------- ");
        Q1 b = new Q1();
        b.calculate_matrix();
        System.out.println(" Question-2 ");
        System.out.println(" ----------- ");
        City c = new City();
        c.insert();

    }
}