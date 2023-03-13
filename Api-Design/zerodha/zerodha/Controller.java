package zerodha;

import java.util.HashMap;

/**
 * Represents a Controller class that manages a HashMap of User objects, indexed
 * by their user ID.
 * The Controller class can be used as a centralized access point to manage and
 * retrieve User objects.
 */
public class Controller {
    private static HashMap<String, User> m_users = new HashMap<>();

    /**
     * This method takes a user ID as input and returns the corresponding User
     * object if it exists in the HashMap. If the user ID does not exist, it returns
     * null.
     * 
     * @param userId id of user
     * @return a new user is returned
     */
    public static User getUser(String userId) {
        return m_users.get(userId);
    }

    /**
     * This method adds a new user to the HashMap with the given user ID as the key
     * and the User object as the value.
     * 
     * @param userId id of user
     * @param user   new user to be inserted in
     */
    public static void addUser(String userId, User user) {
        m_users.put(userId, user);
    }
}
