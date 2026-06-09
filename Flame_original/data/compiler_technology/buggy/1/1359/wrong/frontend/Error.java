package frontend;


import java.io.*;

import java.util.TreeMap;

public class Error {

    private TreeMap<Integer, String > errorList;

    public Error() {
        this.errorList = new TreeMap<>();
    }

    public void lexError(Integer line, String type) {

        errorList.put(line, type);

    }

    public void parseError(Integer line, String type) {

        errorList.put(line, type);
    }

    public void write2txt() {

        try (FileWriter writer = new FileWriter("error.txt", true)) {
            writer.write("");

            for (Integer key : errorList.keySet()) {
                writer.write(key + " " + errorList.get(key) + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}