package Globant.example2.services;

import Globant.example2.entities.User;
import Globant.example2.repositories.UserRepository;
import org.apache.coyote.http11.HttpOutputBuffer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.servlet.http.HttpSession;
import java.util.ArrayList;
import java.util.List;


@Service
public class UserService implements UserDetailsService {

  @Autowired
  private UserRepository userRepository;

  @Override
  public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
//    User user = userRepository.findUserByEmail(email);
//
//    if (user != null ) {
//      List<GrantedAuthority> permissions = new ArrayList<>();
//
//      GrantedAuthority p = new SimpleGrantedAuthority("ROLE_" + user.getRole().toString());
//      permissions.add(p);
//
//      ServletRequestAttributes attributes =  (ServletRequestAttributes) RequestContextHolder.currentRequestAttributes();
//
//      HttpSession session = attributes.getRequest().getSession(true);
//
//      session.setAttribute("user", user);
//
//      return new User(user.getEmail(), user.getPassword(), permissions);//TODO make constructor for this or what ?
//    }

    return null;


  }
}
