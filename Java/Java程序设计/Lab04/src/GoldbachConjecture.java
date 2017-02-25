/**
 * Created by qqf on 13/02/2017.
 */

import java.util.Scanner;
import static java.lang.Math.sqrt;

public class GoldbachConjecture {

    public static boolean isPrime(long num) {
        for (long ii = 2; ii <= sqrt(num); ii++) {
            if (num % ii == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long num = input.nextLong();
        if (num > 6 && num % 2 == 0){
            for(long ii = 2; ii <= num / 2; ii++){
                if(isPrime(ii) && isPrime(num - ii)){
                    System.out.println(Long.toString(num) + "=" + Long.toString(ii) + "+" + Long.toString(num-ii));
                }
            }
        }
    }

}
