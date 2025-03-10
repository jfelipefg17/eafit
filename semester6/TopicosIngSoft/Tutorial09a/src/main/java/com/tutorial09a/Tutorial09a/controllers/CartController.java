package com.tutorial09a.Tutorial09a.controllers;

import com.tutorial09a.Tutorial09a.models.Product;
import com.tutorial09a.Tutorial09a.repositories.ProductRepository;
import jakarta.servlet.http.HttpSession;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

@Controller
@RequestMapping("/cart")
public class CartController {

    private final ProductRepository productRepository;

    public CartController(ProductRepository productRepository) {
        this.productRepository = productRepository;
    }

    @GetMapping
    public String index(HttpSession session, Model model) {
        List<Product> products = productRepository.findAll();

        Map<Long, Product> cartProducts = (Map<Long, Product>) session.getAttribute("cart_product_data");
        if (cartProducts == null) {
            cartProducts = new HashMap<>();
        }

        model.addAttribute("title", "Cart - Online Store");
        model.addAttribute("subtitle", "Shopping Cart");
        model.addAttribute("products", products);
        model.addAttribute("cartProducts", cartProducts);
        return "cart/index";
    }

    @GetMapping("/add/{id}")
    public String add(@PathVariable Long id, HttpSession session) {
        Optional<Product> product = productRepository.findById(id);

        if (product.isPresent()) {
            Map<Long, Product> cartProducts = (Map<Long, Product>) session.getAttribute("cart_product_data");
            if (cartProducts == null) {
                cartProducts = new HashMap<>();
            }

            cartProducts.put(id, product.get());
            session.setAttribute("cart_product_data", cartProducts);
        }

        return "redirect:/cart";
    }

    @GetMapping("/removeAll")
    public String removeAll(HttpSession session) {
        session.removeAttribute("cart_product_data");
        return "redirect:/cart";
    }
}
