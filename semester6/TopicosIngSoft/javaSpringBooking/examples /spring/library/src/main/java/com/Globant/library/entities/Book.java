package com.Globant.library.entities;

import org.hibernate.annotations.GenericGenerator;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Book {

  @Id
  private Long isbn;
  private String tittle;
  private Integer numberBooks;
  @Temporal(TemporalType.DATE)
  private Date entryDate;

  @ManyToOne
  private Author author;
  @ManyToOne

  private Publisher publisher;

  public Book() {
  }

  public Book(Long isbn, String tittle, Integer numberBooks, Date entryDate, Author author, Publisher publisher) {
    this.isbn = isbn;
    this.tittle = tittle;
    this.numberBooks = numberBooks;
    this.entryDate = entryDate;
    this.author = author;
    this.publisher = publisher;
  }

  public Long getIsbn() {
    return isbn;
  }

  public void setIsbn(Long isbn) {
    this.isbn = isbn;
  }

  public String getTittle() {
    return tittle;
  }

  public void setTittle(String tittle) {
    this.tittle = tittle;
  }

  public Integer getNumberBooks() {
    return numberBooks;
  }

  public void setNumberBooks(Integer numberBooks) {
    this.numberBooks = numberBooks;
  }

  public Date getEntryDate() {
    return entryDate;
  }

  public void setEntryDate(Date entryDate) {
    this.entryDate = entryDate;
  }

  public Author getAuthor() {
    return author;
  }

  public void setAuthor(Author author) {
    this.author = author;
  }

  public Publisher getPublisher() {
    return publisher;
  }

  public void setPublisher(Publisher publisher) {
    this.publisher = publisher;
  }
}
