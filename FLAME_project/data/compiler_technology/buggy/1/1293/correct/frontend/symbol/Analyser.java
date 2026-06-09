package frontend.symbol;

import frontend.error.Error;
import frontend.error.ErrorProcess;
import frontend.parser.Parser;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Analyser {
    private ErrorProcess errorProcess;
    private Parser parser;
    private int cur_tableId = 1;
    private int cur_symbolId = 0;
    private ArrayList<SymbolTable> tableList = new ArrayList<>();
    public Analyser(Parser parser, ErrorProcess errorProcess) {
        this.errorProcess = errorProcess;
        this.parser = parser;
    }

    public void outputResult() {
        BufferedWriter bufferedWriter = null;
        boolean isError = this.errorProcess.isError();
        try {
            if (!isError) {
                bufferedWriter = new BufferedWriter(new FileWriter("symbol.txt"));
            } else {
                bufferedWriter = new BufferedWriter(new FileWriter("error.txt"));
                List<Map.Entry<Integer, Error>> list = new ArrayList<>(this.errorProcess.getErrorHashMap().entrySet());
                Collections.sort(list, new Comparator<Map.Entry<Integer, Error>>() {
                    public int compare(Map.Entry<Integer, Error> o1,
                                       Map.Entry<Integer, Error> o2) {
                        return (o1.getValue().getLineNum()-o2.getValue().getLineNum());
                    }
                });
                for (Map.Entry<Integer, Error> entry : list) {
                    bufferedWriter.write(entry.getValue().getLineNum() + " " + entry.getValue().getErrorType());
                    bufferedWriter.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (bufferedWriter != null) {
                try {
                    bufferedWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
