package com.Globant.example2.services;

import com.Globant.example2.NewsApplication;
import com.Globant.example2.entities.News;
import com.Globant.example2.exceptions.MyException;
import com.Globant.example2.repositories.NewsRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.when;
import static org.mockito.Mockito.*;

@SpringBootTest
public class newServiceTest {

  @Autowired
  private NewsService newsService;

  @MockBean
  private NewsRepository newsRepository;



//  @Controller
//  @RequestMapping("/news")
//  public class NewsController {
//
//    @Autowired
//    private NewsService newsService;
//
//    @GetMapping("/create")
//    public String createNew(ModelMap modelMap) {
//
//      return "newsForm.html";
//    }


  @Test
  void createNewANDfindById() throws MyException {

//    System.out.println("newsService: " + newsService);

    when(newsRepository.save(any(News.class)))
            .thenAnswer(invocation -> {
              News news = invocation.getArgument(0);
              return news;
            });

    News news = newsService.createNews("Felipeee","felipe se murio");




    //System.out.println(news.getTittle() + " AAAAAAA " + news.getBody());

    assertNotNull(news, "news should not be null");
    assertNotNull(news.getTittle(), "news should not be null");
  assertEquals("felipe se murio", news.getBody());

  }


  @Test
  public void deberiaBuscarUsuarioPorId() {
// Configuración del mock

    News news = new News("felipe","florez");

    when(newsRepository.getById(eq(news.getTittle()))).thenReturn(news);
// Ejecución de la lógica de la clase de servicio
    News news1 = newsService.searchNewsByTittle(news.getTittle());
// Verificación de resultados
    assertNotNull(news1, "the new cant be null");
    assertEquals("felipe", news1.getTittle());
    assertEquals("florez", news1.getBody());
  }

//    @PostMapping("/addNews")
//    public String addNews(@RequestParam String tittle, @RequestParam String body, ModelMap modelMap) throws MyException {
//
//      try {
//
//        newsService.createNews(tittle,body);
//        modelMap.put("Good", "The Author was successfully uploaded");
//      }catch (MyException e){
//
//        System.out.println(e.getMessage());
//        modelMap.put("error", e.getMessage());
//        return "newsForm.html";
//      }
//
//      return "index.html";
//    }






  @Test
  void listNews(){

  }


//    @GetMapping("/newsList")
//    @Transactional
//    public String listNews(ModelMap modelMap) {
//      List<News> newss = newsService.searchAllNews();
//
//      modelMap.addAttribute("newss", newss);
//
//      return "newsList.html";
//    }





  @Test
  void modifyNew(){

  }

//    @GetMapping("/modify/{tittle}")
//    @Transactional
//    public String modifyNews(@PathVariable String tittle, ModelMap modelMap) {
//      System.out.println("Received title: " + tittle);
//      modelMap.put("news", newsService.getOne(tittle));
//
//      return "newsModify.html";
//    }
//
//    @PostMapping("/modify/{tittle}")
//    @Transactional
//    public String addModifyNews(@PathVariable String tittle, String body, ModelMap modelMap) throws MyException {
//
//      try {
//        newsService.updateNews(tittle,body);
//
//        return "redirect:/news/newsList";
//      }catch (MyException e){
//
//        System.out.println(e.getMessage());
//        modelMap.put("error", e.getMessage());
//        return "newsModify.html";
//      }
//
//    }



  @Test
  void deleteNew(){

  }

//    @GetMapping("/delete")
//    public String deleteNews(ModelMap modelMap) {
//
//      List<News> newss = newsService.searchAllNews();
//      modelMap.addAttribute("newss", newss);
//
//
//      return "newsDelete.html";
//    }
//
//    @PostMapping("/delete")
//    @Transactional
//    public String deleteNews(@RequestParam String tittle, ModelMap modelMap) throws MyException {
//
//      try {
//        newsService.deleteNew(tittle);
//
//        return "redirect:/news/newsList";
//      }catch (MyException e){
//
//        System.out.println(e.getMessage());
//        modelMap.put("error", e.getMessage());
//        return "newsDelete.html";
//      }
//
//    }


}
