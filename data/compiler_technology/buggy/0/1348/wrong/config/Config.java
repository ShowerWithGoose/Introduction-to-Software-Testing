package config;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Paths;

public class Config {
    private static final String src = "testfile.txt";
    private static final String err = "error.txt";
    private static final String lexer = "lexer.txt";
    private static final String asm = "out.s";
    public static boolean printLex = true;

    public static FileInputStream getSrc() throws IOException {
        return new FileInputStream(Paths.get(src).toFile());
    }

    public static FileWriter getAsm() throws IOException {
        return new FileWriter(Paths.get(asm).toFile());
    }

    public static FileWriter getErr() throws IOException {
        return new FileWriter(Paths.get(err).toFile());
    }

    public static FileWriter getLexer() throws IOException {
        return new FileWriter(Paths.get(lexer).toFile());
    }
}
