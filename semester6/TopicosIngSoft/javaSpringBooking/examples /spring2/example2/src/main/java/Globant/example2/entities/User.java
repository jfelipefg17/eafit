package Globant.example2.entities;

import Globant.example2.enums.Role;
import Globant.example2.services.UserService;
//import lombok.*;

import javax.persistence.*;

@Entity
//@Getter @Setter
//@ToString
//@NoArgsConstructor @AllArgsConstructor
//@Data
public class User {


  @Id
  @GeneratedValue(generator = "uuid")
  private String id;
  private String userName;
  private String password;
  private String email;

  @Enumerated(EnumType.STRING)
  private Role role;

  public User(){

  }
  public User(String id, String userName, String password, String email, Role role) {
    this.id = id;
    this.userName = userName;
    this.password = password;
    this.email = email;
    this.role = role;
  }

  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getUserName() {
    return userName;
  }

  public void setUserName(String userName) {
    this.userName = userName;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public Role getRole() {
    return role;
  }

  public void setRole(Role role) {
    this.role = role;
  }



}
