package util;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;

public class File {
    public static InputStream readFile(String file) {
        FileInputStream fis = null;
        try {
            fis = new FileInputStream(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        BufferedInputStream bis = null;
        if (fis != null) {
            bis = new BufferedInputStream(fis);
        }
        return bis;
    }

    public static <T> void writeFile(String file, ArrayList<T> content) {
        try {
            java.io.FileOutputStream fileOutputStream = new java.io.FileOutputStream(file);
            for (T line : content) {
                fileOutputStream.write((line + "\n").getBytes());
            }
            fileOutputStream.close();
        } catch (java.io.IOException e) {
            e.printStackTrace();
            throw new RuntimeException("Can not write to file: " + file);
        }
    }
}
