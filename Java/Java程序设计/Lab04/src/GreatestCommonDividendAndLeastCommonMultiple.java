/**
 * Created by qqf on 13/02/2017.
 */

import static java.lang.Math.min;
import static java.lang.Math.max;
import java.util.Scanner;

public class GreatestCommonDividendAndLeastCommonMultiple {
    public static long GCF(long num1, long num2){
        long larger, smaller, tmp;
        larger = max(num1, num2);
        smaller = min(num1, num2);

        while (larger % smaller != 0 ){
            tmp = smaller;
            smaller = larger % smaller;
            larger = tmp;
        }
        return  smaller;
    }

    public static long LCM(long num1, long num2){
        return num1 * num2 / GCF(num1, num2);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long num1 = input.nextLong();
        long num2 = input.nextLong();
        System.out.println(Long.toString(GCF(num1, num2)) + " " + Long.toString(LCM(num1, num2)));
    }
}
