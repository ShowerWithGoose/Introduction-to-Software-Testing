import Driver.Driver;
import Driver.Config;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        Driver driver = new Driver(args);
        driver.run();
        if (Driver.errorRecord.size() != 0) {
            if (Config.ERROR_OUTPUT_FILE == null || Config.ERROR_OUTPUT_FILE.equals("")) {
                System.out.println(Driver.errorRecord);
            } else {
                try (Writer writer = new OutputStreamWriter(new FileOutputStream(Config.ERROR_OUTPUT_FILE))) {
                    writer.write(Driver.errorRecord + "");
                    writer.close();
                } catch (IOException e) {
                    System.err.println("Error writing to file: " + Config.ERROR_OUTPUT_FILE);
                    e.printStackTrace();
                    return;
                }
            }
        }
    }
}
