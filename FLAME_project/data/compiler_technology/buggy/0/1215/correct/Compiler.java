import frontEnd.*;
import java.io.*;
import java.util.*;
public class Compiler {

    public static void main(String[] args) {
        //String fileName="C:\\Users\\Lenovo\\IdeaProjects\\untitled1\\src\\testfile.txt";
        String fileName="testfile.txt";
        CompileLexer compileLexer=new CompileLexer();
        compileLexer.Lexer(fileName);
    }
}