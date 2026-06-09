package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 关系表达式 RelExp == >   AddExp { ('<' | '>' | '<=' | '>=')  AddExp }
public class RelExp implements SyntaxNode {
  private static String name = "<RelExp>";
  private TokenIterator tokens;

  private ArrayList<Token> operaters = new ArrayList<>();
  private ArrayList<AddExp> addExps = new ArrayList<>();

  public RelExp(TokenIterator tokens) {
    this.tokens = tokens;
  }

  @Override
  public String syntaxPrinter() {
    StringBuilder sb = new StringBuilder();
    int len = operaters.size();
    sb.append(addExps.get(0).syntaxPrinter());
    sb.append(name + "\n");
    for (int i = 0; i < len; i++) {
      sb.append(operaters.get(i).syntaxPrinter());
      sb.append(addExps.get(i + 1).syntaxPrinter());
      sb.append(name + "\n");
    }
    return sb.toString();
  }

  @Override
  public boolean parse() {
    AddExp addExp = new AddExp(tokens);
    addExp.parse();
    addExps.add(addExp);

    while (tokens.hasNext()) {
      Token token = tokens.next();
      TokenType type = token.getType();
      if (!type.equals(TokenType.LSS)
          && !type.equals(TokenType.LEQ)
          && !type.equals(TokenType.GRE)
          && !type.equals(TokenType.GEQ)) {
        tokens.stepBack(1);
        break;
      }
      // AddOp
      operaters.add(token);

      // AddExp
      addExp = new AddExp(tokens);
      addExp.parse();
      addExps.add(addExp);
    }

    return true;
  }

}
