package IO;

import java.io.*;

public class IO {
    private final BufferedReader textfileReader;

    private final BufferedWriter lexerWriter;

    private final BufferedWriter parserWriter;

    private final BufferedWriter errorWriter;

    private final BufferedWriter symbolWriter;

    public IO() throws IOException {
        this.textfileReader = new BufferedReader(new FileReader("testfile.txt"));
        this.lexerWriter = new BufferedWriter(new FileWriter("lexer.txt"));
        this.parserWriter = new BufferedWriter(new FileWriter("parser.txt"));
        this.errorWriter = new BufferedWriter(new FileWriter("error.txt"));
        this.symbolWriter = new BufferedWriter(new FileWriter("symbol.txt"));
    }

    public BufferedReader getTextfileReader() {
        return textfileReader;
    }

    public BufferedWriter getLexerWriter() {
        return lexerWriter;
    }

    public BufferedWriter getParserWriter() {
        return parserWriter;
    }

    public BufferedWriter getErrorWriter() {
        return errorWriter;
    }

    public BufferedWriter getSymbolWriter() {
        return symbolWriter;
    }

    public void closeAll() {
        try {
            textfileReader.close();
            lexerWriter.close();
            parserWriter.close();
            errorWriter.close();
            symbolWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
