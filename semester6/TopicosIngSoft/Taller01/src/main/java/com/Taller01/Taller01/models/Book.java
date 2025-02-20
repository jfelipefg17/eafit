package com.Taller01.Taller01.models;


import jakarta.persistence.Entity;
import jakarta.persistence.PrimaryKeyJoinColumn;

@Entity
public class Book {

    @jakarta.persistence.Id
    @jakarta.persistence.GeneratedValue
    @PrimaryKeyJoinColumn
    private Integer id = 0;

    private String title = "";

    private int stock = 0;

    private double price = 0;

    private String image = "";

    //I change for string, but it will be Author class
    private String author = "";

    //I change for string, but it will be Publisher class
    private String publisher ="";

    //I change for string, but it will be Category class
    private String category = "";

    //I change for string, but it will be Likes class and also a list of that likes
    private Boolean likes;


    public Book() {

    }

    public Book(int id, String title, int stock, double price, String image, String author, String publisher, String category, Boolean likes) {
        this.id = id;
        this.title = title;
        this.stock = stock;
        this.price = price;
        this.image = image;
        this.author = author;
        this.publisher = publisher;
        this.category = category;
        this.likes = likes;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String tittle) {
        this.title = tittle;
    }

    public int getStock(){
        return stock;
    }

    public void setStock(int stock){
        this.stock = stock;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public Boolean getLike() {
        return likes;
    }

    public void setLikes(Boolean likes) {
        this.likes = likes;
    }


    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", tittle='" + title + '\'' +
                ", stock=" + stock +
                ", price=" + price +
                ", image='" + image + '\'' +
                ", author='" + author + '\'' +
                ", publisher='" + publisher + '\'' +
                ", category='" + category + '\'' +
                ", like=" + likes +
                '}';
    }
}

