package Program_3a.RVCE;

import Program_3a.CSE.ThirdSem;

public class Csedept extends ThirdSem {
    // @Override
    public void welcomeMessage() {
        System.out.println("Hello from RVCE Package");
        super.welcomeMessage();
    }

    // @Override
    void defaultMethod() {
        System.out.println("Overriden defaultMethod in RVCE Package");
    }

    public static void main(String[] args) {
        Csedept cs = new Csedept();
        cs.welcomeMessage();
        cs.defaultMethod();
    }
}
