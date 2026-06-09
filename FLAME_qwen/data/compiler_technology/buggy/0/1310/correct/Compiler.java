import src.fronted.LexicAnalysis.LexicAnalysis;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<String> CodeString = read("testfile.txt");
        LexicAnalysis lexicAnalysis = LexicAnalysis.getInstance(CodeString);
        lexicAnalysis.excute();
        lexicAnalysis.output();
    }

    private static ArrayList<String> read(String pathname) throws IOException {
        File inputFile = new File(pathname);
        FileReader fileReader = new FileReader(inputFile);
        ArrayList<String> CodeString = new ArrayList<>();
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        String curString;
        while ((curString = bufferedReader.readLine()) != null) {
            CodeString.add(curString);
        }
        return CodeString;
    }
}
