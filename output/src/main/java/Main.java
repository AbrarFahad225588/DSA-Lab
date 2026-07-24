package src.main.java;
import java.util.Scanner;
 

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        AuthService authService = new AuthService();

        while (true) {
            System.out.println("\n===== MENU =====");
            System.out.println("1. Register");
            System.out.println("2. Login");
            System.out.println("3. Access Protected Resource");
            System.out.println("4. Logout");
            System.out.println("5. Exit");

            System.out.print("Choose option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Username: ");
                    String regUser = scanner.nextLine();
                    System.out.print("Password: ");
                    String regPass = scanner.nextLine();
                    authService.register(regUser, regPass);
                    break;

                case 2:
                    System.out.print("Username: ");
                    String logUser = scanner.nextLine();
                    System.out.print("Password: ");
                    String logPass = scanner.nextLine();
                    authService.login(logUser, logPass);
                    break;

                case 3:
                    authService.protectedAction();
                    break;

                case 4:
                    authService.logout();
                    break;

                case 5:
                    System.out.println("Goodbye!");
                    return;

                default:
                    System.out.println("Invalid option!");
            }
        }
    }
}
