import java.lang.Math;
import java.util.Scanner;

class Circle {
    private double radius;
    private String color;

    public Circle(double radius) {
        this.radius = radius;
        this.color = "";
    }

    public Circle(double radius, String color) {
        this.radius = radius;
        this.color = color;
    }

    public double getRadius() {
        return radius;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public String getColor() {
        return color;
    }
}

class Cylinder extends Circle {
    private double height;

    public Cylinder(double height, double radius) {
        super(radius);
        this.height = height;
    }

    public Cylinder(double height, double radius, String color) {
        super(radius, color);
        this.height = height;
    }

    public double getHeight() {
        return height;
    }

    public double getVolume() {
        return getArea() * height;
    }

    @Override
    public double getArea() {
        return 2 * Math.PI * getRadius() * (getRadius() + height);
    }
}

public class Program_2 {
    public static void main(String[] args) {
        int k = 1;
        while (k != -1) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the height of Cylinder 1: ");
            double height1 = scanner.nextDouble();
            System.out.print("Enter the radius of Cylinder 1: ");
            double radius1 = scanner.nextDouble();
            scanner.nextLine();
            System.out.print("Enter the color of Cylinder 1: ");
            String color1 = scanner.nextLine();
            System.out.print("Enter the height of Cylinder 2: ");
            double height2 = scanner.nextDouble();
            System.out.print("Enter the radius of Cylinder 2: ");
            double radius2 = scanner.nextDouble();
            scanner.nextLine();
            System.out.print("Enter the color of Cylinder 2: ");
            String color2 = scanner.nextLine();
            // Creating instances of Cylinder
            Cylinder cylinder1 = new Cylinder(height1, radius1, color1);
            Cylinder cylinder2 = new Cylinder(height2, radius2, color2);
            // Printing similar cylinders if area, volume, and color are the same
            if (cylinder1.getArea() == cylinder2.getArea() &&
                    cylinder1.getVolume() == cylinder2.getVolume() &&
                    cylinder1.getColor().equals(cylinder2.getColor())) {
                System.out.println("The cylinders are similar.");
                // Accessing methods from the base class
                System.out.println("Cylinder 1 - Radius: " + cylinder1.getRadius());
                System.out.println("Cylinder 1 - Area: " + cylinder1.getArea());
                System.out.println("Cylinder 1 - Color: " + cylinder1.getColor());
                // Accessing methods from the derived class
                System.out.println("Cylinder 2 - Height: " + cylinder2.getHeight());
                System.out.println("Cylinder 2 - Volume: " + cylinder2.getVolume());
                System.out.println("Cylinder 2 - Color: " + cylinder2.getColor());
            } else {
                System.out.println("The cylinders are different.");
                // Accessing methods from the base class
                System.out.println("Cylinder 1 - Radius: " + cylinder1.getRadius());
                System.out.println("Cylinder 1 - Area: " + cylinder1.getArea());
                System.out.println("Cylinder 1 - Color: " + cylinder1.getColor());
                // Accessing methods from the derived class
                System.out.println("Cylinder 2 - Height: " + cylinder2.getHeight());
                System.out.println("Cylinder 2 - Volume: " + cylinder2.getVolume());
                System.out.println("Cylinder 2 - Color: " + cylinder2.getColor());
            }
            System.out.print("Any key to continue, -1 to stop: ");
            k = scanner.nextInt();
            scanner.nextLine();
        }
    }
}