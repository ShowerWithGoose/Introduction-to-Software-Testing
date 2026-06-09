package util;

import model.Error;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ErrorPrint {
    public static void run(List<Error> errors) {
        //Errors排序
        errors.sort((e1, e2) -> Integer.compare(e1.getLineno(), e2.getLineno()));

        //输出到 error.txt
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("error.txt"));
            for(Error error: errors) {
                bw.write(error.getLineno() + " " + error.getErrorType());
                bw.newLine();
            }
            bw.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
