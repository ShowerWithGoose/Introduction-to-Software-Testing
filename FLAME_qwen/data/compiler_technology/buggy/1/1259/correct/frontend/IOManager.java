package frontend;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class IOManager
{
    public static BufferedReader reader;
    public static BufferedWriter writer;

    public static void InitIOReader(BufferedReader reader){
        IOManager.reader = new BufferedReader(reader);
    }

    public static void InitIOWriter(BufferedWriter writer){
        IOManager.writer = writer;
    }

    public static void CloseIO() throws IOException {
        reader.close();
        writer.close();
    }

    public static void Write(String text, boolean newLine){
        try{
            writer.write(text);
            if(newLine){
                writer.newLine();
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
