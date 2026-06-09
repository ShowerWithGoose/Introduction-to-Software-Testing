package io.Conponent;

import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ErrorPrinter implements output {

    private String outputPath;
    private BufferedWriter writer;

    private ArrayList<ErrorToken> errorTokens;
    @Override
    public void init(String path, boolean control) {
        this.outputPath = path;
        try {
            this.writer = control ? new BufferedWriter(new FileWriter(this.outputPath, false)) : null;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        this.errorTokens = new ArrayList<>();
    }

    @Override
    public BufferedWriter getOutputBuffer() {
        return writer;
    }

    @Override
    public void close() {
        try {
            this.writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void print() {
        try {
            for (ErrorToken token : this.errorTokens) {
                writer.write(token.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    public void addErrorToken(ErrorToken token) {
        this.errorTokens.add(token);
    }
}
