package com.Globant.library.controllers;

import com.Globant.library.entities.Author;
import com.Globant.library.entities.Book;
import com.Globant.library.entities.Publisher;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.services.AuthorService;
import com.Globant.library.services.BookService;
import com.Globant.library.services.PublisherService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@Controller
@RequestMapping("/book")
public class BookController {

  @Autowired
  private BookService bookService;
  @Autowired
  private AuthorService authorService;
  @Autowired
  private PublisherService publisherService;


  @GetMapping("/register")
  public String bookForm(ModelMap modelMap) {

    List<Author> authors = authorService.searchAllAuthor();
    List<Publisher> publishers = publisherService.searchAllPublisher();

    modelMap.addAttribute("authors", authors);
    modelMap.addAttribute("publishers", publishers);


    return "bookForm.html";

  }

  @PostMapping("/registration")
  public String registration (@RequestParam(required = false) Long isbn , @RequestParam String tittle, @RequestParam(required = false) Integer numberBook, @RequestParam String idAuthor, @RequestParam String idPublisher, ModelMap modelMap) {

    try {

      bookService.createBook(isbn,tittle,numberBook,idAuthor,idPublisher);
      modelMap.put("Good", "The Book was successfully uploaded");

    }catch (MyExceptions e){

      List<Author> authors = authorService.searchAllAuthor();
      List<Publisher> publishers = publisherService.searchAllPublisher();

      modelMap.addAttribute("authors", authors);
      modelMap.addAttribute("publishers", publishers);


      System.out.println(e.getMessage());
      modelMap.put("Error", e.getMessage());

      return "bookForm.html";
    }

    return "index1.html";
  }
  @PreAuthorize("hasAnyRole('ROLE_USER', 'ROLE_ADMIN')")
  @GetMapping("/list")
  public String list(ModelMap modelMap) {
    List<Book> books = bookService.searchAllBook();

    modelMap.addAttribute("books", books);

    return "bookList.html";
  }
}
