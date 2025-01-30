package com.Globant.library.services;

import com.Globant.library.entities.Publisher;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.repositories.PublisherRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
public class PublisherService {

  @Autowired
  private PublisherRepository publisherRepository;

  @Transactional
  public void createPublisher (String name) throws MyExceptions {

    validator(name);


    Publisher publisher = new Publisher();

    publisher.setName(name);

    publisherRepository.save(publisher);
  }

  public List<Publisher> searchAllPublisher(){

    List<Publisher> publisherList = new ArrayList<>();

    publisherList = publisherRepository.findAll();

    return publisherList;
  }

  public void modifyPublisher(String id, String name ) throws MyExceptions{

    validator(name);


    Optional<Publisher> anw = publisherRepository.findById(id);

    if (anw.isPresent()) {
      Publisher publisher = anw.get();

      publisher.setName(name);

      publisherRepository.save(publisher);
    }
  }
  private void validator( String name) throws MyExceptions {

    if (name == null || name.isEmpty()) {
      throw new MyExceptions("the name cant be null or empty");
    }
  }
}
