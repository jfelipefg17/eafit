package com.Globant.library.entities;

import org.hibernate.annotations.GenericGenerator;
import org.hibernate.annotations.Loader;

import javax.persistence.*;

@Entity
public class Image {

  @Id
  @GeneratedValue(generator = "uuid")
  @GenericGenerator(name = "uuid", strategy = "uuid2")
  private String id;

  private String mime;

  private String name;

  @Lob @Basic(fetch = FetchType.LAZY)
  private byte[] content;

  public Image(){

  }

  public Image(String id, String mime, String name, byte[] content) {
    this.id = id;
    this.mime = mime;
    this.name = name;
    this.content = content;
  }

  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getMime() {
    return mime;
  }

  public void setMime(String mime) {
    this.mime = mime;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public byte[] getContent() {
    return content;
  }

  public void setContent(byte[] content) {
    this.content = content;
  }
}
