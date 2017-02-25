/**
 * Created by qqf on 10/02/2017.
 */
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

public class StringSorting {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("How many string: ");

        int num = sc.nextInt();
        if(num==0) {System.out.println("Total number of string should not be zero!"); System.exit(0);}

        System.out.println("Please enter your string line by line: "); sc.nextLine();

        ArrayList mystring = new ArrayList();
        while(num>=1){
            mystring.add(sc.nextLine());
            num--;
        }
        Collections.sort(mystring);
        System.out.println(mystring);
    }
}
