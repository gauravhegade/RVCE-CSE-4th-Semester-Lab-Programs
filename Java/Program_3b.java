// Animal interface
interface Animal {
    void eat();
}

// TiredAnimal interface extending Animal
interface TiredAnimal extends Animal {
    void sleep();
}

// Lion class implementing Animal and TiredAnimal
class Lion implements TiredAnimal {
    public void eat() {
        System.out.println("Lion is eating zebra.");
    }

    public void roar() {
        System.out.println("Lion is roaring.");
    }

    public void sleep() {
        System.out.println("Lion is sleeping.");
    }
}

// Snake class implementing Animal and TiredAnimal
class Snake implements TiredAnimal {
    public void eat() {
        System.out.println("Snake is eating frog.");
    }

    public void slither() {
        System.out.println("Snake is slithering.");
    }

    public void sleep() {
        System.out.println("Snake is sleeping.");
    }
}

// Example usage
public class Program_3b {
    public static void main(String[] args) {
        Lion lion = new Lion();
        lion.eat();
        lion.roar();
        lion.sleep();
        System.out.println("\n");
        Snake snake = new Snake();
        snake.eat();
        snake.slither();
        snake.sleep();
    }
}