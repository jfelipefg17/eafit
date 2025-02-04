package com.Globant.example2.services;

import com.Globant.example2.entities.News;
import com.Globant.example2.exceptions.MyException;
import com.Globant.example2.repositories.NewsRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


import java.util.List;
import java.util.Optional;

@Service
public class NewsService {

  @Autowired
  private NewsRepository newsRepository;


  @Transactional
  public News createNews(String tittle, String body) throws MyException {

    validator(tittle,body);

    News news = new News(tittle,body);

    return newsRepository.save(news);

  }

  public List<News> searchAllNews(){

    return newsRepository.findAll();
  }

  public News searchNewsByTittle(String tittle) {

    return newsRepository.getById(tittle);
  }

  public void updateNews (String tittle, String body) throws MyException {

    validator(tittle,body);
    System.out.println("Title received: " + tittle);
    Optional<News> anw = newsRepository.findById(tittle);

    if (anw.isPresent()) {

          News news = anw.get();

          news.setBody(body);

          newsRepository.save(news);
    }else {
      throw new MyException("News with title " + tittle + " not found");

    }

  }

  public void deleteNew(String tittle) throws MyException {

    Optional<News> anw = newsRepository.findById(tittle);

    if (anw.isPresent()) {
      newsRepository.deleteById(tittle);
    }else {
      System.out.println(tittle);
      throw new MyException("not exist this new");
    }

  }

  public News getOne(String tittle) {
    News news = newsRepository.getOne(tittle);
    news.getBody();
    return news;
  }

  private void validator( String tittle, String body) throws MyException {

    if (tittle == null || tittle.isEmpty()) {
      throw new MyException("the name cant be null or empty");
    }

    if (body == null || body.isEmpty()) {
      throw new MyException("the name cant be null or empty");
    }
  }




}
