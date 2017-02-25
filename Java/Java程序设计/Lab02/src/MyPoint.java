/**
 * Created by qqf on 11/02/2017.
 */

import java.util.Scanner;
import static java.lang.Math.sqrt;
import static java.lang.Math.pow;

public class MyPoint {

    private double x, y;

    public MyPoint(){
        x = 0;
        y = 0;
    }

    public MyPoint(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double getD(MyPoint point){
        return sqrt(pow((this.x-point.x),2)+pow((this.y-point.y),2));
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String [] param1 = input.nextLine().split(" ");
        MyPoint point1 = new MyPoint(Double.parseDouble(param1[0]), Double.parseDouble(param1[1]));
        String [] param2 = input.nextLine().split(" ");
        MyPoint point2 = new MyPoint(Double.parseDouble(param2[0]), Double.parseDouble(param2[1]));
        System.out.println(point1.getD(point2));
    }
}
