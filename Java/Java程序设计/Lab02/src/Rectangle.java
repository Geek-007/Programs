/**
 * Created by qqf on 11/02/2017.
 */

import java.util.Scanner;

public class Rectangle {

    int height;
    int width;

    public int getArea(int height, int width) {
        return height * width;
    }

    public int getPerimeter(int height, int width){
        return 2 * (height + width);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String [] param = input.nextLine().split(" ");
        Rectangle rec = new Rectangle();
        rec.height = Integer.parseInt(param[0]);
        rec.width = Integer.parseInt(param[1]);
        int Area = rec.getArea(rec.height, rec.width);
        int Perimeter = rec.getPerimeter(rec.height, rec.width);
        System.out.println(Area + " " + Perimeter);
    }
}
