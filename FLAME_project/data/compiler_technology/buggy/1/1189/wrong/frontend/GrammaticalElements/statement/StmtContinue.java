package frontend.GrammaticalElements.statement;

import frontend.Token;

public class StmtContinue extends StmtEle{
    private Token continue_;
    private Token semicolon;

    public StmtContinue(Token continue_, Token semicolon) {
        this.continue_ = continue_;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(continue_.toString());
        sb.append(semicolon.toString());
        return sb.toString();
    }
}
