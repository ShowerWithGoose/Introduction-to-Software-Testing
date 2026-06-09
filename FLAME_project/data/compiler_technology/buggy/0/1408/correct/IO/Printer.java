package IO;

import CompileError.CompileError;
import Front.Token;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Printer
{
    private final HashMap<Integer, ArrayList<CompileError>> errors = new HashMap<>();

    public Printer(ArrayList<CompileError> errorList)
    {
        setErrors(errorList);
    }

    public void setErrors(ArrayList<CompileError> errorList)
    {
        for (CompileError error : errorList)
        {
            int lineNum = error.getLineNum();
            if (!errors.containsKey(lineNum))
            {
                errors.put(lineNum, new ArrayList<>());
            }
            errors.get(lineNum).add(error);
        }
    }

    public void printErrors(String path) throws IOException {
        FileOutputStream writer = new FileOutputStream(path);
        for (int lineNum : errors.keySet())
        {
            ArrayList<CompileError> errorList = errors.get(lineNum);
            for (CompileError error : errorList)
            {
                String inf = error.information() + '\n';
                writer.write(inf.getBytes());
            }
        }
    }

    public void printLexerRes(String path, ArrayList<Token> tokens) throws IOException {
        FileOutputStream writer = new FileOutputStream(path);
        for (Token token : tokens)
        {
            String inf = token.information() + '\n';
            writer.write(inf.getBytes());
        }
    }
}
