package Io;

import token.Errorz;
import token.Token;

import java.io.*;
import java.util.*;

public class Text {
    private ArrayList<String> lines;
    
    public Text() throws IOException {
        lines = new ArrayList<>();
    }
    
    public ArrayList<String> getLines() throws IOException {
        String fileName = "testfile.txt";
        File file = new File(fileName);
        InputStreamReader input = new InputStreamReader(new FileInputStream(file));
        BufferedReader bufferedReader = new BufferedReader(input);
        
        String line = null;
        line = bufferedReader.readLine();
        
        while (line != null) {
            lines.add(line);
            line = bufferedReader.readLine();
        }
        return lines;
    }
    
    public static void printError(ArrayList<Errorz> errors) throws IOException {
        FileWriter fw = new FileWriter("error.txt",true);
        BufferedWriter info = new BufferedWriter(fw);
        Collections.sort((List<Errorz>)errors );
        for (Errorz error : errors) {
            info.write(error.getRowNumber() + " " + error.getError()+"\n");
            info.flush();
        }
        info.close();
    }
    
    public static void printWord(String s) throws IOException {
        FileWriter fw = new FileWriter("parser.txt",true);
        BufferedWriter info = new BufferedWriter(fw);
        info.write(s + "\n");
        info.flush();
        info.close();
    }
    
    public static void printWord1(String s) throws IOException {
        FileWriter fw = new FileWriter("parser.txt",true);
        BufferedWriter info = new BufferedWriter(fw);
        info.write(s);
        info.flush();
        info.close();
    }

}
