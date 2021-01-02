import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class a {
    public static void main(String[] args) {
        try {
            CreateFile.CreationOfFile();
        } catch (IOException e) {
            System.out.println("IO Exception Occured");
        
        }
        try {
            ReadFile.fileReading();
        } catch (IOException e) {
            System.out.println("IO Exception Occured");
            
        }

    }
}

class CreateFile {

    public static void CreationOfFile() throws IOException {

        try {
            File myObj = new File("GeometricalShapesInput.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        FileWriter write_file = new FileWriter("GeometricalShapesInput.txt");
        write_file.write("1,Circle,Nil,Nil,3\n");
        write_file.write("2,Rectangle,2,4,Nil\n");
        write_file.write("3,Square,2,2,Nil\n");
        write_file.write("4,Circle,Nil,Nil,2\n");
        write_file.write("5,Circle,Nil,Nil,4\n");
        write_file.write("6,Rectangle,2,3,Nil\n");
        write_file.write("7,Square,3,3,Nil\n");
        write_file.write("8,Rectangle,3,4,Nil\n");
        write_file.write("9,Rectangle,5,2,Nil\n");
        // write_file.write("9,Rectangle,-5,2,Nil\n"); // Uncomment this to check for
        // exception handling in the program. The program only runs if all the values
        // are positive.
        write_file.write("10,Circle,Nil,Nil,5");
        write_file.close();

        try {
            File myObj = new File("GeometricalShapesOutput.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}

class ReadFile {
    static void fileReading() throws IOException {
        ArrayList<String> shapeList = new ArrayList<String>();
        Scanner scan = new Scanner(new File("GeometricalShapesInput.txt"));

        while (scan.hasNext()) {
            shapeList.add(scan.nextLine());
        }

        int size = shapeList.size();
        double[] areaArray = new double[size];

        for (int i = 0; i < size; i++) {
            String[] temp = shapeList.get(i).split(",");
            if (temp[1].equals("Circle")) {
                int input = Integer.parseInt(temp[4]);
                if (input < 0) {
                    try {
                        throw new IllegalArgumentException("enter Only Positive Numbers and re-run the program");
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                        return;
                    }
                }

                areaArray[i] = GeometricShape.areaofCircle(Integer.parseInt(temp[4]));

            }

            else if (temp[1].equals("Square")) {
                int input = Integer.parseInt(temp[2]);
                if (input < 0) {
                    try {
                        throw new IllegalArgumentException("enter Only Positive Numbers and Re-Run the program");
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                        return;
                    }
                }

                areaArray[i] = GeometricShape.areaofSquare(Integer.parseInt(temp[2]));
            }

            else if (temp[1].equals("Rectangle")) {
                int input1 = Integer.parseInt(temp[2]), input2 = Integer.parseInt(temp[3]);
                if (input1 < 0 || input2 < 0) {
                    try {
                        throw new IllegalArgumentException("enter Only Positive Numbers and Re-run the program");
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                        return;
                    }
                }
                areaArray[i] = GeometricShape.areaofRectangle(Integer.parseInt(temp[2]), Integer.parseInt(temp[3]));
            }

        }

        for (int i = 0; i < size; i++) {
            int index = 0;
            double max = 0.0;
            for (int j = 0; j < size; j++) {
                if (areaArray[j] > max) {
                    max = areaArray[j];
                    index = j;
                }
            }

            areaArray[index] = -1;
            System.out.println(shapeList.get(index));
        }
    }
}

class GeometricShape {
    static double areaofRectangle(int l, int b) {
        return (double) l * b;
    }

    static double areaofSquare(int side) {
        return (double) side * side;
    }

    static double areaofCircle(int r) {
        return Math.PI * (double) r * (double) r;
    }
}
