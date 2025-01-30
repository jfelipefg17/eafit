package com.Globant.library.controllers;

import com.Globant.library.entities.Author;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.services.AuthorService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Controller
@RequestMapping("/author")
public class AuthorController {

  @Autowired
  private AuthorService authorService;

  @GetMapping("/register")
  public String authorForm() {
    return "authorForm.html";
  }

  @PostMapping("/registration")
  public String registration (@RequestParam String name, ModelMap model) {
//    System.out.println("Name" + name);

    try {
      authorService.creatAuthor(name);
      model.put("Good", "The Author was successfully uploaded");

    }catch (MyExceptions e) {
      System.out.println(e.getMessage());
      model.put("error", e.getMessage());
      return "authorForm.html";
    }


    return "index.html";
  }

  @GetMapping("/list")
  @Transactional
  public String list(ModelMap modelMap) {
    List<Author> authorList = authorService.searchAllAuthor();

    modelMap.addAttribute("authors", authorList);

    return "authorList.html";
  }
  @GetMapping("/modify/{id}")
  @Transactional
  public String modify(@PathVariable String id, ModelMap modelMap) {
    modelMap.put("author", authorService.getOne(id));

    return "authorModify.html";
  }


  @PostMapping("/modify/{id}")
  @Transactional
  public String modify(@PathVariable String id, String name, ModelMap modelMap) {

    try {
      authorService.modifyAuthor(id,name);

      return "redirect:/author/list";

    } catch (MyExceptions e) {
      modelMap.put("error", e.getMessage());
    }

    return "authorModify.html";

  }
}
