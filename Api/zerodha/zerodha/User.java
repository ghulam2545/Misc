package zerodha;

/**
 * The purpose of this class is to represent a user of the program. It allows
 * the user to be identified by a unique identifier that can be used to
 * associate the user with other objects or data structures in the program.
 */
public class User {
    private String m_userId;
    // more ...

    /**
     * This takes one parameter "userId" of type String, and it initializes
     * new user.
     * 
     * @param userId ID of user
     */
    public User(String userId) {
        this.m_userId = userId;
    }

    /**
     * Ask for a User userId
     * 
     * @return user ID is returned
     */
    public String getUserId() {
        return this.m_userId;
    }
}
