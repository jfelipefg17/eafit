package com.Workshop.Tutorial_Springboot_modelos.repositories;

import com.Workshop.Tutorial_Springboot_modelos.models.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ProductRepository extends JpaRepository<Product, Long> {
}

