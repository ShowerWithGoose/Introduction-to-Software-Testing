package mainSys;

import java.io.*;

import static mainSys.StaticValues.*;

public class FileIO {
    public static String read() throws IOException {
        //读取同级的testfile.txt
        File file = new File("testfile.txt");
        FileReader reader = new FileReader(file);
        int tempChar;
        StringBuilder stringBuffer = new StringBuilder();
        while ((tempChar = reader.read()) != -1) {
            stringBuffer.append((char) tempChar);
        }
        reader.close();
        sourceCode = stringBuffer.toString();
        return stringBuffer.toString();
    }

    public static void output() throws IOException {
        if (!errors.isEmpty()) {
            //write its content to errorOutPutFile
            try (FileWriter writer = new FileWriter(errorOutPutFile)) {
                for (int i = 0; i < errors.size(); i++) {
                    writer.write(errors.get(i).toString());
                    writer.write("\n");
                    System.out.println(errors.get(i).toString());
                }
                writer.flush();
            }
        } else {
            try (FileWriter writer = new FileWriter(outputFile)) {
                // write tokens to outputFile
                for (int i = 0; i < tokens.size(); i++) {
                    writer.write(tokens.get(i).toString());
                    writer.write("\n");
                    System.out.println(tokens.get(i).toString());
                }
                writer.flush();
            }

        }
    }
}
