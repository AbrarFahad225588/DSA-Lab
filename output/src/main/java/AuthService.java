package src.main.java;
import org.mindrot.jbcrypt.BCrypt;
import java.util.List;

public class AuthService {

    private User loggedInUser = null;

    public void register(String username, String password) {
        List<User> users = FileDatabase.loadUsers();

        for (User user : users) {
            if (user.getUsername().equals(username)) {
                System.out.println("Username already exists!");
                return;
            }
        }

        String hashedPassword = BCrypt.hashpw(password, BCrypt.gensalt());
        int newId = users.size() + 1;

        User newUser = new User(newId, username, hashedPassword);
        users.add(newUser);

        FileDatabase.saveUsers(users);
        System.out.println("Registration successful!");
    }

    public void login(String username, String password) {
        List<User> users = FileDatabase.loadUsers();

        for (User user : users) {
            if (user.getUsername().equals(username) &&
                BCrypt.checkpw(password, user.getPassword())) {

                loggedInUser = user;
                System.out.println("Login successful!");
                return;
            }
        }

        System.out.println("Invalid username or password!");
    }

    public void logout() {
        if (loggedInUser != null) {
            System.out.println("Logged out successfully!");
            loggedInUser = null;
        } else {
            System.out.println("No user is logged in!");
        }
    }

    public void protectedAction() {
        if (loggedInUser == null) {
            System.out.println("Access Denied! Please login first.");
            return;
        }

        System.out.println("Welcome " + loggedInUser.getUsername() + " 🔥");
        System.out.println("You accessed a protected resource!");
    }
}
