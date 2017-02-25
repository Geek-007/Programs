/**
 * Created by qqf on 10/02/2017.
 */

import java.util.Arrays;
import java.util.Scanner;

public class StringSortingForMooc {
    public static void main(String[] args) {

        Scanner input = new Scanner( System.in );
        int N = input.nextInt();
        String s = input.nextLine();

        String [] arr1 = new String[N];

        int kk=0;
        while(N-->=1){
            s = input.nextLine();
            arr1[kk++] = s;
        }

        Arrays.sort(arr1);
        for(int i=0; i<arr1.length; i++)
            System.out.println(arr1[i]);

    }
}
