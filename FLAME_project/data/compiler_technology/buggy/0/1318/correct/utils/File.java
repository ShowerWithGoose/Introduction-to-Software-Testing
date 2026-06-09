package utils;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.ArrayList;

public class File {
    //READ FILE
    public static BufferedInputStream ReadFile(String file) {
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

    public static void WriteFile(String file, ArrayList<String> content) {
        try (FileWriter writer = new FileWriter(file)) {
            for (String line : content) {
                writer.write(line);
                writer.write("\n");
            }
        } catch (java.io.IOException e) {
            e.printStackTrace();
        }
    }
}
