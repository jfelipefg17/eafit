package com.example.demo.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import jakarta.validation.Valid;

import java.util.*;
import com.example.demo.controllers.ProductForm;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

@Controller
@Validated
public class ProductController {

    private static final List<Map<String, Object>> products = new ArrayList<>(List.of(
            Map.of("id", "1", "name", "TV", "description", "Best TV", "price", 500),
            Map.of("id", "2", "name", "iPhone", "description", "Best iPhone", "price", 100),
            Map.of("id", "3", "name", "Chromecast", "description", "Best Chromecast", "price", 500),
            Map.of("id", "4", "name", "Glasses", "description", "Best Glasses", "price", 300)
    ));


    @GetMapping("/products")
    public String index(Model model) {
        model.addAttribute("title", "Products - Online Store");
        model.addAttribute("subtitle", "List of products");
        model.addAttribute("products", products);
        return "product/index";
    }

    @GetMapping("/products/create")
    public String create(Model model) {
        model.addAttribute("title", "Create Product");

            model.addAttribute("productForm", new ProductForm());
        return "product/create";
}


    @PostMapping("/products/save")
    public String save(@ModelAttribute("productForm") @Valid ProductForm productForm,
                       BindingResult result,
                       Model model,
                       RedirectAttributes redirectAttributes) {
        System.out.println("Errores: " + result.getAllErrors()); // 🔍 Imprime errores en la consola
        if (result.hasErrors()) {
            model.addAttribute("title", "Create Product");
            return "products/form"; // Asegúrate de que sea la vista correcta del formulario
        }

        // Simulación de guardar el producto en la lista (sin persistencia en DB)
        Map<String, Object> newProduct = new HashMap<>();
        newProduct.put("id", String.valueOf(products.size() + 1));
        newProduct.put("name", productForm.getName());
        newProduct.put("description", "Price: $" + productForm.getPrice());
        products.add(newProduct);

        // Agrega un mensaje de éxito
        redirectAttributes.addFlashAttribute("good", "The product was saved successfully!");

        return "redirect:/products";
    }



    @GetMapping("/products/{id}")
    public String show(@PathVariable String id, Model model) {
        int productId = Integer.parseInt(id) - 1;

        if (productId < 0) {
            return "redirect:/";
        }

        Map<String, Object> product = products.get(productId);
        model.addAttribute("name", product.get("name") + " - Online Store");
        model.addAttribute("subtitle", product.get("description") + " - Product Information");
        model.addAttribute("product", product);
        return "product/show";
    }
}

