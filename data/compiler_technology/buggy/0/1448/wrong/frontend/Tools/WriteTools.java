package frontend.Tools;

import java.io.*;

public class WriteTools {
    private PrintStream defaultPrintStream = System.out;
    private PrintStream printStream = defaultPrintStream;
    public void setOutputPath(File filepath, boolean append) {
        try {
            if (append) {
                printStream = new PrintStream(new FileOutputStream(filepath, true), true);
            } else {
                printStream = new PrintStream(filepath, "UTF-8");
            }
            System.setOut(printStream);
        } catch (FileNotFoundException e) {
            System.out.println("Output file not found!");
        } catch (UnsupportedEncodingException e) {
            System.out.println("UTF-8 unavailable!");
        }

    }
    public void reset(){
        System.setOut(defaultPrintStream);
        printStream.close();
    }
}