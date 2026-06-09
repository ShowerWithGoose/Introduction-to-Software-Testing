package util;

import common.GlobalData;
import model.Error;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class ErrorSave {
    public static void error(String process, int lineno, char errorType) {
        GlobalData.Errorflag = true;

        if(process.equals("Lexer")) {
            GlobalData.Lexerflag = false;
        }
        if(process.equals("Parser")) {
            GlobalData.Parserflag = false;
        }

        Error error = new Error(process, lineno, errorType);
        GlobalData.Errors.add(error);
    }
}
