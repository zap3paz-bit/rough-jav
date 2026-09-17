import java.util.Scanner;

public class Sales {
    public static void main(String[] args) {
        Demo d = new Demo();
        d.fun();
    }
}

class Commission {
    double sales;

    Commission(double s) {
        sales = s;
    }

    double commission() {
        return sales / 100;
    }
}

class Demo {
    void fun() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter sales: ");
        double s = sc.nextDouble();

        if (s < 0) {
            System.out.println("Invalid Input");
        } else {
            Commission c = new Commission(s);
            double k = c.commission();
            System.out.println("Commission:" + k);
        }

        sc.close();
    }
}