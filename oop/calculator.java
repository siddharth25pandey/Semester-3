interface calu {
    void x(int a);

    void y(int b);

    void sum();

    void product();
}
/*class cal implements calu{

}*/
/*
 * class cal { int x; int y;
 * 
 * public int sum() { return x + y; }
 * 
 * public int product() { return x * y; } }
 */

public class calculator {
    public static void main(String args[]) {
        cal c = new cal();
        c.x = 10;
        c.y = 20;
        System.out.println(c.sum());

    }
}