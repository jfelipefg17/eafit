package com.Globant.library.controllers;

import com.Globant.library.entities.Author;
import com.Globant.library.entities.Publisher;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.services.PublisherService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.core.parameters.P;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
@RequestMapping("/publisher")
public class PublisherController {

  @Autowired
  private PublisherService publisherService;

  @GetMapping("/register")
  public String publisherForm(){
    return "publisherForm.html";
  }

  @PostMapping("registration")
  public String registration(@RequestParam String name, ModelMap model) {

    try {
      publisherService.createPublisher(name);
      model.put("Good", "The Publisher was successfully uploaded");
    }catch (MyExceptions e){
      System.out.println(e.getMessage());
      model.put("Error", e.getMessage());

      return "publisherForm.html";
    }

    return "index1.html";
  }

  @PreAuthorize("hasAnyRole('ROLE_USER', 'ROLE_ADMIN')")
  @GetMapping("/list")
  @Transactional
  public String list(ModelMap modelMap) {
    List<Publisher> publisherList = publisherService.searchAllPublisher();

    modelMap.addAttribute("publishers", publisherList);

    return "publisherList.html";
  }
}
