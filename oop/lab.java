import java.util.*;

public class lab {

    public static void main(String[] args) {
        // Question 1
        System.out
                .println("--------------------------------------- Question 1 ---------------------------------------");
        Matrix Q1 = new Matrix();
        Q1.Question1_main();
        System.out
                .println("--------------------------------------- Question 2 ---------------------------------------");
        Question2 ques2 = new Question2();
        ques2.populate_matrix();
        ques2.print_matrix();
        ques2.split_arr();
        ques2.algo();
        // Question 4
        System.out.println();
        System.out
                .println("--------------------------------------- Question 4 ---------------------------------------");
        int dest_x, dest_y, N, M;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of matrix : ");
        N = input.nextInt();
        System.out.print("Enter the co-ordinates where you want to reach (with space) : ");
        M = input.nextInt();
        dest_x = input.nextInt();
        dest_y = input.nextInt();
        System.out.println(Grid.paths(0, 0, N, M, dest_x, dest_y));
        Grid.PrintPaths(N, M, dest_x, dest_y);
        input.close();

        System.out.println();

    }
}

class Matrix {

    ArrayList<ArrayList<Integer>> arrayRandom = new ArrayList<ArrayList<Integer>>();

    int[][] a = new int[5][20];

    public void populate_matrix() {
        Random random = new Random();

        System.out.println();

        for (int i = 0; i < 5; i++) {
            arrayRandom.add(new ArrayList<Integer>());
            for (int j = 0; j < 20; j++) {
                arrayRandom.get(i).add(j, (20 + random.nextInt(181)));
            }
        }
    }

    public void print_matrix() {
        for (int i = 0; i < 5; i++) {
            Iterator<Integer> it = arrayRandom.get(i).iterator();
            while (it.hasNext()) {
                System.out.printf("%d ", it.next());
            }
            System.out.println();
        }

        System.out.println();
    }

    public void sortAscending(ArrayList<Integer> row) {
        for (int i = 0; i < 20; i++) {
            for (int j = i + 1; j < 20; j++) {
                if (row.get(i) > row.get(j)) {
                    Collections.swap(row, i, j);
                }
            }
        }
    }

    public void sortDescending(ArrayList<Integer> row) {
        for (int i = 0; i < 20; i++) {
            for (int j = i + 1; j < 20; j++) {
                if (row.get(i) < row.get(j)) {
                    Collections.swap(row, i, j);
                }
            }
        }
    }

    public void sort_matrix() {
        Iterator<ArrayList<Integer>> iteratorm = arrayRandom.iterator();

        for (int i = 0; i < 5; i++) {
            if (iteratorm.hasNext()) {
                if (i % 2 == 0) {
                    sortAscending(iteratorm.next());
                } else {
                    sortDescending(iteratorm.next());
                }
            }
        }
    }

    public void countFrequency() {
        int[] array = new int[181];

        for (int i = 0; i < 181; i++) {
            array[i] = 0;
        }

        Iterator<ArrayList<Integer>> iteratorm = arrayRandom.iterator();

        while (iteratorm.hasNext()) {
            Iterator<Integer> it = iteratorm.next().iterator();

            while (it.hasNext()) {
                array[it.next() - 20]++;
            }
        }

        System.out.println("Element        Frequency");

        for (int i = 0; i < 181; i++) {
            if (array[i] > 0) {
                System.out.println(i + 20 + " ----------------> " + array[i]);
            }
        }
    }

    public void Question1_main() {
        // Matrix Q1 = new Matrix();
        System.out.println();
        System.out
                .println("--------------------------------------- Question 1 ---------------------------------------");
        populate_matrix();
        System.out.println("Randomly generated matrix[5][20] : \n");
        print_matrix();
        sort_matrix();
        System.out.println("\nMatrix[5][20] after sorting first-->ascending , second-->descending");
        System.out.println("third-->descending and so on ... : \n");
        print_matrix();
        System.out.println("List of unique elements with its frequency : \n");
        countFrequency();
        System.out.println();
    }

}

class Grid {
    public static int paths(int x, int y, int N, int M, int src, int dest) {
        if (x < 0 || y < 0 || x > N || y > M) {
            return 0;
        }

        if (x == src - 1 || y == dest - 1) {
            return 1;
        }
        return paths(x + 1, y, N, M, src, dest) + paths(x, y + 1, N, M, src, dest);
    }

    public static void findPaths(int[][] mat, Stack<Integer> path, int i, int j, int dest_x, int dest_y) {
        int M = mat.length;
        int N = mat[0].length;
        if (i == dest_x - 1 && j == dest_y - 1) {
            path.add(mat[i][j]);
            System.out.println(path);
            path.pop();
            return;
        }
        path.add(mat[i][j]);

        if ((i >= 0 && i < M && j + 1 >= 0 && j + 1 < N)) {
            findPaths(mat, path, i, j + 1, dest_x, dest_y);
        }

        if ((i + 1 >= 0 && i + 1 < M && j >= 0 && j < N)) {
            findPaths(mat, path, i + 1, j, dest_x, dest_y);
        }

        path.pop();
    }

    public static void PrintPaths(int N, int M, int dest_x, int dest_y) {
        int[][] Mat = new int[N][M];
        int K = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Mat[i][j] = (K++);
            }
        }

        Stack<Integer> PPaths = new Stack<>();

        int x = 0, y = 0;

        findPaths(Mat, PPaths, x, y, dest_x, dest_y);
    }
}

class Question2 {
    int[] arr = new int[10000];
    int[] a1 = new int[2000];
    int[] a2 = new int[2000];
    int[] a3 = new int[2000];
    int[] a4 = new int[2000];
    int[] a5 = new int[2000];
    int n = 2000;

    public void populate_matrix() {
        long seed = 10197;
        Random r = new Random();
        r.setSeed(seed);
        for (int i = 0; i < 10000; i++)
            arr[i] = r.nextInt(501);
    }

    public void print_matrix() {
        for (int i = 0; i < 10000; i++)
            System.out.printf("%d ", arr[i]);
        System.out.println();
    }

    public void split_arr() {
        for (int i = 0; i < 2000; i++) {
            a1[i] = arr[i];
        }
        for (int i = 2000; i < 4000; i++) {
            a2[i - 2000] = arr[i];
        }
        for (int i = 4000; i < 6000; i++) {
            a3[i - 4000] = arr[i];
        }
        for (int i = 6000; i < 8000; i++) {
            a4[i - 6000] = arr[i];
        }
        for (int i = 8000; i < 10000; i++) {
            a5[i - 8000] = arr[i];
        }
        /*
         * for (int i = 0; i < 2000; i++) System.out.printf("%d ", a1[i]);
         * System.out.println(); for (int i = 0; i < 2000; i++) System.out.printf("%d ",
         * a2[i]); System.out.println(); for (int i = 0; i < 2000; i++)
         * System.out.printf("%d ", a3[i]); System.out.println(); for (int i = 0; i <
         * 2000; i++) System.out.printf("%d ", a4[i]); System.out.println(); for (int i
         * = 0; i < 2000; i++) System.out.printf("%d ", a5[i]); System.out.println();
         */
    }

    public static void sortarr(int[] a, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }

    public void algo() {
        Thread obj1 = new Thread(new MyThread(a1, n));
        Thread obj2 = new Thread(new MyThread(a2, n));
        Thread obj3 = new Thread(new MyThread(a3, n));
        Thread obj4 = new Thread(new MyThread(a4, n));
        Thread obj5 = new Thread(new MyThread(a5, n));
        obj1.start();
        obj2.start();
        obj3.start();
        obj4.start();
        obj5.start();
        mergearr();
    }

    public void mergearr() {
        int[] result = KSortedArray.mergeKSortedArray(new int[][] { a1, a2, a3, a4, a5 });
        System.out.println(Arrays.toString(result));
    }
}

class ArrayContainer implements Comparable<ArrayContainer> {
    int[] arr;
    int index;

    public ArrayContainer(int[] arr, int index) {
        this.arr = arr;
        this.index = index;
    }

    @Override
    public int compareTo(ArrayContainer o) {
        return this.arr[this.index] - o.arr[o.index];
    }
}

class KSortedArray {
    public static int[] mergeKSortedArray(int[][] arr) {
        PriorityQueue<ArrayContainer> queue = new PriorityQueue<ArrayContainer>();
        int total = 0;

        for (int i = 0; i < arr.length; i++) {
            queue.add(new ArrayContainer(arr[i], 0));
            total = total + arr[i].length;
        }

        int m = 0;
        int result[] = new int[total];

        while (!queue.isEmpty()) {
            ArrayContainer ac = queue.poll();
            result[m++] = ac.arr[ac.index];

            if (ac.index < ac.arr.length - 1) {
                queue.add(new ArrayContainer(ac.arr, ac.index + 1));
            }
        }

        return result;
    }
}

class Grid {
    public static int paths(int x, int y, int N, int M, int src, int dest) {
        if (x < 0 || y < 0 || x > N || y > M) {
            return 0;
        }
        if (x == src - 1 || y == dest - 1) {
            return 1;
        }
        return paths(x + 1, y, N, M, src, dest) + paths(x, y + 1, N, M, src, dest);
    }

    public static void findPaths(int[][] mat, Stack<Integer> path, int i, int j, int dest_x, int dest_y) {
        int M = mat.length;
        int N = mat[0].length;
        if (i == dest_x - 1 && j == dest_y - 1) {
            path.add(mat[i][j]);
            System.out.println(path);
            path.pop();
            return;
        }
        path.add(mat[i][j]);

        if ((i >= 0 && i < M && j + 1 >= 0 && j + 1 < N)) {
            findPaths(mat, path, i, j + 1, dest_x, dest_y);
        }

        if ((i + 1 >= 0 && i + 1 < M && j >= 0 && j < N)) {
            findPaths(mat, path, i + 1, j, dest_x, dest_y);
        }

        path.pop();
    }

    public static void PrintPaths(int N, int M, int dest_x, int dest_y) {
        int[][] Mat = new int[N][M];
        int K = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Mat[i][j] = (K++);
            }
        }
        Stack<Integer> PPaths = new Stack<>();
        int x = 0, y = 0;
        findPaths(Mat, PPaths, x, y, dest_x, dest_y);
    }
}

class MyThread implements Runnable {
    int[] a1;
    int n;

    public MyThread(int[] a, int n) {
        this.a1 = a;
        this.n = n;
    }

    public void run() {
        Question2.sortarr(a1, n);
    }
}