package frontend;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;

public class WrongFile {
    private static WrongFile instance = null;
    private HashMap<Integer, Wrong> wrongs;
    private boolean flag;
    private WrongFile() {
        this.wrongs = new HashMap<>();
        this.flag = false;
    }

    public static WrongFile getInstance() {
        if(instance == null) {
            instance = new WrongFile();
        }
        return instance;
    }

    public void addWrong(Wrong wrong) {
        this.flag = true;
        wrongs.put(wrong.getPosLine(), wrong);
    }

    public boolean getFlag() {
        return flag;
    }

    public void getPrint() {
        Set set = wrongs.keySet();
        Object[] arr = set.toArray();
        Arrays.sort(arr);
        String outputFileName = "error.txt";
        try {
            OutputStream outputStream = new FileOutputStream(outputFileName);
            PrintStream ps = new PrintStream(outputStream);
            for (Object i : arr) {
                ps.println(wrongs.get(i).getString());
            }
        } catch (FileNotFoundException e) {
            System.err.println("Can not open " + outputFileName);
        }
    }


}
