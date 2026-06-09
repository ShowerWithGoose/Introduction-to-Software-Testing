package util;

import common.GlobalData;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Error {
    public static void error(String process, int lineno, char errorType) {
        BufferedWriter bw;
        try {
            bw = new BufferedWriter(new FileWriter("error.txt", true));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        if(process.equals("Lexer"))
            GlobalData.Lexerflag = false;
        try {
            bw.write(lineno + " " + errorType);
            bw.newLine();
            bw.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
