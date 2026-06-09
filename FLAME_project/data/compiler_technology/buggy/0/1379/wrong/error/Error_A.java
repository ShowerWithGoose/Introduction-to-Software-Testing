package error;

import error.Error;
import frontend.FileOutput;

public class Error_A extends Error {
    private String name;
    private FileOutput fileOutput;
    private int lineNum;

    public Error_A(String name, FileOutput fileOutput, int lineNum) {
        this.name = name;
        this.fileOutput = fileOutput;
        this.lineNum = lineNum;
    }

    @Override
    public void printError() {
        fileOutput.write(lineNum + " a");
    }
}
