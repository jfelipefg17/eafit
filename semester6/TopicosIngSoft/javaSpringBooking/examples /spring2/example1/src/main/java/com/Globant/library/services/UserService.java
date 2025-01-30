package com.Globant.library.services;

import com.Globant.library.entities.Image;
import com.Globant.library.entities.User;
import com.Globant.library.enums.Role;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.repositories.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.expression.spel.ast.NullLiteral;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpSession;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
public class UserService implements UserDetailsService {

  @Autowired
  private UserRepository userRepository;

  @Autowired
  private ImageService imageService;

  @Transactional
  public void register(MultipartFile multipartFile, String name, String email, String password1, String password2) throws MyExceptions {

    validator(name, email, password1, password2);

    User user = new User();

    user.setName(name);
    user.setEmail(email);
    user.setPassword(new BCryptPasswordEncoder().encode(password1));
    user.setRole(Role.USER);

    Image image = imageService.safe(multipartFile);

    user.setImage(image);

    userRepository.save(user);
  }

  @Transactional
  public void update(MultipartFile multipartFile, String id, String name, String email, String password1, String password2) throws MyExceptions {

    validator(name, email, password1, password2);

    Optional<User> aws = userRepository.findById(id);

    if (aws.isPresent()) {

      User user = aws.get();

      user.setName(name);
      user.setEmail(email);
      user.setPassword(new BCryptPasswordEncoder().encode(password1));
      user.setRole(Role.USER);

      String idImage = null;

      if (user.getImage() != null) {
        idImage = user.getImage().getId();
      }

      Image image = imageService.update(multipartFile, idImage);

      user.setImage(image);


      userRepository.save(user);

    }


  }

  public User getOne(String id){
    return userRepository.getOne(id);
  }


  private void validator(String name, String email, String password1, String password2) throws MyExceptions {

    if (name.isEmpty() || name == null) {
      throw new MyExceptions("the name cant be nuul or empty");
    }
    if (email.isEmpty() || email == null) {
      throw new MyExceptions("the email cant be null or empty ");
    }
    if (password1.isEmpty() || password1 == null || password1.length() <=5) {
      throw new MyExceptions("the first password can not be null or empty and has to have more than 5 digits");
    }
    if (password2.isEmpty() || password2 == null || password2.length() <=5) {
      throw new MyExceptions("the second password can not be null or empty and has to have more than 5 digits");
    }
    if( !password1.equals(password2)) {
      throw new MyExceptions("the passwords are not equal ");
    }
  }

  @Override
  public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
    User userEntity = userRepository.findByEmail(email);

    if (userEntity != null) {

      List<GrantedAuthority>  permissions = new ArrayList<>();
      GrantedAuthority p = new SimpleGrantedAuthority("ROLE_" + userEntity.getRole().toString());
      permissions.add(p);

      ServletRequestAttributes attributes = (ServletRequestAttributes) RequestContextHolder.currentRequestAttributes();

      HttpSession session = attributes.getRequest().getSession(true);

      session.setAttribute("userSession", userEntity);

      // i have to called like this because the class user of user details is called like user that is my entity and the software got confuse with that
      return new org.springframework.security.core.userdetails.User(userEntity.getEmail(), userEntity.getPassword(),permissions);

    } else {
      throw new UsernameNotFoundException("User was not found with the email: " + email);
    }


  }
}
