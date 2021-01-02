import java.util.Scanner;

class point {
    int cox, coy;
    // double radius, area;
    Scanner sc = new Scanner(System.in);

    point() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the x Coordinate ");
        this.cox = sc.nextInt();
        System.out.println("Enter the y Coordinate ");
        this.coy = sc.nextInt();
    }

}

class rectangle {
    point pointOne;
    point pointTwo;

    rectangle(point p1, point p2) {
        this.pointOne = p1;
        this.pointTwo = p2;
    }

    double getHeight() {
        int h;
        if (pointOne.coy > pointTwo.coy) {
            h = pointOne.coy - pointTwo.coy;
        } else {
            h = pointTwo.coy - pointOne.coy;
        }
        return h;
    }

    double getWidth() {
        double w;
        if (pointOne.cox > pointTwo.cox) {
            w = pointOne.cox - pointTwo.cox;
        } else {
            w = pointTwo.cox - pointOne.cox;
        }
        return w;
    }

    double area_rect() {
        return getHeight() * getWidth();
    }
}

class circle {
    double radius, area;

    double getRadius(double r) {
        this.radius = r;
        return this.radius;
    }

    double area_circle() {
        this.area = Math.PI * (this.radius) * (this.radius);

        return this.area;
    }
}

public class AssignMG2163 {
    public static void main(String argv[]) {
        System.out.println("Enter the Pair of two Opposite Co-ordinates point\n");
        System.out.println("Enter the Co-ordinates of First Opposite point \n");
        point one = new point();
        System.out.println("Enter the Co-ordinates of Second Opposite point \n");
        point two = new point();
        System.out.println("");
        System.out.println("The Opposite Coordintes Points are " + "(" + one.cox + "," + one.coy + ")" + " and " + "("
                + two.cox + "," + two.coy + ")");
        rectangle a = new rectangle(one, two);
        circle b = new circle();
        System.out.println("The Height of the Rectangle is : " + a.getHeight());
        System.out.println("The Width of the Rectangle is : " + a.getWidth());
        System.out.println("The Area of the Rectangle is : " + a.area_rect() + " square_units");
        double r;
        if (a.getHeight() > a.getWidth()) {
            r = a.getWidth() / 2;
        } else {
            r = a.getHeight() / 2;
        }
        b.getRadius(r);
        System.out.println("The Largest Circle's radius that can be accomadated in the Rectangle is : " + r);
        System.out.println("The Largest Circle's Area that can be accomadated in the Rectangle is : " + b.area_circle()
                + " square_units");

    }
}