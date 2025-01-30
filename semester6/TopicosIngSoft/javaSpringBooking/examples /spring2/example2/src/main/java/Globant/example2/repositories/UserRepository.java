package Globant.example2.repositories;

import Globant.example2.entities.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, String> {

  public User findUserByEmail(String email);
}
