import CSE.JavaProgramming; 
public class OopsFeature extends JavaProgramming { 
// @Override
    public void welcomeMessage() { 
        System.out.println("Overridden welcomeMessage method in RVCE 
        package\n"); 
        super.welcomeMessage(); // Calling the superclass method
    } 
// @Override
    void defaultMethod() { 
        System.out.println("Overridden defaultMethod in RVCE package\n"); 
    } 
    
    public static void main(String[] args) { 
        OopsFeature oopsFeature = new OopsFeature(); 
        oopsFeature.welcomeMessage(); 
        oopsFeature.defaultMethod(); 
    } 
} 
