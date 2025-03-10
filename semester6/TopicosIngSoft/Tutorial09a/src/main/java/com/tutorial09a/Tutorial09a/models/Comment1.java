package com.tutorial09a.Tutorial09a.models;

import jakarta.persistence.*;

@Entity
@Table(name = "comments")
public class Comment1 {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String text;

    @ManyToOne
    @JoinColumn(name = "product_id")
    private Product product;

    public Comment1() {
    }

    public Comment1(String text, Product product) {
        this.text = text;
        this.product = product;
    }

    public Long getId() {
        return id;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public Product getProduct() {
        return product;
    }

    public void setProduct(Product product) {
        this.product = product;
    }
}

