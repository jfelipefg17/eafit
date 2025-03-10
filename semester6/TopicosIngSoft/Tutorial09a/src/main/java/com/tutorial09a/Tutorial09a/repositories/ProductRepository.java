package com.tutorial09a.Tutorial09a.repositories;

import com.tutorial09a.Tutorial09a.models.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ProductRepository extends JpaRepository<Product, Long> {
}