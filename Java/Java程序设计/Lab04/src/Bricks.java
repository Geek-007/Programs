/**
 * Created by qqf on 14/02/2017.
 */
import java.util.Scanner;
public class Bricks{

    public static long Arrange(long n){
        long s1=1, s2=2, s3=0;
        if (n==1){
            return s1;
        }
        else if(n==2){
            return s2;
        }
        else{
            for(long i=3; i<=n; i++){
                s3 = s1+s2;
                s1 = s2;
                s2 = s3;
            }
            return s3;
        }

    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        long N = input.nextLong();
        System.out.println(Arrange(N));
    }
}