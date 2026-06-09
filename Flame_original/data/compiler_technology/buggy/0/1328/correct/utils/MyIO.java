package utils;

import config.Config;

import java.io.*;
import java.util.StringJoiner;

public class MyIO {
    public static String read(String inputFilePath) {
        // OPT: 使用 BufferedReader 进行缓冲，提高写入性能
        try (FileInputStream fis = new FileInputStream(inputFilePath);
             InputStreamReader isr = new InputStreamReader(fis);
             BufferedReader br = new BufferedReader(isr)) {
            StringJoiner stringJoiner = new StringJoiner("\n");
            String line;
            while ((line = br.readLine()) != null) {
                stringJoiner.add(line);
            }
            return stringJoiner.toString();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void write(String outputFilePath, String content) {
        // OPT: 使用 BufferedWriter 进行缓冲，提高写入性能
        try (FileOutputStream fos = new FileOutputStream(outputFilePath, true);
             OutputStreamWriter osw = new OutputStreamWriter(fos);
             BufferedWriter bw = new BufferedWriter(osw)) {
            bw.write(content);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void writeToken(String tokenMsg) {
        write(Config.outputFilePath, tokenMsg);
    }

    public static void writeError(String errorMsg) {
        write(Config.errorFilePath, errorMsg);
    }
}
