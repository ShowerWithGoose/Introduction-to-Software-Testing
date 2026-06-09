package frontend;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PushbackReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;

public class Config {
    public static final PushbackReader TESTFILE_READER;

    static {
        try {
            TESTFILE_READER = new PushbackReader(new FileReader("testfile.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static final BufferedWriter ERROR_WRITER;

    static {
        try {
            ERROR_WRITER = new BufferedWriter(new FileWriter("error.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static final BufferedWriter PARSER_WRITER;

    static {
        try {
            PARSER_WRITER = new BufferedWriter(new FileWriter("parser.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static final BufferedWriter LEXER_WRITER;

    static {
        try {
            LEXER_WRITER = new BufferedWriter(new FileWriter("lexer.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static final BufferedWriter SYMBOL_WRITER;

    static {
        try {
            SYMBOL_WRITER = new BufferedWriter(new FileWriter("symbol.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void closeAll() {
        try {
            TESTFILE_READER.close();
            ERROR_WRITER.close();
            PARSER_WRITER.close();
            LEXER_WRITER.close();
            SYMBOL_WRITER.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
