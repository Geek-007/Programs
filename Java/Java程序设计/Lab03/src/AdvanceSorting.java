/**
 * Created by qqf on 12/02/2017.
 */

import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

class myarray <Type>{
    public Type [] myarr;

    public myarray(Type [] myarray){
        this.myarr = myarray;
    }

    public void mysort() {
        Arrays.sort(myarr);
        for(int ii=0; ii<myarr.length; ii++)
            System.out.println(myarr[ii]);
    }
}

public class AdvanceSorting {
    public static boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        }
        catch(NumberFormatException e) {
            return false;
        }
        catch(NullPointerException e) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int nlines = input.nextInt();
        String s = input.nextLine();
        int [] nums = new int [nlines];
        String [] strs = new String [nlines];
        int kk=0, jj=0;
        for(int ii=0; ii<nlines; ii++){
            s = input.nextLine();
            if (isInteger(s)){
                nums[kk++] = Integer.parseInt(s);
            } else {
                strs[jj++] = s;
            }
        }
        Integer [] arr11 = new Integer[kk];
        String [] arr22 = new String[jj];
        for(int i=0; i<kk; i++){
            arr11[i] = nums[i];
        }
        for(int i=0; i<jj; i++){
            arr22[i] = strs[i];
        }

        myarray intarr = new myarray<Integer>(arr11);
        intarr.mysort();

        myarray intarr2 = new myarray<String>(arr22);
        intarr2.mysort();

    }
}
