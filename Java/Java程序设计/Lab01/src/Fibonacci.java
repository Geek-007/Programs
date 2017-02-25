/**
 * Created by qqf on 10/02/2017.
 */

import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner input = new Scanner( System.in );
        int N = input.nextInt();

        long F0=1, F1=1, FN=1;
        while(N-->1){
            FN = F0 + F1;
            F0 = F1;
            F1 = FN;
        }
        System.out.println(FN);
    }
}
