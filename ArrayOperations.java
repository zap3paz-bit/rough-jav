import java.util.Scanner;

class ArrayOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] a = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println("\n1. Sum and Average");
        System.out.println("2. Search an element");
        System.out.println("3. Sum of even numbers");
        System.out.println("4. Reverse array");
        System.out.println("5. Count prime numbers");
        System.out.println("6. Second highest element");
        System.out.println("7. Sort increasing and decreasing");

        System.out.print("Enter your choice: ");
        int ch = sc.nextInt();

        switch (ch) {

            case 1:
                int sum = 0;

                for (int i = 0; i < n; i++) {
                    sum = sum + a[i];
                }

                double avg = (double) sum / n;

                System.out.println("Sum = " + sum);
                System.out.println("Average = " + avg);
                break;

            case 2:
                System.out.print("Enter element to search: ");
                int x = sc.nextInt();
                boolean found = false;

                for (int i = 0; i < n; i++) {
                    if (a[i] == x) {
                        System.out.println("Element found at position " + (i + 1));
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    System.out.println("Element not found");
                }
                break;

            case 3:
                int evenSum = 0;

                for (int i = 0; i < n; i++) {
                    if (a[i] % 2 == 0) {
                        evenSum = evenSum + a[i];
                    }
                }

                System.out.println("Sum of even numbers = " + evenSum);
                break;

            case 4:
                int temp;

                for (int i = 0; i < n / 2; i++) {
                    temp = a[i];
                    a[i] = a[n - 1 - i];
                    a[n - 1 - i] = temp;
                }

                System.out.println("Reversed array:");
                for (int i = 0; i < n; i++) {
                    System.out.print(a[i] + " ");
                }
                break;

            case 5:
                int count = 0;

                for (int i = 0; i < n; i++) {
                    int num = a[i];
                    boolean prime = true;

                    if (num < 2) {
                        prime = false;
                    } else {
                        for (int j = 2; j < num; j++) {
                            if (num % j == 0) {
                                prime = false;
                                break;
                            }
                        }
                    }

                    if (prime) {
                        count++;
                    }
                }

                System.out.println("Prime numbers = " + count);
                break;

            case 6:
                int highest = a[0];
                int second = Integer.MIN_VALUE;

                for (int i = 1; i < n; i++) {
                    if (a[i] > highest) {
                        second = highest;
                        highest = a[i];
                    } else if (a[i] > second && a[i] != highest) {
                        second = a[i];
                    }
                }

                if (second == Integer.MIN_VALUE) {
                    System.out.println("Second highest does not exist");
                } else {
                    System.out.println("Second highest = " + second);
                }
                break;

            case 7:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (a[i] > a[j]) {
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }

                System.out.println("Increasing order:");
                for (int i = 0; i < n; i++) {
                    System.out.print(a[i] + " ");
                }

                System.out.println();

                System.out.println("Decreasing order:");
                for (int i = n - 1; i >= 0; i--) {
                    System.out.print(a[i] + " ");
                }
                break;

            default:
                System.out.println("Invalid choice");
        }

        sc.close();
    }
}