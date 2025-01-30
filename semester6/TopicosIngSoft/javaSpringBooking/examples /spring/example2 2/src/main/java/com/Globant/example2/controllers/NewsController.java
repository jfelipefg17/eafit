package com.Globant.example2.controllers;


import com.Globant.example2.entities.News;
import com.Globant.example2.exceptions.MyException;
import com.Globant.example2.services.NewsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Controller
@RequestMapping("/news")
public class NewsController {

  @Autowired
  private NewsService newsService;

  @GetMapping("/create")
  public String createNew(ModelMap modelMap) {

    return "newsForm.html";
  }

  @PostMapping("/addNews")
  public String addNews(@RequestParam String tittle, @RequestParam String body, ModelMap modelMap) throws MyException {

    try {

      newsService.createNews(tittle,body);
      modelMap.put("Good", "The Author was successfully uploaded");
    }catch (MyException e){

      System.out.println(e.getMessage());
      modelMap.put("error", e.getMessage());
      return "newsForm.html";
    }

    return "index.html";
  }




  @GetMapping("/modify/{tittle}")
  @Transactional
  public String modifyNews(@PathVariable String tittle, ModelMap modelMap) {
    System.out.println("Received title: " + tittle);
    modelMap.put("news", newsService.getOne(tittle));

    return "newsModify.html";
  }

  @PostMapping("/modify/{tittle}")
  @Transactional
  public String addModifyNews(@PathVariable String tittle, String body, ModelMap modelMap) throws MyException {

    try {
      newsService.updateNews(tittle,body);

      return "redirect:/news/newsList";
    }catch (MyException e){

      System.out.println(e.getMessage());
      modelMap.put("error", e.getMessage());
      return "newsModify.html";
    }

  }

  @GetMapping("/delete")
  public String deleteNews(ModelMap modelMap) {

    List<News> newss = newsService.searchAllNews();
    modelMap.addAttribute("newss", newss);


    return "newsDelete.html";
  }

  @PostMapping("/delete")
  @Transactional
  public String deleteNews(@RequestParam String tittle, ModelMap modelMap) throws MyException {

    try {
      newsService.deleteNew(tittle);

      return "redirect:/news/newsList";
    }catch (MyException e){

      System.out.println(e.getMessage());
      modelMap.put("error", e.getMessage());
      return "newsDelete.html";
    }

  }





  @GetMapping("/newsList")
  @Transactional
  public String listNews(ModelMap modelMap) {
    List<News> newss = newsService.searchAllNews();

    modelMap.addAttribute("newss", newss);

    return "newsList.html";
  }



}
