# Library Management System

## Overview
This project is a **Library Management System** developed using **Java Spring Boot**, **MySQL**, **JPA (Java Persistence API)**, and **Hibernate**. The frontend utilizes **Thymeleaf** to render dynamic content. Security is handled with **Spring Security**, which manages user authentication and authorization.

## Technologies Used
- **Java 17+**
- **Spring Boot**
- **Spring Security**
- **Spring Data JPA**
- **Hibernate**
- **Thymeleaf**
- **MySQL**
- **BCrypt for password encryption**
- **Maven for dependency management**
- **Docker & Kubernetes (future implementation)**

## Architecture
This project follows a **monolithic architecture** but is designed with future **microservices** in mind. It implements the **MVC (Model-View-Controller)** pattern:
- **Model**: Entities representing the database schema (e.g., User, Book, Author, Publisher, Image).
- **View**: Thymeleaf templates for rendering the UI.
- **Controller**: Handles HTTP requests and directs business logic.
- **Service Layer**: Business logic is separated from controllers.
- **Repository Layer**: Uses Spring Data JPA for database operations.

## User Roles and Security
The system has two user roles:
- **USER (Default)**: Can only view books, publishers and authors.
- **ADMIN**: Can add, modify, and delete books, authors, and publishers.

**Authentication & Session Management:**
- User registration defaults to the **USER** role.
- **Spring Security** manages authentication.
- Users are redirected based on their roles after login.

## Current Issues and To-Do List
### ✅ Functional Features
- User authentication and session management.
- Admin permissions to manage library data.
- Book, Author, Publisher, and Image handling.

### ❌ Known Issues
1. **User Image Not Displaying:** Uploaded images are not correctly rendered.
2. **Admin Role Handling:** After registering as an admin, the system redirects to a normal user view instead of keeping admin privileges 

(Configurar vistas y controladores con roles:
   En los controladores (@Controller), restringes el acceso con @PreAuthorize("hasRole('ADMIN')") o en WebSecurity con .antMatchers("/admin/**").hasRole("ADMIN").
   Usar Thymeleaf para mostrar u ocultar elementos según el rol (sec:authorize="hasRole('ADMIN')").

   Panel de administración dedicado:
   Tener una URL exclusiva como /admin/dashboard donde los administradores gestionan libros, autores, etc.
   Redirigir a los usuarios normales a /home y a los administradores a /admin/dashboard tras iniciar sesión. Esto se puede hacer con un SuccessHandler personalizado en Spring Security.

   Persistencia del rol en la sesión:
   Actualmente, al registrarse como ADMIN, parece que el rol se pierde al navegar. Esto se soluciona asegurando que el rol se almacene correctamente en la sesión (HttpSession) y se consulte en cada request).
3. **Error Handling:** Currently, error messages are poorly displayed. Need proper alerts and validations.
4. **Navigation Issues:** Missing "Go Back" buttons on many pages.

### 🚀 Future Enhancements
- Implement **proper error alerts** instead of raw error messages.
- Improve **session management** to ensure Admin access remains persistent.
- **Dockerize** the application and deploy it online.
- **Use Kubernetes** for scaling and managing microservices.
- Transition from **monolithic to microservices architecture** for better modularity and scalability.

## Deployment Plan
- **Containerize the app** using **Docker**.
- Use **Kubernetes** for orchestration and scaling.
- Deploy on a **cloud platform** (AWS, GCP, or Azure) with a **MySQL database instance**.

## How to Run Locally
1. Clone the repository:
   ```sh
   git clone https://github.com/your-repo/library-management.git
   cd library-management
   ```
2. Set up the database (MySQL):
   ```sql
   CREATE DATABASE library2;
   ```
3. Configure `application.properties`:
   ```properties
   spring.datasource.url=jdbc:mysql://localhost:3306/library2
   spring.datasource.username=root
   spring.datasource.password=yourpassword
   ```
4. Run the application:
   ```sh
   mvn spring-boot:run
   ```
5. Open the browser and go to:
   ```
   http://localhost:8080/
   ```

## License
This project is licensed under the MIT License.
