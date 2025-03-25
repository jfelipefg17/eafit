/*library2 querys*/

INSERT INTO roles (name) VALUES ('ADMIN'), ('USER');

INSERT INTO users (name, email, password) 
VALUES ('admin', 'admin@email.com', '1234567890'); -- Contraseña: admin123 (encriptada con BCrypt)

INSERT INTO user_roles (user_id, role_id) VALUES (1, 1); -- Asignar ADMIN al usuario 1

DESC users;
SELECT * FROM USERS;
SELECT email, password FROM users;
SELECT * FROM users WHERE email = 'mafe@gmail.com';


ALTER TABLE users 
MODIFY email VARCHAR(255) NOT NULL, 
MODIFY name VARCHAR(255) NOT NULL, 
MODIFY password VARCHAR(255) NOT NULL, 
MODIFY role VARCHAR(255) NOT NULL;

SELECT * FROM roles;


ALTER TABLE users MODIFY id INT AUTO_INCREMENT PRIMARY KEY;


INSERT INTO users (email, name, password) VALUES ('test@example.com', 'Test User', 'password123');


ALTER TABLE users DROP PRIMARY KEY;
ALTER TABLE users MODIFY id INT AUTO_INCREMENT PRIMARY KEY;


-- Mostrar todos los autores
SELECT * FROM products;

-- Mostrar un autor por ID
SELECT * FROM author WHERE id = 'ID_DEL_AUTOR';

-- Contar cuántos autores hay
SELECT COUNT(*) FROM author;

-- Buscar autores por nombre (ejemplo: nombres que contienen "John")
SELECT * FROM author WHERE name LIKE '%John%';

-------------------------------------------------------------

-- Mostrar todos los libros
SELECT * FROM book;

-- Mostrar un libro por ISBN
SELECT * FROM book WHERE isbn = 123456789;

-- Mostrar libros de un autor específico
SELECT * FROM book WHERE author_id = 'ID_DEL_AUTOR';

-- Mostrar libros de una editorial específica
SELECT * FROM book WHERE publisher_id = 'ID_DEL_EDITORIAL';

-- Buscar libros por título
SELECT * FROM book WHERE tittle LIKE '%Harry Potter%';

-- Contar cuántos libros hay en total
SELECT COUNT(*) FROM book;

-- Mostrar libros ordenados por fecha de entrada (más recientes primero)
SELECT * FROM book ORDER BY entryDate DESC;

----------------------------------------------------------------

-- Mostrar todas las imágenes
SELECT * FROM image;

-- Mostrar una imagen específica por ID
SELECT * FROM image WHERE id = 'ID_DE_LA_IMAGEN';

-- Mostrar todas las imágenes de un tipo específico (ejemplo: PNG)
SELECT * FROM image WHERE mime = 'image/png';

-- Contar cuántas imágenes hay
SELECT COUNT(*) FROM image;

---------------------------------------------------------------

-- Mostrar todas las editoriales
SELECT * FROM publisher;

-- Mostrar una editorial por ID
SELECT * FROM publisher WHERE id = 'ID_DE_LA_EDITORIAL';

-- Buscar editoriales por nombre
SELECT * FROM publisher WHERE name LIKE '%Penguin%';

-- Contar cuántas editoriales hay
SELECT COUNT(*) FROM publisher;

--------------------------------------------------------------
INSERT INTO products (name, price) VALUES 
('MacBook Pro', 3000),
('iPad', 1000),
('iPhone', 1200),
('Apple Watch', 500);


-- Mostrar todos los usuarios
SELECT * FROM user;
-- Mostrar un usuario por ID
SELECT * FROM user WHERE id = 'ID_DEL_USUARIO';

-- Buscar usuarios por nombre
SELECT * FROM user WHERE name LIKE '%Carlos%';

-- Buscar un usuario por email
SELECT * FROM user WHERE email = 'correo@example.com';

-- Contar cuántos usuarios hay en total
SELECT COUNT(*) FROM user;

-- Mostrar usuarios con un rol específico (ejemplo: ADMIN)
SELECT * FROM user WHERE role = 'ADMIN';

-- Mostrar usuarios con imagen asociada
SELECT * FROM user WHERE image_id IS NOT NULL;

-- importante cambiar tipo de usuario a ADMIN 
UPDATE user SET role = 'ADMIN' WHERE id = '7fd6af46-abee-4382-b122-f71a37d313fc';


INSERT INTO comments (description, product_id) VALUES ('Buen producto', 1);
INSERT INTO comments (description, product_id) VALUES ('Mejor de lo esperado', 1);
INSERT INTO comments (description, product_id) VALUES ('Excelente calidad', 2);
INSERT INTO comments (description, product_id) VALUES ('Mala calidad', 2);
SELECT * FROM comments WHERE product_id = 1;

