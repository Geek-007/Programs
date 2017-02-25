/**
 * Created by qqf on 12/02/2017.
 */

import java.util.Scanner;
import static java.lang.Math.sqrt;

class Graph{
    int a, b;

    public Graph(int a, int b){
        this.a = a;
        this.b = b;
    }
}

class Triangle extends Graph{
    int c;

    public Triangle(int a, int b, int c){
        super(a, b);
        this.c = c;
    }

    public void getArea() {
        double s = 0.5*(a+b+c);
        int area = (int) sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println(area);
    }
}

class Rectangle extends Graph{

    public Rectangle(int a, int b){
        super(a, b);
    }

    public void getArea(){
        int area = a * b;
        System.out.println(area);
    }
}

public class AreaCal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long nlines = input.nextLong();
        String tmp = input.nextLine();
        for(long ii=0; ii<nlines; ii++){
            String [] strlines = input.nextLine().split(" ");
            int [] line = new int [strlines.length];
            for(int jj=0; jj<line.length; jj++){
                line[jj] = Integer.parseInt(strlines[jj]);
            }
            if (line.length == 2){
                Rectangle graph = new Rectangle(line[0], line[1]);
                graph.getArea();
            } else{
                Triangle graph = new Triangle(line[0], line[1], line[2]);
                graph.getArea();
            }
        }

    }
}
