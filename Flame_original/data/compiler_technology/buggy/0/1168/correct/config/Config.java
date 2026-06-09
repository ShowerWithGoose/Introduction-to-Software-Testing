package config;

import utils.IOUtils;

import java.io.IOException;
import java.io.PrintStream;

public class Config {
    public static String fileInPath = "testfile.txt";
    public static String fileOutPath = "lexer.txt";
    public static String errorOutPath = "error.txt";
    public static boolean lexer = true;

    public static void init() throws IOException {
        IOUtils.clear(fileOutPath);
        IOUtils.clear(errorOutPath);
        System.setOut(new PrintStream(fileOutPath));
        System.setErr(new PrintStream(errorOutPath));
    }
}