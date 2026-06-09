package utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import java.io.*;

public class Reader {
    public static ArrayList<String> read() throws IOException {
        ArrayList<String> sourceCode = new ArrayList<>();

        // if (GlobalVars.debug) {
        //     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //     String string;
        //     while ((string = br.readLine()) != null) {
        //         sourceCode.add(string);
        //     }
        //     br.close();
        // } else {
        File file = new File("testfile.txt");
        if (!file.exists()) {
            file.createNewFile();
        }

        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String string;
        while ((string = br.readLine()) != null) {
            sourceCode.add(string);
        }
        br.close();

        return sourceCode;
    }
}