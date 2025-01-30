package com.Globant.library.services;

import com.Globant.library.entities.Image;
import com.Globant.library.exceptions.MyExceptions;
import com.Globant.library.repositories.ImageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.Optional;

@Service
public class ImageService {

  @Autowired
  private ImageRepository imageRepository;

  public Image safe(MultipartFile multipartFile) throws MyExceptions {
    if (multipartFile != null) {
      try {

        Image image = new Image();

        image.setMime(multipartFile.getContentType());
        image.setName(multipartFile.getName());
        image.setContent(multipartFile.getBytes());

        return imageRepository.save(image);

      } catch (Exception e){
        System.err.println(e.getMessage());
      }
    }
    return null;
  }


  public Image update(MultipartFile multipartFile, String id) throws MyExceptions{

    if (multipartFile != null) {
      try {

        Image image = new Image();

        if (id != null){

          Optional<Image> aws = Optional.of(imageRepository.getById(id));

          if (aws.isPresent()) {

            image = aws.get();

          }
        }

        image.setMime(multipartFile.getContentType());
        image.setName(multipartFile.getName());
        image.setContent(multipartFile.getBytes());

        return imageRepository.save(image);

      } catch (Exception e){
        System.err.println(e.getMessage());
      }
    }
    return null;

  }




}
