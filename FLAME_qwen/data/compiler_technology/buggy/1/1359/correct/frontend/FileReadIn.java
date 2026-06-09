package frontend;

import java.io.*;

public class FileReadIn {
    private StringBuffer token;
    private final StringBuffer text;
    private int ptr;
    private int curLine;

    public FileReadIn(String filePath) {
        this.ptr = 0;
        this.curLine = 1;
        this.token = new StringBuffer();
        this.text = new StringBuffer();
        try {
            File file = new File(filePath);
            FileInputStream inputStream = new FileInputStream(file);
            InputStreamReader reader = new InputStreamReader(inputStream);
            while (reader.ready()) {
                text.append((char) reader.read());
            }
            // System.out.println(text.toString());
            reader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.text.append('\n');
        this.text.append((char)0);
    }

    public void pushLine() {
        this.curLine++;
    }

    public int getCurLine() {
        return curLine;
    }

    public void catToken() {
        this.token.append(this.text.charAt(ptr));
    }

    public void clearToken() {
        this.token = new StringBuffer();
    }

    public void nextChar() {
        this.ptr++;
    }

    public void preChar() {
        this.ptr--;
        if (this.ptr < 0) throw new RuntimeException("preChar ptr unavailable");
    }

    public char getChar() {
        return this.text.charAt(ptr);
    }

    public StringBuffer getToken() {
        return this.token;
    }

    public StringBuffer getText() {
        return this.text;
    }

}