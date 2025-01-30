package com.Globant.library.repositories;

import com.Globant.library.entities.Book;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BookRepository extends JpaRepository<Book, Long> {

  @Query("SELECT L FROM Book L WHERE L.tittle = :tittle")
  public Book searchBookByTittle(@Param("tittle") String tittle);

  @Query("SELECT L FROM Book L WHERE L.author.name = :name")
  public List<Book> searchBookByNameAuthor(@Param("name") String name);

}
