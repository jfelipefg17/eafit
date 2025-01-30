package com.Globant.library.services;

import com.Globant.library.entities.Author;
import com.Globant.library.entities.Book;
import com.Globant.library.entities.Publisher;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.repositories.AuthorRepository;
import com.Globant.library.repositories.BookRepository;
import com.Globant.library.repositories.PublisherRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Optional;

@Service
public class BookService {

  @Autowired
  private BookRepository bookRepository;
  @Autowired
  private AuthorRepository authorRepository;
  @Autowired
  private PublisherRepository publisherRepository;

  @Transactional
  public void createBook(Long isbn, String tittle, Integer numberBooks, String idAuthor, String idPublisher) throws MyExceptions {

    validator(isbn, tittle, numberBooks, idAuthor, idPublisher);

    Author author = authorRepository.findById(idAuthor).get();
    Publisher publisher = publisherRepository.findById(idPublisher).get();

    Book book = new Book();

    book.setIsbn(isbn);
    book.setTittle(tittle);
    book.setNumberBooks(numberBooks);
    book.setEntryDate(new Date());
    book.setAuthor(author);
    book.setPublisher(publisher);

    bookRepository.save(book);
  }

  public List<Book>  searchAllBook(){

    List<Book> bookList = new ArrayList<>();

    bookList = bookRepository.findAll();

    return bookList;
  }

  public void modifyBook (Long isbn, String tittle, Integer numberBooks, String idAuthor, String idPublisher) throws MyExceptions{

    validator(isbn, tittle, numberBooks, idAuthor, idPublisher);

    //Book book = bookRepository.findById(isbn).get();

    Optional<Book> anwB = bookRepository.findById(isbn);
    Optional<Author> anwA = authorRepository.findById(idAuthor);
    Optional<Publisher> anwP = publisherRepository.findById(idPublisher);

    Author author = new Author();
    Publisher publisher = new Publisher();

    if (anwA.isPresent()){

      author = anwA.get();
    }

    if (anwP.isPresent()){

      publisher = anwP.get();
    }

    if (anwB.isPresent()) {

      Book book = anwB.get();

      book.setTittle(tittle);
      book.setNumberBooks(numberBooks);
      book.setAuthor(author);
      book.setPublisher(publisher);

      bookRepository.save(book);

    }
  }

  private void validator (Long isbn, String tittle, Integer numberBooks, String idAuthor, String idPublisher) throws MyExceptions {
    if (isbn == null ) {
      throw new MyExceptions("The isbn cant be null");
    }

    if (tittle == null || tittle.isEmpty()) {
      throw new MyExceptions("the tittle cant be null or empty");
    }
    if (numberBooks == null) {
      throw new MyExceptions("The numberBooks cant be null");
    }

    if (idAuthor == null || idAuthor.isEmpty()) {
      throw new MyExceptions("the Author cant be null or empty");
    }
    if (idPublisher == null || idPublisher.isEmpty()) {
      throw new MyExceptions("the Publisher cant be null or empty");
    }
  }
}
