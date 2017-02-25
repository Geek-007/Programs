/**
 * Created by qqf on 12/02/2017.
 */

import java.util.Scanner;

class Person{
    String type;
    long [] scores;
    private int score_ave;

    public Person(String type, long [] scores){
        this.type = type;
        this.scores = scores;
    }

    public void print_ave(){
        double sum = 0;
        for(int ii=0; ii<scores.length; ii++){
            sum = sum + scores[ii];
        }
        score_ave = (int) sum/scores.length;
        System.out.println(type + " " + score_ave);
    }
}

class Student extends Person{
    public Student(long [] scores){
        super("Student", scores);
    }
}

class Teacher extends Person{
    public Teacher(long [] scores){
        super("Teacher", scores);
    }
}

public class TeacherStudent {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long nlines = Long.parseLong(input.nextLine());
        String [] str_scores;
        for(long ii=0; ii<nlines; ii++){
            str_scores = input.nextLine().split(" ");
            long [] scores = new long [str_scores.length];
            for(int jj=0; jj<str_scores.length; jj++){
                scores[jj] = Long.parseLong(str_scores[jj]);
            }

            if(scores.length == 3){
                Student aperson = new Student(scores);
                aperson.print_ave();
            }
            else {
                Teacher aperson = new Teacher(scores);
                aperson.print_ave();
            }
        }
    }
}
