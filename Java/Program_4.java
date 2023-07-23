import java.util.Scanner;

class DemonetizationException extends Exception {
    private int amount;

    public DemonetizationException(int amount) {
        this.amount = amount;
    }

    public String getMessage() {
        return "Deposit of Old currency of Rs" + amount + " crosses Rs. 5,000 and cannot be Deposited ";
    }
}

class Account {
    private static final int MIN_BALANCE = 500;
    private int balance;

    public Account() {
        balance = MIN_BALANCE;
    }

    public void deposit(int amount, String currencyType) {
        String curr = currencyType.toUpperCase();
        if (curr.equals("OLD") && amount > 5000) {
            try {
                throw new DemonetizationException(amount);
            } catch (DemonetizationException e) {
                System.out.println(e.getMessage());
                return;
            }
        }
        balance += amount;
        System.out.println("Deposit successful!");
    }

    public void currBalance() {
        System.out.println("Current balance: Rs" + balance);
    }

    public void withdraw(int amount) {
        if (balance - amount < MIN_BALANCE) {
            System.out.println("Insufficient balance!");
            return;
        }
        balance -= amount;
        System.out.println("Withdrawal successful!");
    }
}

class Program_4 {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        Account acc = new Account();
        while (true) {
            System.out.println("1.Deposit\n2.Current bal\n3.Withdraw\n4.Exit\nEnter your choice: ");
            int ch = inp.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter the amount to be deposited");
                    int amount = inp.nextInt();
                    System.out.println("Enter amount type");
                    String type = inp.next();
                    acc.deposit(amount, type);
                    break;
                case 2:
                    acc.currBalance();
                    break;
                case 3:
                    System.out.println("Enter amount to be withdrawn: ");
                    int amount1 = inp.nextInt();
                    acc.withdraw(amount1);
                    break;
                case 4:
                    System.exit(0);
            }
        }
    }
}