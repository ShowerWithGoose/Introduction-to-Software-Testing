package utils;

import error.Mistake;
import frontend.Config;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class OutputTool {
    public static List<Mistake> mistakeList = new ArrayList<>();

    public static void writeToFile(FileWriter fileWriter, String string) {
        if (!Config.emitSyntaxTree) { return; }
        try {
            fileWriter.write(string);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void printError() throws IOException {
        FileWriter fileWriter = new FileWriter(Config.errorOutput);
        Collections.sort(mistakeList);
        for (Mistake mistake : mistakeList) {
            fileWriter.write(mistake.toString() + "\n");
        }
        fileWriter.close();
    }
}