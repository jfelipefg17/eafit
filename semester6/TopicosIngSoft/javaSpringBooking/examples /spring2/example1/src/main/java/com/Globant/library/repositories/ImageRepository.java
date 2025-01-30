package com.Globant.library.repositories;

import com.Globant.library.entities.Image;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import org.springframework.web.bind.annotation.RequestMapping;

@Repository
public interface ImageRepository extends JpaRepository<Image, String > {
}
