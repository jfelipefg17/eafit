package com.Workshop.Tutorial_Springboot_modelos.controllers;

import com.Workshop.Tutorial_Springboot_modelos.models.Comment;
import com.Workshop.Tutorial_Springboot_modelos.models.Product;
import com.Workshop.Tutorial_Springboot_modelos.repositories.CommentRepository;
import com.Workshop.Tutorial_Springboot_modelos.repositories.ProductRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.List;
import java.util.Optional;

@Controller
public class ProductController {

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private CommentRepository commentRepository;

    @GetMapping("/products")
    public String index(Model model) {
        List<Product> products = productRepository.findAll();
        model.addAttribute("title", "Products - Online Store");
        model.addAttribute("subtitle", "List of products");
        model.addAttribute("products", products);
        return "product/index"; // Retorna la vista product/index.html (Thymeleaf)
    }

    @GetMapping("/products/{id}")
    public String show(@PathVariable("id") Long id, Model model) {
        Product product = productRepository.findById(id)
                .orElseThrow(() -> new RuntimeException("Product not found"));
        model.addAttribute("title", product.getName() + " - Online Store");
        model.addAttribute("subtitle", product.getName() + " - Product information");
        model.addAttribute("product", product);
        return "product/show"; // Retorna la vista product/show.html (Thymeleaf)
    }

    @GetMapping("/products/create")
    public String createProductForm(Model model) {
        model.addAttribute("product", new Product());
        return "product/create";
    }

    @PostMapping("/products")
    public String save(Product product) {
        // Validaciones mínimas
        if (product.getName() == null || product.getName().isEmpty() ||
                product.getPrice() == null) {
            throw new RuntimeException("Name and Price are required");
        }
        productRepository.save(product);
        return "redirect:/products";
    }

    @PostMapping("/products/{id}/comments")
    public String addComment(@PathVariable Long id, @RequestParam String description, RedirectAttributes redirectAttributes) {
        Optional<Product> optionalProduct = productRepository.findById(id);

        if (optionalProduct.isPresent()) {
            Product product = optionalProduct.get();
            Comment comment = new Comment(description, product);

            commentRepository.save(comment);

            redirectAttributes.addFlashAttribute("successMessage", "Comentario agregado exitosamente");

            return "redirect:/products/" + id;
        } else {
            redirectAttributes.addFlashAttribute("errorMessage", "Producto no encontrado");
            return "redirect:/products";
        }
    }

}
