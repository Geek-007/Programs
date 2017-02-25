/**
 * Created by qqf on 10/02/2017.
 */

import java.util.Scanner;

public class Intersection {
    public static void main(String[] args) {
        Scanner input = new Scanner( System.in );
        String line = input.nextLine();
        int N = Integer.parseInt(line);
        String [] set01 = input.nextLine().split(" ");
        line = input.nextLine();
        int M = Integer.parseInt(line);
        String [] set02 = input.nextLine().split(" ");

        int sum = 0;
        for(int kk=0; kk<N; kk++)
            for(int jj=0; jj<M; jj++)
                if(set01[kk].equals(set02[jj]))
                {sum++; continue;}

        System.out.println(sum>0?sum:"None");
    }
}
