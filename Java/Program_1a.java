import java.util.Scanner;

class Complex {
    int real;
    int imaginary;

    Complex() {
        // default constructor
    }

    // parameterized constructor
    Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    Complex add(Complex c1, Complex c2) {
        Complex result = new Complex();
        result.real = c1.real + c2.real;
        result.imaginary = c1.imaginary + c2.imaginary;
        return result;
    }

    Complex subtract(Complex c1, Complex c2) {
        Complex result = new Complex();
        result.real = c1.real - c2.real;
        result.imaginary = c1.imaginary - c2.imaginary;
        return result;
    }

    // method overloading
    Complex add(Complex c1, Complex c2, Complex c3) {
        Complex result = new Complex();
        result.real = c1.real + c2.real + c3.real;
        result.imaginary = c1.imaginary + c2.imaginary + c3.imaginary;
        return result;
    }

    Complex subtract(Complex c1, Complex c2, Complex c3) {
        Complex result = new Complex();
        result.real = c1.real - c2.real - c3.real;
        result.imaginary = c1.imaginary - c2.imaginary - c3.imaginary;
        return result;
    }

    void display(Complex result) {
        System.out.print(result.real);
        if(result.imaginary < 0)
            System.out.println(result.imaginary + "i");
        else
            System.out.println("+" + result.imaginary + "i");
    }

}
public class Program_1a {
    public static void main(String[] args) {
        Complex result = new Complex();
        Scanner input = new Scanner(System.in);

        System.out.println("Enter real and imaginary part of complex number 1");
        Complex c1 = new Complex(input.nextInt(), input.nextInt());

        System.out.println("Enter real and imaginary part of complex number 2");
        Complex c2 = new Complex(input.nextInt(), input.nextInt());

        System.out.println("Enter real and imaginary part of complex number 3");
        Complex c3 = new Complex(input.nextInt(), input.nextInt());

        System.out.println("\nAdding 2 complex numbers: ");
        result.display(result.add(c1, c2));
        System.out.println("Subtracting 2 complex numbers: ");
        result.display(result.subtract(c2, c1));

        System.out.println("\nAdding 3 complex numbers: ");
        result.display(result.add(c1, c2, c3));
        System.out.println("Subtracting 3 complex numbers: ");
        result.display(result.subtract(c3, c2, c1));

        input.close();
    }
}
