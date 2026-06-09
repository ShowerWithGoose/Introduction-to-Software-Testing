package frontend.GrammaticalElements.statement;

import frontend.Token;

public class StmtBreak extends StmtEle{
    private Token break_;
    private Token semicolon;

    public StmtBreak(Token break_, Token semicolon) {
        this.break_ = break_;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(break_.toString());
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
