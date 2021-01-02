import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class CreateFile {
    void CreationOfFIle() {
        try {
            File ob1 = new File("GeometricalShapesInput.txt");
            File ob2 = new File("GeometricalShapesOutput.txt");

            if (ob1.createNewFile() && ob2.createNewFile()) {
                System.out.println("File created: " + ob1.getName());
                System.out.println("File created: " + ob2.getName());
            } else {
                System.out.println("File already exits");
            }
        } catch (IOException e) {
            System.out.println("An error occurred");
            e.printStackTrace();
        }
    }
}

class ReadFile {
    void FileReading() {
        try {
            File ob = new File("GeometricalShapesInput.txt");
            Scanner sc = new Scanner(ob);
            while (sc.hasNextLine()) {
                String data = sc.nextLine();
                System.out.println(data);

            }
            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
}

class GeometricalShapes {
    double AreaOfRectangle(int l, int b) {
        double area_r = l * b;
        return area_r;
    }

    double AreaOfSquare(int l) {
        double area_r = l * l;
        return area_r;
    }

    double AreaOfCircle(int r) {
        double area_c = Math.PI * (r) * (r);
        return area_c;
    }
}

public class sid {
    public static void main(String args[]) throws IOException {
        CreateFile ob = new CreateFile();
        ob.CreationOfFIle();
        try {
            FileWriter w = new FileWriter("GeometricalShapesInput.txt");
            w.write("1,Circle,Nil,Nil,3\n");
            w.write("2,Rectangle,2,4,Nil\n");
            w.write("3,Square,2,2,Nil\n");
            w.write("4,Circle,Nil,Nil,2\n");
            w.write("5,Circle,Nil,Nil,4\n");
            w.write("6,Rectangle,2,3,Nil\n");
            w.write("7,Square,3,3,Nil\n");
            w.write("8,Rectangle,3,4,Nil\n");
            w.write("9,Rectangle,-5,2,Nil\n");
            w.write("10,Circle,Nil,Nil,5\n");
            w.close();
        } catch (IOException e) {
            System.out.println("An error occurred");
            e.printStackTrace();
        }
        ReadFile x = new ReadFile();
        x.FileReading();
        File read_file = new File("GeometricalShapesInput.txt");
        Scanner scan = new Scanner(read_file);
        Map<Double, String> newTempMap = new HashMap<Double, String>();
        GeometricalShapes areas = new GeometricalShapes();
        while (scan.hasNextLine()) {
            String data = scan.nextLine();
            String[] sarr = data.trim().split(",");
            if (sarr[1].equals("Rectangle")) {
                newTempMap.putIfAbsent(areas.AreaOfRectangle(Integer.parseInt(sarr[2]), Integer.parseInt(sarr[3])),
                        data);
            } else if (sarr[1].equals("Circle")) {
                newTempMap.putIfAbsent(areas.AreaOfCircle(Integer.parseInt(sarr[4])), data);
            } else {
                newTempMap.putIfAbsent(areas.AreaOfSquare(Integer.parseInt(sarr[2])), data);
            }
        }
        double[] tarr = new double[newTempMap.size()];
        int index = 0;
        for (Map.Entry<Double, String> entry : newTempMap.entrySet()) {
            tarr[index++] = entry.getKey();

        }
        Arrays.sort(tarr);
        FileWriter write_fileOutPut = new FileWriter("GeometricalShapesOutput.txt");
        for (double entry : tarr) {
            try {
                write_fileOutPut.write(newTempMap.get(entry) + "\n");
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        write_fileOutPut.close();

    }
}