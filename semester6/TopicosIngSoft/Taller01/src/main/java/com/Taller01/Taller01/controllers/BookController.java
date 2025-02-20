package com.Taller01.Taller01.controllers;

import com.Taller01.Taller01.models.Book;
import com.Taller01.Taller01.services.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

//Book controller
@Controller
@RequestMapping("/book")
public class BookController {

    @Autowired
    private BookService bookService;


    @GetMapping("/formBook")
    public String bookForm(ModelMap modelMap) {

        return "create";

    }
    //Create a book
    @PostMapping("/createBook")
    public String createBook ( @RequestParam String title, @RequestParam int stock, @RequestParam double price, @RequestParam String image, @RequestParam String author, @RequestParam String publisher, @RequestParam String category, @RequestParam boolean likes, ModelMap modelMap) {

        try {
            bookService.createBook( title, stock,price, image, author, publisher, category, likes);
            modelMap.put("success", "The Book was successfully uploaded");

        }catch (Exception e){
            System.out.println(e.getMessage());
            modelMap.put("error", e.getMessage());

            return "redirect:/book/formBook";
        }
        return "redirect:/book/listBooks";
    }


    //Read-List the books
    @GetMapping("/listBooks")
    public String listBooks(ModelMap modelMap) {

        try {
            List<Book> books = bookService.searchAllBook();
            modelMap.addAttribute("books", books);

            return "listBooks";
        }catch (Exception e){
            System.out.println(e.getMessage());
            modelMap.put("error", e.getMessage());
        }
        return "index";
    }

    //Read-List a specific book
    @GetMapping("/listBook")
    public String listBook(@RequestParam Integer id , ModelMap modelMap) {

        try {
            Book book = bookService.findById(id);
            modelMap.addAttribute("book", book);

            return "book";
        }catch (Exception e){
            System.out.println(e.getMessage());
            modelMap.put("error", e.getMessage());
        }
        return "listBooks";
    }


    //Update-Modify a book
    @PostMapping("/modifyBook")
    public String modifyBook (@RequestParam Integer id , @RequestParam String title, @RequestParam int stock, @RequestParam double price, @RequestParam String image, @RequestParam String author, @RequestParam String publisher, @RequestParam String category, @RequestParam boolean likes, ModelMap modelMap) {

        try {
            bookService.modifyBook( id, title, stock,price, image, author, publisher, category,likes);
            modelMap.put("success", "The book was successfully modified");

        }catch (Exception e){
            System.out.println(e.getMessage());
            modelMap.put("error", e.getMessage());

            return "modify";
        }
        return "redirect:/book/listBooks";
    }




    //Delete a book
    @PostMapping("/deleteBook")
    public String deleteBook(@RequestParam Integer id, ModelMap modelMap) {

        try {
            bookService.deleteBook(id);
            modelMap.put("success", "The book was successfully deleted.");

        }catch (Exception e){
            System.out.println(e.getMessage());
            modelMap.put("error", e.getMessage());
            return "listBooks";
        }
        return "redirect:/book/listBooks";
    }


}
