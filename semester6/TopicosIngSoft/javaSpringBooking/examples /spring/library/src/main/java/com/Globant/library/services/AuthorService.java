package com.Globant.library.services;

import com.Globant.library.entities.Author;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.repositories.AuthorRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
public class AuthorService {

  @Autowired
  private AuthorRepository authorRepository;
  @Transactional
  public void creatAuthor (String name) throws MyExceptions{

    validator( name);


    Author author = new Author();

    author.setName(name);

    authorRepository.save(author);
  }

  public List<Author> searchAllAuthor () {

    List<Author> authorList = new ArrayList<>();

    authorList = authorRepository.findAll();

    return authorList;
  }

  public void modifyAuthor(String id, String name) throws MyExceptions{

    validator(name);


    Optional<Author> anw = authorRepository.findById(id);

    if (anw.isPresent()){

      Author author = anw.get();

      author.setName(name);

      authorRepository.save(author);
    }
  }

  public Author getOne(String id) {

    Author author = authorRepository.getOne(id);
    author.getName();
    return author;
  }

  private void validator( String name) throws MyExceptions{

    if (name == null || name.isEmpty()) {
      throw new MyExceptions("the name cant be null or empty");
    }
  }
}
