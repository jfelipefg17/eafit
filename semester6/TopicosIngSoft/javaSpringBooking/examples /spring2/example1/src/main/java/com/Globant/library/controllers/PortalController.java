package com.Globant.library.controllers;

import com.Globant.library.entities.User;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.services.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpSession;

@Controller
@RequestMapping("/")
public class PortalController {

  @Autowired
  private UserService userService;

  @GetMapping("/")
  public String index() {
    return "entry.html";
  }


  @GetMapping("/register")
  public String register() {
    return "register.html";
  }

  @PostMapping("/register")
  public String register(@RequestParam String name, @RequestParam String email, @RequestParam String password1, @RequestParam String password2, ModelMap modelMap, MultipartFile multipartFile) throws MyExceptions{

    try {
     userService.register(multipartFile, name, email, password1, password2);
     modelMap.put("Good","User Successfully Registered");

     return "index1.html";

   } catch (MyExceptions e) {

     modelMap.put("Error", e.getMessage());
      modelMap.put("name", name);
      modelMap.put("email",email);

     return "register.html";

   }

  }

  @GetMapping("/login")
  public String login(@RequestParam(required = false) String error, ModelMap modelMap){
    if (error != null) {
      modelMap.put("Error","Email Or Password could be wrong");
    }
    return "login.html";
  }

  @PreAuthorize("hasAnyRole('ROLE_USER', 'ROLE_ADMIN')")
  @GetMapping("/start")
  public String start(HttpSession session) {

    User logUser = (User) session.getAttribute("userSession");

    if (logUser.getRole().toString().equals("ADMIN")) {
      return "redirect:/admin/dashboard";
    } else {
      return "index1.html";
    }
  }

  @PreAuthorize("hasAnyRole('ROLE_USER', 'ROLE_ADMIN')")
  @GetMapping("/profile")
  public String profile(ModelMap modelMap, HttpSession httpSession) {

    User user = (User) httpSession.getAttribute("userSession");
    modelMap.put("user", user);
    return "userModify.html";
  }


  @PreAuthorize("hasAnyRole('ROLE_USER', 'ROLE_ADMIN')")
  @PostMapping("/profile/{id}")
  public String update(MultipartFile multipartFile, @PathVariable String id, @RequestParam String name,@RequestParam String email, @RequestParam String password1, @RequestParam String password2, ModelMap modelMap) {


    try {
      userService.update(multipartFile,id,name,email,password1,password2);

      modelMap.put("Good", "User Update");

      return "index1.html";

    }catch (MyExceptions exceptions) {

      modelMap.put("Error", exceptions.getMessage());

      return "userModify.html";
    }
  }


//  @PreAuthorize("hasRole('ROLE_USER')")
//  @GetMapping("/start")
//  public String start() {
//    return "index1.html";
//  }


}
