package io;

import frontend.Token;
import io.Conponent.ErrorPrinter;
import io.Conponent.ErrorToken;
import io.Conponent.InputScanner;
import io.Conponent.LexerPrinter;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;

public class Settings {
    private static Settings instance;
    private final boolean fileInputSwitch;
    private final boolean errorPrinterSwitch;

    private final boolean lexerPrinterSwitch;


    private InputScanner inputScanner;
    private LexerPrinter lexerPrinter;
    private ErrorPrinter errorPrinter;

    private final String inputPath;
    private final String errorPath;
    private final String lexerPath;

    private Settings() {
        this.fileInputSwitch = true;
        this.errorPrinterSwitch = true;
        this.lexerPrinterSwitch = true;

        this.inputPath = "testfile.txt";
        this.errorPath = "error.txt";
        this.lexerPath = "lexer.txt";
        try {
            this.setBuffers();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    private void setBuffers() throws IOException {
        this.inputScanner = new InputScanner(this.fileInputSwitch, this.inputPath);
        this.errorPrinter = new ErrorPrinter();
        this.lexerPrinter = new LexerPrinter();

        errorPrinter.init(this.errorPath, this.errorPrinterSwitch);
        lexerPrinter.init(this.lexerPath, this.lexerPrinterSwitch);
    }

    public void closeBuffers() {
        if (this.errorPrinterSwitch) {
            this.errorPrinter.close();
        }
        if (this.lexerPrinterSwitch) {
            this.lexerPrinter.close();
        }
    }

    public BufferedReader getFileInputBuffer() {
        return inputScanner.getReader();
    }

    public static Settings getInstance() {
        if (instance == null) {
            instance = new Settings();
        }
        return instance;
    }

    public void addErrorToken(ErrorToken token) {
        this.errorPrinter.addErrorToken(token);
    }

    public void addNormalToken(ArrayList<Token> tokens) {
        this.lexerPrinter.addToken(tokens);
    }

    public void print() {
        this.lexerPrinter.print();
        this.errorPrinter.print();
    }
}
