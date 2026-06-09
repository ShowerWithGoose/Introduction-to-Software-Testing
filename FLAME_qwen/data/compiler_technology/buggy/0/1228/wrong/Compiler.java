import frontend.LexType;
import frontend.Lexer;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws IOException {

        File filePath = new File("testfile.txt");
        //File filePath = new File("C:\\idea\\文件\\bianyi\\src\\testfile.txt");
        //String filePath2 = "C:\\idea\\文件\\bianyi\\src\\lexer.txt";
        String filePath2 = "lexer.txt";
        BufferedWriter writer = new BufferedWriter(new FileWriter(filePath2));
        byte[] bytes = Files.readAllBytes(Paths.get(filePath.getAbsolutePath()));
        String source = new String(bytes, StandardCharsets.UTF_8);
        Lexer lexer = new Lexer(source);
        int i=0;
        while(lexer.next()&&i<300){
            if(lexer.getLexType()!= LexType.NOTE) {
                //System.out.println(lexer.getLexType() + " " + lexer.getToken());
                writer.write(lexer.getLexType() + " " + lexer.getToken()+"\n");
            }
            //i++;
        }
        writer.close();
    }
}