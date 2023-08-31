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
            Scanner input = new Scanner(System.in);

            System.out.print("Enter the height of Cylinder 1: ");
            double height1 = input.nextDouble();
            System.out.print("Enter the radius of Cylinder 1: ");
            double radius1 = input.nextDouble();
            input.nextLine();
            System.out.print("Enter the color of Cylinder 1: ");
            String color1 = input.nextLine();

            System.out.println();

            System.out.print("Enter the height of Cylinder 2: ");
            double height2 = input.nextDouble();
            System.out.print("Enter the radius of Cylinder 2: ");
            double radius2 = input.nextDouble();
            input.nextLine();
            System.out.print("Enter the color of Cylinder 2: ");
            String color2 = input.nextLine();

            // Creating instances of Cylinder
            Cylinder c1 = new Cylinder(height1, radius1, color1);
            Cylinder c2 = new Cylinder(height2, radius2, color2);
            System.out.println();

            // Printing similar cylinders if area, volume, and color are the same
            if (c1.getArea() == c2.getArea() &&
                    c1.getVolume() == c2.getVolume() &&
                    c1.getColor().equals(c2.getColor())) {
                System.out.println("The cylinders are similar.");

                // Accessing methods from the base class
                System.out.println("Cylinder 1 - Radius: " + c1.getRadius());
                System.out.println("Cylinder 1 - Area: " + c1.getArea());
                System.out.println("Cylinder 1 - Color: " + c1.getColor());

                // Accessing methods from the derived class
                System.out.println();
                System.out.println("Cylinder 2 - Height: " + c2.getHeight());
                System.out.println("Cylinder 2 - Volume: " + c2.getVolume());
                System.out.println("Cylinder 2 - Color: " + c2.getColor());
            } else {
                System.out.println("The cylinders are different.");

                // Accessing methods from the base class
                System.out.println("Cylinder 1 - Radius: " + c1.getRadius());
                System.out.println("Cylinder 1 - Area: " + c1.getArea());
                System.out.println("Cylinder 1 - Color: " + c1.getColor());

                // Accessing methods from the derived class
                System.out.println();
                System.out.println("Cylinder 2 - Height: " + c2.getHeight());
                System.out.println("Cylinder 2 - Volume: " + c2.getVolume());
                System.out.println("Cylinder 2 - Color: " + c2.getColor());
            }
            System.out.print("Any key to continue, -1 to stop: ");
            k = input.nextInt();
            input.nextLine();
        }
    }
}