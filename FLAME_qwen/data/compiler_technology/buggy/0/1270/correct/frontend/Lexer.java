package frontend;

import java.io.*;
import java.util.*;

public class Lexer {
    private List<String> lines;

    public Lexer(String filename) throws IOException {
        lines = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line;
        while((line = reader.readLine()) != null) {
            lines.add(line);
        }
        reader.close();
    }

    public void analyze(String lexerOutputFile, String errorOutputFile) {
        try {
            PrintWriter lexerOutput = new PrintWriter(new FileWriter(lexerOutputFile));
            PrintWriter errorOutput = new PrintWriter(new FileWriter(errorOutputFile));
            boolean insideComment = false;
            for(int lineNum = 0; lineNum < lines.size(); lineNum++){
                String line = lines.get(lineNum);
                StringBuilder processedLine = new StringBuilder();
                for(int i = 0; i < line.length(); i++) {
                    if (i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i + 1) == '*') {
                        insideComment = true;
                        i++;
                    } else if (insideComment && line.charAt(i) == '*' && i + 1 < line.length() && line.charAt(i + 1) == '/') {
                        insideComment = false;
                        i++;
                    } else if (!insideComment) {
                        processedLine.append(line.charAt(i));
                    }
                }
                List<Token> tokens = Token.tokenize(processedLine.toString());
                for(Token token: tokens) {
                    if(token.getType() != TokenType.ERROR){
                        lexerOutput.println(token.getType() + " " + token.getValue());
                    } else {
                        errorOutput.println((lineNum + 1) + " a");
                    }
                }
            }

            lexerOutput.close();
            errorOutput.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}