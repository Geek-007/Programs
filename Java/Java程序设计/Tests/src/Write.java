/**
 * Created by qqf on 16/02/2017.
 */
import java.io.*;
public class Write {
    public static void main(String[] args) throws IOException{
        String fileName = "hello.txt";
        BufferedWriter out = new BufferedWriter(new FileWriter(fileName));
        out.write("hello");
        out.newLine();;
        out.write("This is another file using BufferedWriter");
        out.newLine();
        out.write("So I can use a common way to start a newline");
        out.close();
    }
}
