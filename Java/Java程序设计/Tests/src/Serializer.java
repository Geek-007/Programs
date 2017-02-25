/**
 * Created by qqf on 16/02/2017.
 */

import java.io.*;

class Book implements Serializable{
    int id;
    String name;
    String author;
    float price;
    public Book (int id, String name, String author, float price){
        this.id = id;
        this.name = name;
        this.author = author;
        this.price = price;
    }
}

public class Serializer {
    public static void main(String[] args) throws IOException, ClassNotFoundException{
        Book book = new Book(100032, "Think in Java", "XXX", 30);
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("book.dat"));
        out.writeObject(book);
        out.close();

        Book books = null;
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("book.dat"));
        books = (Book)in.readObject();
        in.close();
        System.out.println("ID is " + books.id);
        System.out.println("name is " + books.name);
        System.out.println("author is " + books.author);
        System.out.println("price is " + books.price);
    }
}
