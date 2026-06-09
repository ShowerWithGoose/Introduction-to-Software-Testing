package src;

public class State {
    public String state;

    public State(boolean isComment) {
        if(isComment){
            state = "comment";
        }
        else {
            state = "start";
        }
    }

    public void changeState(String newState) {
        state = newState;
    }

    public String getState() {
        return state;
    }
}
