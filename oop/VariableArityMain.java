import java.util.ArrayList;
import java.util.Scanner;

// Siddharth Pandey
// S20190010163
abstract class VariableOperation {
    ArrayList<Integer> op;
    int ans;

    abstract int compute();

    abstract void printresult();
}

class AddVariableOperation extends VariableOperation {

    int ans = 0;

    int compute() {
        for (int i : op)
            ans += i;

        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class SubVariableOperation extends VariableOperation {

    int compute() {
        ans = op.get(0);
        for (int i = 1; i < op.size(); i++)
            ans -= op.get(i);

        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class MulVariableOperation extends VariableOperation {

    int ans = 1;

    int compute() {
        for (int i : op)
            ans *= i;

        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class DivVariableOperation extends VariableOperation {

    int compute() {
        ans = op.get(0);
        for (int i = 1; i < op.size(); i++)
            ans /= op.get(i);

        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class VariableEquationParser {
    static VariableOperation parseBinaryOpString(String binOpString) {

        String[] a = binOpString.trim().split(" ");

        if (a[1].equals("+")) {
            AddVariableOperation x = new AddVariableOperation();
            x.op = new ArrayList<Integer>();
            for (int i = 0; i < a.length; i = i + 2) {

                x.op.add(Integer.parseInt(a[i]));

            }

            return x;
        }

        else if (a[1].equals("-")) {
            SubVariableOperation x = new SubVariableOperation();
            x.op = new ArrayList<Integer>();
            for (int i = 0; i < a.length; i = i + 2) {

                x.op.add(Integer.parseInt(a[i]));

            }

            return x;
        }

        else if (a[1].equals("*")) {
            MulVariableOperation x = new MulVariableOperation();
            x.op = new ArrayList<Integer>();
            for (int i = 0; i < a.length; i = i + 2) {

                x.op.add(Integer.parseInt(a[i]));

            }

            return x;
        }
        // Left to Right
        else if (a[1].equals("/")) {
            DivVariableOperation x = new DivVariableOperation();
            x.op = new ArrayList<Integer>();
            for (int i = 0; i < a.length; i = i + 2) {

                x.op.add(Integer.parseInt(a[i]));

            }

            return x;
        }
        return null;

    }
}

public class VariableArityMain {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println(
                "Enter the Equation with space between each character (Only one operand can be use multiple time)");
        VariableOperation object = VariableEquationParser.parseBinaryOpString(scan.nextLine());
        object.compute();
        System.out.println("The Result of the Expression is");
        object.printresult();

        scan.close();
    }
}
