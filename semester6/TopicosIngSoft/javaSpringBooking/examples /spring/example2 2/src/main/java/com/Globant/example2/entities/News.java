package com.Globant.example2.entities;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class News {

  @Id
  private String tittle;
  private String body;

  public News() {

  }

  public News(String tittle, String body) {
    this.tittle = tittle;
    this.body = body;
  }

  public String getTittle() {
    return tittle;
  }

  public void setTittle(String tittle) {
    this.tittle = tittle;
  }

  public String getBody() {
    return body;
  }

  public void setBody(String body) {
    this.body = body;
  }
}
