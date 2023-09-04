import java.util.*;

class Arrays {
    ArrayList<String> list = new ArrayList<>();

    public void add(String color) {
        list.add(color);
    }

    public void display() {
        if (list.isEmpty())
            return;

        System.out.println("Array List is: " + list);
    }

    public void reverseList() {
        if (list.isEmpty())
            return;

        ArrayList<String> reversed = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0; i--)
            reversed.add(list.get(i));

        System.out.println("Reversed list is: " + reversed);
    }

    public void sort() {
        if (list.isEmpty())
            return;

        Collections.sort(list);
        System.out.println("Sorted list is: " + list);
    }

    @SuppressWarnings("unchecked")
    public void cloneList() {
        if (list.isEmpty())
            return;

        ArrayList<String> cloned_list = (ArrayList<String>) list.clone();
        System.out.println("Cloned list is: " + cloned_list);
    }

    public void subArray(int start, int end) {
        if (list.isEmpty())
            return;

        else if (start < 0 || end > list.size()) {
            System.out.println("Out of bounds!");
            return;
        }

        ArrayList<String> subarray = new ArrayList<>(list.subList(start, end));
        System.out.println("Sub Array is: " + subarray);
    }

    public void toArray() {
        if (list.isEmpty())
            return;

        String[] arr = new String[list.size()];
        list.toArray(arr);

        System.out.println("Converted array is: ");
        for (String s : arr)
            System.out.print(s + " ");

        System.out.println();
    }

}

public class Program_6 {
    public static void main(String[] args) {
        Arrays arr = new Arrays();
        Scanner input = new Scanner(System.in);

        int choice, start, end;
        String color;

        System.out.println("""
                1. Add Element
                2. Display List
                3. Reverse List
                4. Sort List
                5. Clone List
                6. Extract SubArray
                7. Convert to Array
                 """);

        while (true) {
            System.out.print("Enter your choice: ");
            choice = input.nextInt();
            switch (choice) {
                case 1 -> {
                    System.out.print("Enter color: ");
                    color = input.next();
                    arr.add(color);
                }
                case 2 -> arr.display();
                case 3 -> arr.reverseList();
                case 4 -> arr.sort();
                case 5 -> arr.cloneList();
                case 6 -> {
                    System.out.println("Enter start and end index (0 indexed): ");
                    start = input.nextInt();
                    end = input.nextInt();
                    arr.subArray(start, end);
                }
                case 7 -> arr.toArray();
                default -> {
                    input.close();
                    System.exit(1);
                }
            }
        }
    }
}