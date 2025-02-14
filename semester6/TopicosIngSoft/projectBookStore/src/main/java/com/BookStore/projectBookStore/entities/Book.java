package com.BookStore.projectBookStore.entities;

import jakarta.persistence.Entity;
import jakarta.persistence.PrimaryKeyJoinColumn;

@Entity
@jakarta.persistence.Table(name = "books")
public class Book {

    @jakarta.persistence.Id
    @jakarta.persistence.GeneratedValue
    @PrimaryKeyJoinColumn
    private int id = 0;

    @jakarta.persistence.Column(nullable = false)
    private String title = "";

    @jakarta.persistence.Column(nullable = false)
    private String author = "";

    private String genre = "";

    private int year = 0;

    private int pages = 0;

    @jakarta.persistence.Column(unique = true, nullable = false)
    private String isbn = "";

    private String cover = "";

    public Book()
    {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getPages() {
        return pages;
    }

    public void setPages(int pages) {
        this.pages = pages;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getCover() {
        return cover;
    }

    public void setCover(String cover) {
        this.cover = cover;
    }
}
