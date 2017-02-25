/**
 * Created by qqf on 12/02/2017.
 */

import java.util.Scanner;

public class Triangle {
    double a, b, c;

    public Triangle(double a, double b, double c){
        double MAX = Math.max(Math.max(a, b), c);
        double MIN = Math.min(Math.min(a, b), c);

        if (MAX <=0){
            this.a = 0;
            this.b = 0;
            this.c = 0;
        }
        else if (a+b>c && a+c>b && b+c>a){
            this.a = a;
            this.b = b;
            this.c = c;
        }
        else{
            this.a = MAX;
            this.b = MAX;
            this.c = MAX;
        }
    }

    public double getArea(double a, double b, double c){
        double s = 0.5*(a+b+c);
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String [] line = s.nextLine().split(" ");
        Triangle triangle = new Triangle(Double.parseDouble(line[0]), Double.parseDouble(line[1]),Double.parseDouble(line[2]));
        System.out.println(triangle.getArea(triangle.a, triangle.b, triangle.c));
    }
}
