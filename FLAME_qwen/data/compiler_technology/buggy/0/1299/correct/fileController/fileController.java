package fileController;

import java.io.*;

public class fileController {
    private static BufferedReader read;
    private static BufferedWriter write;
    public static void setRead(String fileName) throws IOException {
        read = new BufferedReader(new FileReader(fileName));
    }
    public static void closeRead(){
        try {
            read.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static void setWrite(String fileName) throws IOException{
        write = new BufferedWriter(new FileWriter(fileName));
    }
    public static void closeWrite(){
        try {
            write.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static char readAChar() throws IOException{
        char c;
        c = (char) read.read();
        return c;
    }

    public static void printALine(String content){
        try {
            write.write(content);
            write.write('\n');
            write.flush();
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}
