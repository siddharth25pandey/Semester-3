import java.util.Scanner;

// Siddharth Pandey
// S20190010163

abstract class BinaryOperation {
    int op1, op2, ans;

    abstract int compute();

    abstract void printresult();
}

class AddBinaryOperation extends BinaryOperation {
    int compute() {
        ans = op1 + op2;
        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class SubBinaryOperation extends BinaryOperation {
    int compute() {
        ans = op1 - op2;
        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class MulBinaryOperation extends BinaryOperation {
    int compute() {
        ans = op1 * op2;
        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class DivBinaryOperation extends BinaryOperation {
    int compute() {
        ans = op1 / op2;
        return ans;
    }

    void printresult() {
        System.out.println(ans);
    }
}

class BinaryEquationParser {
    static BinaryOperation parseBinaryOpString(String binOpString) {

        String[] a = binOpString.trim().split(" ");

        if (a[1].equals("+")) {
            AddBinaryOperation x = new AddBinaryOperation();
            x.op1 = Integer.parseInt(a[0]);
            x.op2 = Integer.parseInt(a[2]);

            return x;
        }

        else if (a[1].equals("-")) {
            SubBinaryOperation x = new SubBinaryOperation();
            x.op1 = Integer.parseInt(a[0]);
            x.op2 = Integer.parseInt(a[2]);

            return x;
        }

        else if (a[1].equals("*")) {
            MulBinaryOperation x = new MulBinaryOperation();
            x.op1 = Integer.parseInt(a[0]);
            x.op2 = Integer.parseInt(a[2]);

            return x;
        }

        else if (a[1].equals("/")) {
            DivBinaryOperation x = new DivBinaryOperation();
            x.op1 = Integer.parseInt(a[0]);
            x.op2 = Integer.parseInt(a[2]);

            return x;
        }
        return null;

    }
}

public class BinaryMain {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println(
                "Enter the Binary operand Equation with space between each character (Only one operand can be use multiple time)");
        BinaryOperation object = BinaryEquationParser.parseBinaryOpString(scan.nextLine());
        object.compute();
        System.out.println("The Result of the Expression is");
        object.printresult();

        scan.close();
    }
}
