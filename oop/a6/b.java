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
*/

class CreateFile {
    static void CreationOfFile() {

        try {
            FileWriter f = new FileWriter("GeometricalShapesInput.txt");
            f.write("1,Circle,Nil,Nil,3\n");
            f.write("2,Rectangle,2,4,Nil\n");
            f.write("3,Square,2,2,Nil\n");
            f.write("4,Circle,Nil,Nil,2\n");
            f.write("5,Circle,Nil,Nil,4\n");
            f.write("6,Rectangle,2,3,Nil\n");
            f.write("7,Square,3,3,Nil\n");
            f.write("8,Rectangle,3,4,Nil\n");
            f.write("9,Rectangle,5,2,Nil\n");
            f.write("10,Circle,Nil,Nil,5");
            f.close();
            System.out.println("Data Inserted & Updated Succesfully.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}

class ReadFile {
    static GeometricalShapes[] FileReading() {
        GeometricalShapes[] s = new GeometricalShapes[10];
        try {
            File obj = new File("GeometricalShapesInput.txt");
            Scanner sc = new Scanner(obj);
            int p = 0;
            String str;
            while (sc.hasNextLine()) {
                str = sc.nextLine();
                s[p] = new GeometricalShapes(str);
                p++;
            }
            sc.close();
            return s;
        } catch (FileNotFoundException e) {
            System.out.println("An error occured.");
            e.printStackTrace();
        }
        return s;
    }
}

class GeometricalShapes {
    int type_of_shape, l, b, r, no;
    double area;
    String dat;

    static void validate(double p) {
        if (p < 0) {
            System.out.println("Error: Negative Area is not valid");
            System.exit(0);
        }
    }

    GeometricalShapes(String data) {
        this.dat = data;
        data = data.replaceAll("\\s", "");
        String[] res = data.split("[,]", 0);

        int i = 0;
        for (String s : res) {
            if (i == 0) {
                i = 1;
                this.no = Integer.parseInt(s);
            } else if (i == 1) {
                i = 2;
                if (s.contains("Circle")) {
                    this.type_of_shape = 1;
                } else if (s.contains("Rectangle")) {
                    this.type_of_shape = 2;
                } else if (s.contains("Square")) {
                    this.type_of_shape = 3;
                } else {
                    System.out.println("No shape Identified\n");
                }
            } else if (i == 2) {
                i = 3;
                if (s.contains("Nil") == false)
                    this.l = Integer.parseInt(s);
            } else if (i == 3) {
                i = 4;
                if (s.contains("Nil") == false)
                    this.b = Integer.parseInt(s);
            } else if (i == 4) {
                i = 5;

                if (s.contains("Nil") == false)
                    this.r = Integer.parseInt(s);
            }
            if (this.type_of_shape == 1)
                AreaOfCircle();
            else if (this.type_of_shape == 2)
                AreaOfRectangle();
            else if (this.type_of_shape == 3)
                AreaofSquare();
        }
    }

    void AreaOfRectangle() {
        this.area = this.l * this.b;
        validate(this.area);
    }

    void AreaofSquare() {
        this.area = this.l * this.b;
        validate(this.area);
    }

    void AreaOfCircle() {
        this.area = Math.PI * this.r * this.r;
        validate(this.area);
    }
}

public class b {
    static void sort(GeometricalShapes a[]) {
        GeometricalShapes key;
        int size = a.length;
        for (int j = 1; j < size; j++) {
            key = a[j];
            int k = j - 1;
            while (k >= 0 && a[k].area < key.area) {
                a[k + 1] = a[k];
                k = k - 1;
            }
            a[k + 1] = key;
        }
    }

    public static void main(String args[]) throws IOException {
        CreateFile.CreationOfFile();
        GeometricalShapes[] shapes = ReadFile.FileReading();
        sort(shapes);
        try (FileWriter x = new FileWriter("GeometricalShapesOutput.txt")) {
            for (int i = 0; i < 10; i++) {
                x.write(shapes[i].dat + ", " + shapes[i].area + "\n");
            }
            x.flush();
            x.close();
        } catch (IOException error) {
            System.out.println("An error has occured.");
            error.printStackTrace();
        }
    }
}
